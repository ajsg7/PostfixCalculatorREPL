#include "REPL.h"
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

long int REPL::postfixCalculator(const std::string& expression) {
	std::stack<long int> S;
	int top, bottom;
	std::istringstream userinput(expression);
	std::string a_string;

	while (userinput >> a_string) {
		if (a_string.size() == 1 and
			(a_string.find_first_of("+-*/^") != std::string::npos)) {
			if (S.size() < 2) {
				throw std::invalid_argument("Error!");
			}
			bottom = S.top(); //first
			S.pop();
			top = S.top(); //last
			S.pop();
			if (a_string[0] == '+') {
				S.push(top + bottom);
			}
			else if (a_string[0] == '-') {
				S.push(top - bottom);
			}
			else if (a_string[0] == '*') {
				S.push(top * bottom);
			}
			else if (a_string[0] == '/') {
				if (bottom == 0) {
					throw std::invalid_argument("Denominator argument must be greater than zero");
				}
				S.push(top / bottom);
			}
		} //end of if
		else S.push(stoi(a_string));
	} //end of while
	return S.top();
}

void REPL::runProgram() {
	std::string expression;
	std::string stop = "quit";
	long int result;
	std::cout << "Enter an expression to add, subtract, divide, or multiply in postfix form, otherwise enter 'quit'"
		<< " to stop the program:" << std::endl;
	do {
		std::cout << "\n-->";
		std::getline(std::cin, expression);
		try {
			if (expression == stop) {
				return;
			}
			result = postfixCalculator(expression);
			std::cout << result << std::endl;
			
		}
		catch (std::exception& e) { std::cout << "Error Here"; continue; }
	} while (expression != stop);
}

