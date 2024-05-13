#ifndef __EXPRESSION_CALCULATOR_HPP_
#define __EXPRESSION_CALCULATOR_HPP_

#include <string>

class ExpressionCalculator{

public:
    ExpressionCalculator(std::string const &expression);
    ExpressionCalculator(ExpressionCalculator const &other);
    ExpressionCalculator(ExpressionCalculator &&other);
    ~ExpressionCalculator();

    ExpressionCalculator &operator =(ExpressionCalculator const &other);
    ExpressionCalculator &operator =(ExpressionCalculator &&other);

    bool IsTautology() const;
    bool IsContradiction() const;

private:
    void Copy(ExpressionCalculator const &other);
    void Move(ExpressionCalculator &&other);
    void Free();

private:
    class BooleanExpression;
    class Variable;
    class VariableState;
    class UnaryExpression;
    class BinaryExpression;

private:
    static bool CheckAllVariations(BooleanExpression const *expression, bool expectedValue);
    static BooleanExpression *ParseExpression(std::string const &expressionString);

private:
    BooleanExpression *m_Expression = nullptr;

};

#endif