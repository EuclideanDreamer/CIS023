/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Program name    :  L3-4                                       * 
'*                                                                     * 
'* Written by      : Bailey Nichols                              * 
'*                                                                     * 
'* Purpose         :   Read a string, validate that string, convert it to 
'*                              'postfix notation and then output that string.      * 
'*                                                                     * 
'* Inputs          : Takes string input    * 
'*                                                                     * 
'* Outputs         : Displays sting to console on member call  * 
'*                                                                     * 
'* Calls           : All public members listed in uml can be called                * 
'*                                                                     *                   * 
'*---------------------------------------------------------------------* 
'* Change Log:                                                         * 
'*                         Revision                                    * 
'*       Date    Changed  Rel Ver Mod Purpose                          * 
'* 		12/10/21      Nichols 000.001.000  Known bugs fixed       * 
'*                                                               
'*'				UML 
*			_______infixToPostfix_______
'*			|+|void|infixToPostfix()
'*			|+|void|~infixToPostfix()
'*			|+|void|getInfix(string)
'*			|+|void|showPostfix
'*			|+|void|showInfix()
		-------------------------------
'*			|-|bool|isOperator(char)
'*			|-|bool|isOperand(char)
'*			|-|bool|isRightAssociative(char);
'*			|-|bool|precidenceOrder(char, char)
'*			|-|int |precedence(char);
'*			|-|void|translate(char);
'*			|-|bool|validate(string)
'*			|-|char|inFixstr
'*			|-|char|postFixstr
'*			|-|int |limit
'*'
'*      
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 
#pragma once
#include <iostream>
#include <string>
#include <stack>
constexpr int Maximum = 60;
class infixToPostfix
{
public:
	infixToPostfix();

	~infixToPostfix() {};

	void getInfix(std::string);

	void showInfix();

	void showPostfix();

private:
	bool isOperator(char);

	bool isOperand(char);

	bool isRightAssociative(char);

	bool precidenceOrder(char ch1, char ch2);

	int precedence(char);

	void translate();

	bool validate(std::string);

	char inFixStr[Maximum];
	std::string postFixstr;
	int limit;
};

