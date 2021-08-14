/*
/   Program Name: Die or L1-1
/    
/     Written By: Bailey Nichols
/
(############################################[ Programming Data ]######################################)
/
/              Purpose: The purpose of the program is to show what numbers are produced from the rolling
                            of computerized dice.
/                        
/                                          
/          User Inputs: The user will input to the console the amount of dice to be used, the user will input the number of times to roll the dice.
/
/        
/               Outputs: The program will output all prompts and a graph showing the sums produced.
/
/            
/                 Calls:N/A
/
/              Structure:

                    int main(){

                        get number of dice

                        get number of rolls 

                        for numOfDice{
                            for numOfRolls{
                                do stuff
                            }
                        }
                        Print graph

                        that's all folks!
                    }
/
(############################################[ Change Log ]######################################)
/
/    Date              Name             Version              Purpose
/       |                |                 |                     |
/   08/14/2021    Bailey Nichols         00.00            Initial Release
*/
#pragma once 
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
class die {
private:
    int num; //value of the roll in this instance (1-6)
public:
    die();
    //default constuctor
    //init num to 1
    //---------------
    void roll();
    //Function to roll die
    //Function uses rand() genorator to get int 1-6 in private data member num
    //-------------------------
    int getNum() const;
    //function to retun top face of the die
    //returns "the value of the instance variable num"
};