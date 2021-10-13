#include "L2-2.h"
#include "invalidSec.h"
#include "invalidMin.h"
#include "invalidHr.h"
#include "invalidEntry.h"

class clockChecker
{
private:
    string tm;
public:
    clockChecker(){}
    ~clockChecker(){}
    //try set
    bool setter(string str);
    //transformer
    void transform();
    //getter
    void printTime();
};

bool clockChecker::setter(string str){
    try{
        //
/*     / str[length] =  0 - 0 - : - 0 - 0 - : - 0 - 0 - P - M  /
       /~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
       / array[len]  =  0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9  /

        map of array above explains why the random numbers contolling the 
        loops in the programming below 
*/
        int length = str.size();
        //make len size to avoid buffer overflow
        for (int i=0; i<length-2; i++){ ///check for invalid entry except for PM
            if((str[i]>=';')||(str[i]<='/')){ //if ascii value is < or > : and 0 
                throw invalidEntry();         // entry is invalid
            }
        }
        if ((str[length-1]=='p')||(str[length-1]=='P')){
            if(str[1]>'1'){ // if hr has a ten spot above 1 its invalid
                throw invalidHr();
            }
        }
        if(str[3]>'6'){
            throw invalidMin();
        }
        if(str[6]>'6'){
            throw invalidSec();
        }
        // 
        tm = str;
    }
    catch(invalidSec){
        return false;
    }
    //------------------------------------[Line For Readablity]---------------------//
    catch(invalidMin){
        return false;
    }
    //------------------------------------[Line For Readablity]---------------------//
    catch(invalidHr){
        return false;

    }
    //------------------------------------[Line For Readablity]---------------------//
    catch(invalidEntry){
        cout << "Invalid Entry, must be in this format!"<<endl;
        cout << "00:00:00XX  ex. 5:30 PM is 05:30:00PM" <<endl;
        cout << "Hint: (Fail) Did you enter a space before the time?"<<endl;
        return false;
    }
    return true;
}
void clockChecker::transform(){
    string temp = tm;
    if (temp[8]=='p'||temp[8]=='P'){
        
        int num;
        num= stoi(temp);

        num=num+12;

        string hr; 
        hr = to_string(num);

        for (int i =0; i<2;i++){
            temp[i]= hr[i];
        }



        tm=temp;
    }
}
void clockChecker::printTime(){
    for (int i=0; i<8;i++){
        cout <<tm[i];
    }
}
