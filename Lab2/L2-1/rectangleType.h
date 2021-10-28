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

