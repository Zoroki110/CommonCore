#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
	public :
		RPN();
		~RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);

		int calculate(const std::string& expression);
	private :
		std::stack<int> _stack;

		bool isOperator(char c) const;
		int applyOperator(char op, int left, int right) const;
};

#endif