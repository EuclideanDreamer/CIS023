/*
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Program name    :  infixToPostFix.h                                               * 
'*                                                                     * 
'* Written by      : Bailey Nichols                                     * 
'*                                                                     * 
'* Purpose         :   The purpose of this program is to                             * 
'*                                                                     * 
'*                                                                     * 
'* Structure       : BEGIN                                             * 
'*                        while not at the end of the data             *
'*                            1 init the stack     
                              2 process the expression
                              3 output result
                              4 get next expression                    *
'*                   STOP                                              * 
'*                        End of Program                               * 
'*                                                                     * 
'*---------------------------------------------------------------------* 
'* Change Log:                                                         * 
'*                         Revision                                    * 
'*       Date    Changed  Rel Ver Mod Purpose                          * 
'* 11/08/12      Nichols 000.000.000 Initial release of program       * 
'*                                                                     * 
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
#include "myStack.h"
#include <iostream>
#include <fstream>
#include <string>
class infixToPostFix{
    private:
        stack<char> Stack;
        std::string expression;
        std::string postFix;
        public:
            infixToPostFix();
            void getInFix(std::string&);
            void processExpression();
            void showPostFix();
            void showInFix();
};
//constructor
infixToPostFix::infixToPostFix(){
    expression = "";
    postFix = "";
    Stack.clear();
}

//processes the expression
void infixToPostFix::processExpression(){
    char ch;
    while(expression.length() > 0){
        ch = expression.at(0);
        if(ch == '('){
            Stack.push(ch);
        }
        else if(ch == ')'){
            while(Stack.peek() != '('){
                postFix += Stack.peek();
                Stack.pop();
            }
            Stack.pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(Stack.peek() != '(' && Stack.peek() != '+' && Stack.peek() != '-' && Stack.peek() != '*' && Stack.peek() != '/'){
                postFix += Stack.peek();
                Stack.pop();
            }
            Stack.push(ch);
        }
        else{
            postFix += ch;
        }
        expression.erase(0,1);
    }
    while(Stack.peek() != '('){
        postFix += Stack.peek();
        Stack.pop();
    }
    Stack.pop();
}

//get the infix expression
void infixToPostFix::getInFix(std::string& inFix){
    expression = inFix;
}
//show the infix expression
void infixToPostFix::showInFix(){
    std::cout << "Infix: " << expression << std::endl;
}

//show the postfix expression
void infixToPostFix::showPostFix(){
    std::cout << "Postfix: " << postFix << std::endl;
}
