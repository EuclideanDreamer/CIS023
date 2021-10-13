/*
    Program Name: L2-3 or Ackermann Test

    Author: Bailey Nichols

    Purpose: The purpose of this program is to answer a prompt from my professor, to demonstrate the use of 
        recursion in C++. The question or prompt is, "How many times has the Ackermann Function been 
        recursively called when m = 3 and n = 5" (see formula shown in in notes and below)

    
    Ackermann Function as defined by the handout 



        A(m, n) = { n+1= number                 if m=0}
                  { A(m-1, 1)= number           if n=0}
                  { A(m-1, A(n, n-1))        otherwise}
//Ackermann function definition as defined by prof David Brailsford
//https://www.youtube.com/watch?v=i7sm9dzFtEI&t=301s

    Recursive Counting Ackermann as defined by Stack Exchange user  Peter Košinár 
//https://math.stackexchange.com/questions/2511594/ackermann-function-how-to-calculate-the-number-of-times-it-calls-itself

        RA(m, n) = {1                                   for m=0        }
                   {1 + RA(m-1, 1)                      for m>0 and n=0}
                   {1 + RA(m, n-1) + RA(m-1,A(m,n-1))   for m>0 and n>0}

    Change Log
        01/05/2021      Bailey Nichols      1.0     Inital Release
*/     
#pragma once
#include <iostream>
#include <string>
using namespace std;
class ackTest
{
private:
    long long i;
public:
    ackTest(){i=0;};//init value to zero
    ~ackTest(){};
    //ackermann function
    int runAckermann(int, int);
    //fun from stack overflow
    int countAckermann(int, int);
    //get i
    long long getI(){return i;}
};
//function definitions

//function from handout as seen in notes
int ackTest::runAckermann(int m, int n){
    int ret;
    i++;
    if (m==0)
    {
        ret = n + 1;
    }
    else if (n==0)
    {
        ret = runAckermann(m-1, 1);
    }
    else
    {
        ret = runAckermann(m-1, runAckermann(m, n-1));
    }
    return ret;
}

//function from stack overflow 
int ackTest::countAckermann(int m, int n){
    int x;
    if (m==0)
    {
        x++;
    }
    if (m>0&&n==0){

        x=1+countAckermann(m-1, 1);
    }
    if (m>0&&n>0){
        x=1+countAckermann(m, n-1)+countAckermann(m-1, ackTest::runAckermann(m, n-1));

    }
    return x;
}
