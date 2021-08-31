/*
/    Program Name: 
/    
/           Written By:
/
(############################################[ Programming Data ]######################################)
/
/               Purpose:
/                        
/                                          
/          User Inputs:
/
/        
/                Outputs:
/
/            
/                    Calls:
/
/              Structure:
/
(############################################[ Change Log ]######################################)
/
/    Date                 Name             Version              Purpose
/       |                         |                       |                         |
/  00/00/0000    Bailey Nichols         00.00            Initial Release
*/
#include <iostream>
#include <string>
using namespace std;
//
//------------------------------------------[Person Type]-----------------------------------//
//
class personType{
public:
void print() const;
//Function to output the first name and last name//in the form firstName lastName.
void setName(string first, string last);
//Function to set firstName and lastName according //to the parameters.//Postcondition: firstName = first; lastName = last
string getFirstName() const;//Function to return the first name.//Postcondition: The value of the data member firstName//               is returned.
string getLastName() const;//Function to return the last name.//Postcondition: The value of the data member lastName//               is returned.   
personType(string first = "", string last = "");//constructor//Sets firstName and lastName according to the parameters.//The default values of the parameters are empty strings.//Postcondition: firstName = first; lastName = last  
private:
    string firstName; //variable to store the first name
    string lastName;  //variable to store the last name};
};
void personType::print() const{    cout << firstName <<" "<< lastName;}
void personType::setName(string first, string last){    firstName =first;    lastName =last;}
string personType::getFirstName() const{return firstName;}
string personType::getLastName() const{return lastName;}
//constructor
personType::personType(string first, string last){    firstName =first;    lastName =last;}
//
//------------------------------------------[Doctor Type]-----------------------------------//
//
class doctorType:personType
{
private:
    /* data */
    string spl;
public:
    doctorType(string, string, string);
    void print()const;
    void setSpeciality(string);
    string getSpeciality();
};
//constructor
doctorType::doctorType(string first, string last, string spl){
    first=""; last=""; spl="";
}
void doctorType::print() const{
    cout << getFirstName() << " " << getLastName() << " MD of "<< spl <<endl;
}
void doctorType::setSpeciality(string specality){ spl = specality; }
string doctorType::getSpeciality(){ return spl;}
//
//------------------------------------------[Patient Type]-----------------------------------//
//
class patientType:personType{
private:
    string ID;
    int birthDay, birthMonth, birthYear;
    string drFirstName, drLastName, drSpl;
    int admissionDay, admissionMonth, admissionYear;
    int dischargeDay, dischargeMonth, dischargeYear;

public:
    void setInfo(string, string, string, 
                 int, int, int, 
                 string, string, string, 
                 int, int, int, int, int, int);
    void setID(string);
    string getID();
    void setBirthDate(int, int, int);
    int getBirthDay();
    int getBirthMonth();
    int getBirthYear();
    void setDoctorName(string, string);
    void setDoctorSpl(string);
    string getDoctorFName();
    string getDoctorLName();
    string getDoctorSpl();
    void setAdmDate(int, int, int);
    int getAdmDay();
    int getAdmMonth();
    int getAdmYear();
    void setDisDate(int, int, int);
    int getDisDay();
    int getDisMonth();
    int getDisYear();
};

void patientType::setInfo(string id, string fName, string lName, 
                 int bDay, int bMth, int bYear, 
                 string docFrName, string docLaName, string docSpl, 
                 int admDay, int admMonth, int admYear, int disChDay, 
                 int disChMth, int disChYear){
                     ID= id; setName(fName, lName); birthDay=bDay; birthMonth=bMth, birthYear=bYear;
                     drFirstName=docFrName; drLastName=docLaName; drSpl=docSpl;
                     dischargeDay=disChDay; dischargeMonth=disChMth; dischargeYear=disChYear;
                 }

void patientType::setID(string id){
    ID=id;
}
string patientType::getID(){
    return ID;
}
void patientType::setBirthDate(int bDay, int bMonth, int bYear){
    birthDay=bDay; birthMonth=bMonth; birthYear=bYear;
}
int patientType::getBirthDay(){
    return birthDay;
}
int patientType::getBirthMonth(){
    return birthMonth;
}
int patientType::getBirthYear(){
    return birthYear;
}
void patientType::setDoctorName(string first, string last){
    drFirstName=first; drLastName=last;
}
void patientType::setDoctorSpl(string occp){
    drSpl=occp;
}
string patientType::getDoctorFName(){
    return drFirstName;
}
string patientType::getDoctorLName(){
    return drLastName;
}
string patientType::getDoctorSpl(){
    return drSpl;
}
void patientType::setAdmDate(int day, int month, int year){
    admissionDay=day; admissionMonth=month; admissionYear=year;
}
int patientType::getAdmDay(){
    return admissionDay;
}
int patientType::getAdmMonth(){
    return admissionMonth;
}
int patientType::getAdmYear(){
    return admissionYear;
}
void patientType::setDisDate(int day, int month, int year){
    admissionDay=day; admissionMonth=month; admissionYear=year;
}
int patientType::getDisDay(){
    return dischargeDay;
}
int patientType::getDisMonth(){
    return dischargeMonth;
}
int patientType::getDisYear(){
    return dischargeYear;
}
//
//------------------------------------------[Patient Type]-----------------------------------//
//
class billType
{
private:
    string id;
    double phCharges;
    double rRent;
    double docFee;
public:
    billType();
    void printBill();
    void setInfo(string, double, double, double);
    void setID(string);
    string getID();
    void setPharmacyCharges(double);
    void updatePharmacyCharges(double);
    double getPharmacyCharges();
    void setRoomRent(double);
    double getRoomRent();
    void updateRoomRent(double);
    void setDoctorFee(double);
    double getDoctorFee();
    void updateDoctorFee(double);
    double billingAmount();
};
billType::billType(){
    id=""; phCharges=0.0; rRent=0.0; docFee=0.0; 
}
void billType::printBill(){
   cout <<"ID: "<<id<<" Pharmacy Charges: "<<phCharges<<" Room Rent: "<<rRent<<" Doctors Fees: "<<docFee<<endl;
}
void billType::setInfo(string Id, double charge, double rent, double fee){
    id=Id; phCharges=charge; rRent=rent; docFee=fee;    
}
void billType::setID(string Id){
    id=Id;
}
string billType::getID(){
    return id;
}
void billType::setPharmacyCharges(double charge){
    phCharges=charge;
}
void billType::updatePharmacyCharges(double charge){
    phCharges+=charge;
}
double billType::getPharmacyCharges(){
    return phCharges;
}
void billType::setRoomRent(double rent){
    rRent=rent;
}
double billType::getRoomRent(){
    return rRent;
}
void billType::updateRoomRent(double rent){
    rRent+=rent;
}
void billType::setDoctorFee(double fee){
    docFee=fee;
}
double billType::getDoctorFee(){
    return docFee;
}
void billType::updateDoctorFee(double fee){
    docFee+=fee;
}
double billType::billingAmount(){
    double total=0.0;
    total = docFee + phCharges + rRent;
    return total;
}