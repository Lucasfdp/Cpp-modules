#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }

bool RPN::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

double RPN::applyOperator(char op, double a, double b) const
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("division by zero.");
			return a / b;
	}
	throw std::runtime_error("unknown operator.");
}

double RPN::evaluate(const std::string& expression) const
{
	std::stack<double> stack;
	std::istringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
		{
			if (stack.size() < 2)
				throw std::runtime_error("invalid expression.");

			double b = stack.top(); stack.pop();
			double a = stack.top(); stack.pop();

			stack.push(applyOperator(token[0], a, b));
		}
		else
		{
			// must be a single digit number per subject rules
			if (token.length() != 1 || !std::isdigit(token[0]))
				throw std::runtime_error("invalid token: " + token);

			stack.push(token[0] - '0');
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("invalid expression.");

	return stack.top();
}