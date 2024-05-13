#include <iostream>
#include <string>

class Context {
public:
	void SetMessage(std::string str) { m_Message = str; }
	std::string const &Message() const { return m_Message; }

private:
  	std::string m_Message;
};

class Expression {
public:
	virtual bool Interpret(Context const &) = 0;
	virtual ~Expression() = default;
};

class TerminalExpression : public Expression {
public:
	TerminalExpression(std::string str): m_String(str) {}

	bool Interpret(Context const &context) override {
		return context.Message().find(m_String) == std::string::npos;
	}

private:
  	std::string m_String;
};

class AndExpression : public Expression {
public:
	AndExpression(Expression *p, Expression *q)
		: p_(std::move(p)), q_(std::move(q)) {}

	bool Interpret(const Context& context) override {
		return p_ -> Interpret(context) && q_ -> Interpret(context);
	}

private:
	Expression *p_;
	Expression *q_;
};

int main() {
	TerminalExpression a("sb");
	TerminalExpression b("fk");
	Expression *expression = new AndExpression(&a, &b);

	Context context;
	context.SetMessage("hello world");

	if(expression -> Interpret(context)) std::cout << context.Message();
	else std::cout << "sensitive words";

	delete expression;

	return 0;
}
