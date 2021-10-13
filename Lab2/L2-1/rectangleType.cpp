#include <rectangleType.h>
rectangleType::rectangleType(double l, double w)
{ setDimension(l, w);
}

rectangleType::~rectangleType()
{
}

void rectangleType::setDimension(double l, double w){
	if(l>0 && w > 0){		
		length = l; width = w;
	}
	else{ length = 0.0; width = 0.0;}
}

void rectangleType::print()const{
	cout << "Length = "<< length << "Width = " <<  width;
}


    // when you say myRectangle + yourRectangle 
    // the compiler does 
    // myRectangle.operator+(yourRectangle);
    //eazy peazy

    //overloaded operators 

rectangleType rectangleType::operator+(const rectangleType& otherRect)const {
    rectangleType returnRect((this->length+otherRect.length), (this->width + otherRect.width));
    return returnRect;
}

rectangleType rectangleType::operator-(const rectangleType& otherRect)const {
    rectangleType returnRect((this->length - otherRect.length), (this->width - otherRect.width));
    return returnRect;
}

rectangleType rectangleType::operator*(const rectangleType& otherRect)const {
    rectangleType returnRect((this->length * otherRect.length), (this->width * otherRect.width));
    return returnRect;
}

rectangleType rectangleType::operator++(){
    rectangleType returnRect((this->length++), (this->width++));
    return returnRect;
}

rectangleType rectangleType::operator++(int i){
    rectangleType returnRect((this->length+ i), (this->width+ i));
    return returnRect;
}

rectangleType rectangleType::operator--(){
    rectangleType returnRect((this->length--), (this->width--));
    return returnRect;
}

rectangleType rectangleType::operator--(int i){
    rectangleType returnRect((this->length- i), (this->width- i));
    return returnRect;
}

bool rectangleType::operator == (const rectangleType& otherRect) const{
    if((this->length==otherRect.length)&&(this->width == otherRect.width)){
        return true;
    }
    else{return false;}
}

bool rectangleType::operator == (const rectangleType& otherRect) const{
    if((this->length==otherRect.length)&&(this->width == otherRect.width)){
        return false;
    }
    else{return true;}
}

bool rectangleType::operator <= (const rectangleType& otherRect) const{
    if(area() <= otherRect.area()){
        return true;
    }
    else {return false;}
}

bool rectangleType::operator < (const rectangleType& otherRect) const{
    if(area() < otherRect.area()){
        return true;
    }
    else {return false;}
}

bool rectangleType::operator >= (const rectangleType& otherRect) const{
    if(area() >= otherRect.area()){
        return true;
    }
    else {return false;}
}

bool rectangleType::operator > (const rectangleType& otherRect) const{
    if(area() > otherRect.area()){
        return true;
    }
    else {return false;}
}
