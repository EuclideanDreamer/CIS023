#include <iostream>
using namespace std;


class clockType
{
private:
    int hr; int min; int sec;
public:
    void setTime(int hours, int minuties, int seconds);
    void printTime() const;

    bool operator == (const clockType& otherClock)const;

    clockType(int=0, int=0, int=0);
    ~clockType();
};

void clockType::setTime(int hours, int minuties, int seconds){
    hr=hours; min = minuties; sec= seconds;
}

void clockType::printTime()const{
    cout << hr << ":" << min << ":" << sec;
}

bool clockType::operator==(const clockType& otherClock)const{
    return (hr== otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

