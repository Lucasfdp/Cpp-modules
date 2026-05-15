#pragma once

#include <string>
#include <stack>

class RPN
{
public:
	RPN();
	~RPN();

	double evaluate(const std::string& expression) const;

private:
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

	bool isOperator(char c) const;
	double applyOperator(char op, double a, double b) const;
};