#include "REPL.h"
#include <iostream>

//REPL class has the following member functions: 
//long int postfixCalculator(const std::string&);
//void runProgram();

/*Function postfixCalculator takes a constant string by reference with the parameter expression to calculate as a string, 
then converts it to an integer.
*It also lets the user know when a division is attempting to divide by zero which is undefined, so it will throw an Error.
*Since the expressions must be entered in Postfix form, the function will throw an Error when an operator is called
on only one integer instead of two. 
*The function allows the user to Add, Multiply, Subtract, and Divide Only.
*/

/*Function runProgram does exactly what its name describes. It is responsible for initially prompting the 
user to enter their Postfix expression.
* The function also contains a do-while loop which runs if the user does not enter "quit."
* The function uses thwo strings, one initialized to quit the program by using a comparison to break the do-while loop.
* A temporary long integer varaible is declared to store the expression's calculated result.
* The function uses a try and catch blocks to display Errors when dividing by zero or stack errors occur.
* The design of the program allows it to run indefinitely until the user decides to enter quit.
* Postfix example: 2 3 + will print 5. Make sure there is a space between separate integers.
*/


using namespace std;
int main() {

	REPL myREPL;
	myREPL.runProgram();

}