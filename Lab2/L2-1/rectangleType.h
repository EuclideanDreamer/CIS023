#include "L2-1.h"
class rectangleType
{
private:
    /* length and width of rectangle */
    double width; double length;
public:
    //setters 
    void setDimension(double l, double w);

    //getters
    double getLength() const{return length;}
    double getWidth() const{return width;}
    
    // member to return area
    double area() const{return length * width;}

    // member to return parameter
    double parameter() const{return (2*length) + (2* width);}

    //member to print leng and width
    void print()const;

    // when you say myRectangle + yourRectangle 
    // the compiler does 
    // myRectangle.operator+(yourRectangle);
    //eazy peazy

    //overloaded operators 
    rectangleType operator + (const rectangleType &) const;    
    rectangleType operator - (const rectangleType &) const;    
    rectangleType operator * (const rectangleType&) const;    
    rectangleType operator ++ ();       
    rectangleType operator ++ (int);    
    rectangleType operator -- ();
    rectangleType operator -- (int);
    bool operator == (const rectangleType&) const;
    bool operator != (const rectangleType&) const;
    bool operator <= (const rectangleType&) const;
    bool operator < (const rectangleType&) const;
    bool operator >= (const rectangleType&) const;
    bool operator > (const rectangleType&) const;    

    //default constructor with init
    rectangleType(){length=0.0;width=0.0;}
    //assignment constructor defined below
    rectangleType(double, double);
    //destructor
    ~rectangleType();
};

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
