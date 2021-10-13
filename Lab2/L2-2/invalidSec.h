using namespace std;
#include <string>
class invalidSec{
private:
    string message;
public:
    invalidSec(){
        message = "Invalid Entry, must be in this format!\n\t00:00:00XX  ex. 5:30 PM is 05:30:00PM  Hint: bad second input";
    }
    invalidSec(string str){
        message = str;
    }
    string what(){
        return message;
    }
};