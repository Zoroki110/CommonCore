#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& copy) { *this = copy; }
RPN& RPN::operator=(const RPN& copy) {
	if (this != &copy)
		_stack = copy._stack;
	return *this;
}

bool RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/'); //check si le char est un operateur
}

int RPN::applyOperator(char op, int left, int right) const { //fonction qui applique l'operateur sur les left and right
	switch (op) {
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/':
			if (right == 0) {
				std::cerr << "Error: Division by zero." << std::endl;
				exit(EXIT_FAILURE);
			}
			return left / right;
		default:
			std::cerr << "Error: Invalid operator." << std::endl;
			exit(EXIT_FAILURE);
	}
	return 0; 
}

int RPN::calculate(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) { //on lit le stream
		if (token.length() == 1 && isOperator(token[0])) { //si le token est un operateur
			if (_stack.size() < 2) { //on check au minimum 2 element dans la stack
				std::cerr << "Error: not enough operands" << std::endl;
				exit(EXIT_FAILURE);
			} //quand on a repere l'operateur on pop les 2 dernier element de la stack 
			int right = _stack.top(); _stack.pop(); //exemple 3 4 +, on repere l'operateur +, on top = 4 et on pop
			int left = _stack.top(); _stack.pop(); //donc right =4 puis on top = 3 et on pop
			int result = applyOperator(token[0], left, right); //token[0] = operateur
			_stack.push(result); //et on push le resultat pour mettre dans la stack et continue 
		} else { //si c'est un chiffre
			int value = atoi(token.c_str()); //on converti le token en int
			if (value < 0 || value > 9 || token.find_first_not_of("0123456789") != std::string::npos) { //check si bien compris en 0 et 9
				std::cerr << "Error: Invalid token => " << token << std::endl;
				exit(EXIT_FAILURE);
			}
			_stack.push(value); //on l'envoie sur la stack
		}
	}
	if (_stack.size() != 1) {
		std::cerr << "Error: Invalid expression." << std::endl;
		exit(EXIT_FAILURE);
	}
	return _stack.top(); 
}
