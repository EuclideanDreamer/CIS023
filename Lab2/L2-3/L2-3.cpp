#include "L2-3.h"
int main(){
    try{
        int x=0;
        int y=0;
        string errStr{"failed input, stream in fail state"};
        cout << "Bailey Nichols\tL2-3\tL2-3.exe"<<endl; //i have no idea how you compile my code 
                                                                                     //note i run ''./Testprogram'' on the console 
        cout << "Please enter a positive intiger to be used as M\n//>>:: ";
        cin >> x;
        cout << "Please enter a positive intiger to be used as N\n//>>:: ";
        cin >> y;
            //
        if (!cin){
            throw errStr;
        }
        else if(x<=0||x>5){
            throw x;
        }
        else if(y<=0||y>5){
            throw y;
        }
            //
        ackTest test; //using object from header file 
        x=test.runAckermann(x,y);
            //
        cout<< "It returned the value: "<< test.getI() << endl;   
    }
    catch(int n){
        cout << "Failed input "<< n <<" is too large or small"<<endl;
    }
    catch(string s){
        cout << s <<endl;
    }
    //code told to insert just before 'return 0'
    char q;
    std::cout << "\nPress any key to Exit.";
    std::cin.ignore(2, '\n');
    std::cin.get(q);
    return 0;
}
