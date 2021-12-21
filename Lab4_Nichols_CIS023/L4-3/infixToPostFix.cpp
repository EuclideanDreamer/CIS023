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
#include "infixToPostFix.h"

infixToPostfix::infixToPostfix() {
	for (int i = 0; i < Maximum; i++) {
		inFixStr[i] = NULL;
	}
	postFixstr = "";
	limit = 0;
    std::cout << "Bailey Nichols\tL4-2\tL4-2.exe"<<std::endl;
}

void infixToPostfix::getInfix(std::string str) {
	if (validate(str)) {
		int n = str.length();
		limit = n;//assign member to hold n outside of function

		for (int i = 0; i < limit; i++) {
			inFixStr[i] = str[i];
		}//
	}
}

bool infixToPostfix::validate(std::string str) {
	int n = str.length();
	for (int i = 0; i < n; i++) {
		switch (str[i])
		{
		case ' ':
			std::cout << "Validation Error: Must be no spaces in the string!" << std::endl;
			return false;
			break;

		case ':':
			std::cout << "Validation Error: Use Semicolon!" << std::endl;
			return false;
			break;
		case '.':
			std::cout << "Validation Error: Bad Symbol" << std::endl;
			return false;
			break;
		default:
			break;
		}
		if (str[i] > '{') {
			std::cout << "Validation Error: Bad Symbol" << std::endl;
			return false;
		}

		if ((str[i] > '<') && (str[i] < 'A')) {
			std::cout << "Validation Error: BBBad Symbol" << std::endl;
			return false;
		}
	}
	return true;
}

void infixToPostfix::showInfix() {
	for (int i = 0; i < limit; i++) {
		std::cout << inFixStr[i];
	}
	std::cout << std::endl;
}

int infixToPostfix::precedence(char c) {
	int n = 0;
	if (c == '^') {
		n=3;
	}
	else if (c == '*' || c == '/') {
		n= 2;
	}
	else if (c == '+' || c == '-') {
		n= 1;
	}
	else {
		std::cout << "precidence fail"<<std::endl;
		n= 0;
	}
	return n;
}

bool infixToPostfix::isRightAssociative(char c) {
	if (c == '^') {
		return true;
	}
	else {
		return false;
	}
}

bool infixToPostfix::precidenceOrder(char ch1, char ch2) {
	if (ch1 == ch2) {
		if (isRightAssociative(ch1)) {
			return false;
		}
		else {
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool infixToPostfix::isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	else {
		return false;
	}
}

bool infixToPostfix::isOperand(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return true;
	}
	else{
		return false;
	}
}

void infixToPostfix::translate() {
	//copy char array to string
	postFixstr = std::string(inFixStr);
	//stack and and empty string for transfer
	//std::cout << postFixstr;
	std::stack<char> st;
	std::string temp;

	for (int i = 0; i < limit; i++) {
		if (isOperator(postFixstr[i])) {
			while (!st.empty() && st.top() != '(' && precidenceOrder(st.top(), postFixstr[i])) {
				temp.push_back(st.top());
				st.pop();
			}
			st.push(postFixstr[i]);
		}
		else if(isOperand(postFixstr[i])){
			temp.push_back(postFixstr[i]);
		}
		else if(postFixstr[i] == '(') {
			st.push(postFixstr[i]);
		}
		else if (postFixstr[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				temp.push_back(st.top());
				st.pop();
			}
		}
	}
	while (!st.empty()) {
		temp.push_back(st.top());
		st.pop();
	}
	
	postFixstr = temp;
}

void infixToPostfix::showPostfix() {
	translate();
	std::cout << postFixstr<< ";";
}
