#include "ExpressionCalculator.hpp"
#include <stdexcept>
#include <utility>
#include <cstdint>

namespace{
    static uint16_t const CHARACTERS_COUNT = 26;

    static char const AND = '^';
	static char const OR = 'v';
	static char const IMPL = '>'; //=>
	static char const IFF = '='; // <=>
	static char const XOR = '+';
	static char const NEG = '!';

	bool IsOperator(char ch) {
		return ch == AND || ch == OR || ch == IFF || ch == IMPL || ch == XOR || ch == NEG;
	}
}

class ExpressionCalculator::VariableState{

public:
    bool GetVariableValue(char const name) const{
        if(!IsValidCharacter(name)) throw std::invalid_argument("Variable name is invalid");
        return m_Variables[name - 'A'];
    }
    void SetVariableValue(char const name, bool const value){
        if(!IsValidCharacter(name)) throw std::invalid_argument("Variable name is invalid");
        m_Variables[name - 'A'] = value;
    }

public:
    static bool IsValidCharacter(char const ch){ return 'A' <= ch && ch <= 'Z'; }
    static VariableState DecodeFromNumber(uint32_t number, bool const variables[CHARACTERS_COUNT]){

        VariableState result;

        for(uint16_t i = 0; i < CHARACTERS_COUNT; i++)
            if(variables[i] && number >> i & 1)
                result.SetVariableValue('A' + i, true);

        return result;

    }

private:
    bool m_Variables[CHARACTERS_COUNT] = { false, };

};

class ExpressionCalculator::BooleanExpression{

public:
    virtual bool Evaluate(ExpressionCalculator::VariableState const &state) const = 0;
    virtual BooleanExpression *Clone() const = 0;
    virtual ~BooleanExpression() = default;

    bool m_Variables[CHARACTERS_COUNT] = { false, };
    uint16_t m_NumberOfVariables = 0;

};

class ExpressionCalculator::Variable : public ExpressionCalculator::BooleanExpression{

public:
    Variable(char const name){
        m_Name = name;
        m_Variables[name - 'A'] = true;
        m_NumberOfVariables = 1;
    }

    bool Evaluate(ExpressionCalculator::VariableState const &state) const override{ return state.GetVariableValue(m_Name); }
    ExpressionCalculator::BooleanExpression *Clone() const override{ return new Variable(*this); }

private:
    char m_Name;

};

class ExpressionCalculator::UnaryExpression : public ExpressionCalculator::BooleanExpression{

public:
    UnaryExpression(ExpressionCalculator::BooleanExpression *expression){

        m_Expression = expression;

        for(uint16_t i = 0; i < CHARACTERS_COUNT; ++i)
            m_Variables[i] = expression -> m_Variables[i];

        m_NumberOfVariables = expression -> m_NumberOfVariables;

    }

    ~UnaryExpression(){
        delete m_Expression;
    }

    bool Evaluate(ExpressionCalculator::VariableState const &state) const override{
        return !m_Expression -> Evaluate(state);
    }

    ExpressionCalculator::BooleanExpression *Clone() const override{ return new UnaryExpression(m_Expression -> Clone()); }

private:
    ExpressionCalculator::BooleanExpression *m_Expression = nullptr;

};

class ExpressionCalculator::BinaryExpression : public ExpressionCalculator::BooleanExpression{

public:
    BinaryExpression(char operand, ExpressionCalculator::BooleanExpression *left, ExpressionCalculator::BooleanExpression *right){

        m_Operand = operand;
        m_Left = left;
        m_Right = right;

        for(uint16_t i = 0; i < CHARACTERS_COUNT; i++){

            m_Variables[i] = left -> m_Variables[i] || right -> m_Variables[i];
            m_NumberOfVariables += m_Variables[i];

        }

    }

    ~BinaryExpression(){

        delete m_Left;
        delete m_Right;

    }

    bool Evaluate(ExpressionCalculator::VariableState const &state) const override{

        switch(m_Operand){

            case OR: return m_Left -> Evaluate(state) || m_Right -> Evaluate(state);
            case AND: return m_Left -> Evaluate(state) && m_Right -> Evaluate(state);
            case IMPL: return !m_Left -> Evaluate(state) || m_Right -> Evaluate(state);
            case IFF: return m_Left -> Evaluate(state) == m_Right -> Evaluate(state);
            case XOR: return m_Left -> Evaluate(state) != m_Right -> Evaluate(state);
            default: return false;

        }

    }

    ExpressionCalculator::BooleanExpression *Clone() const override{ return new BinaryExpression(m_Operand, m_Left -> Clone(), m_Right -> Clone()); }

private:
    ExpressionCalculator::BooleanExpression *m_Left = nullptr;
    ExpressionCalculator::BooleanExpression *m_Right = nullptr;
    char m_Operand;

};

bool ExpressionCalculator::CheckAllVariations(BooleanExpression const *expression, bool expectedValue){

    uint32_t variationsCount = 1 << expression -> m_NumberOfVariables;

	for(uint32_t i = 0; i < variationsCount; i++)
		if(expression -> Evaluate(VariableState::DecodeFromNumber(i, expression -> m_Variables)) != expectedValue) return false;

	return true;

}

ExpressionCalculator::BooleanExpression *ExpressionCalculator::ParseExpression(std::string const &expressionString){

    if(expressionString.length() == 0) return nullptr;
	if(expressionString.length() == 1) return new Variable(expressionString[0]);

	std::string strWithoutBrackets = expressionString.substr(1, expressionString.length() - 2);
	uint32_t length = strWithoutBrackets.length();
	uint32_t bracketsCounter = 0;

	for(uint32_t i = 0; i < length; i++){

        bracketsCounter += (strWithoutBrackets[i] == '(') - (strWithoutBrackets[i] == ')');

		if(IsOperator(strWithoutBrackets[i]) && bracketsCounter == 0){

			if(strWithoutBrackets[i] == NEG) return new UnaryExpression(ParseExpression(strWithoutBrackets.substr(i + 1, length - i - 1)));
			else return new BinaryExpression(
					strWithoutBrackets[i],
					ParseExpression(strWithoutBrackets.substr(0, i)),
					ParseExpression(strWithoutBrackets.substr(i + 1, length - i - 1))
                );

		}

	}

	return nullptr;

}

ExpressionCalculator::ExpressionCalculator(std::string const &expression){
    m_Expression = ParseExpression(expression);
}

ExpressionCalculator::ExpressionCalculator(ExpressionCalculator const &other){
    Copy(other);
}

ExpressionCalculator::ExpressionCalculator(ExpressionCalculator &&other){
    Move(std::move(other));
}

ExpressionCalculator::~ExpressionCalculator(){
    Free();
}

ExpressionCalculator &ExpressionCalculator::operator =(ExpressionCalculator const &other){

    if(this == &other) return *this;

    *this = ExpressionCalculator(other);

    return *this;

}

ExpressionCalculator &ExpressionCalculator::operator =(ExpressionCalculator &&other){

    if(this == &other) return *this;

    Free();
    Move(std::move(other));

    return *this;

}

bool ExpressionCalculator::IsTautology() const{ return CheckAllVariations(m_Expression, true); }
bool ExpressionCalculator::IsContradiction() const{ return CheckAllVariations(m_Expression, false); }

void ExpressionCalculator::Copy(ExpressionCalculator const &other){
    m_Expression = other.m_Expression -> Clone();
}

void ExpressionCalculator::Move(ExpressionCalculator &&other){
    m_Expression = std::exchange(other.m_Expression, nullptr);
}

void ExpressionCalculator::Free(){
    delete m_Expression;
}