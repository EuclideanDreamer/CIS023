class invalidHr{

private:
    string message;
public:
    invalidHr(){
        message = "Invalid Entry, must be in this format!\n\t00:00:00XX  ex. 5:30 PM is 05:30:00PM  Hint: bad hour input";
    }
    invalidHr(string str){
        message = str;
    }
    string what(){
        return message;
    }

};