#include "clockChecker.h"

int main(){
    cout<<"Bailey Nichols\tL2-2\tL2-2.exe"<<endl;
    clockChecker check;
    string str;
    cout << "Please enter the time in 00::00::00 XX format: ";
    cin >> str;
    if(check.setter(str)){
    check.transform();
    cout << "Thanks the time is: ";
    check.printTime();
    cout <<endl;
    }
    else{
        cout<<"Sorry try again"<<endl;
    }
    return 0;
}   