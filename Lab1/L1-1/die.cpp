#include "die.h"

die::die(){
    num=1;
}

void die::roll(){
    num=rand() % 6 +1;
}

int die::getNum() const{
    return num;
}