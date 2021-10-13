#include <iostream>
#include <string>
#include "L1-2.h"

using namespace std;

int main()
{
    std::cout << “Bailey Nichols\t“ << “L 1-2\t“ << “L1-2.exe“ << std::endl;
    patientType newPatient;
    newPatient.setInfo("1000", "bob", "sob", 14, 04, 1996, 
                        "Lenord", "McCoy", "Eng", 12,
                        10, 1999, 04, 10, 1877);
    newPatient.setID("1234");
    
	string x = newPatient.getID();
    
    int a;
	newPatient.setBirthDate(12, 12, 1977);
	a=newPatient.getBirthDay();
    a=newPatient.getBirthMonth();
    a=newPatient.getBirthYear();

    newPatient.setDoctorName("Lenoard", "McCoy");
    newPatient.setDoctorSpl("Eng");
    x=newPatient.getDoctorFName();
    x=newPatient.getDoctorLName();

    x=newPatient.getDoctorSpl();

    newPatient.setAdmDate( 2, 17, 2019);
    a=newPatient.getAdmDay();
    a=newPatient.getAdmMonth();
    a=newPatient.getAdmYear();

    newPatient.setDisDate(2, 19, 2019);
    a=newPatient.getDisDay();
    a=newPatient.getDisMonth();
    a=newPatient.getDisYear();

    patientType y();

	billType newBill;
    newBill.setInfo("1000", 200.0, 500.0, 25.0);

    newBill.setID("1234");
    x=newBill.getID();

    newBill.setPharmacyCharges(22.33);
    double b=newBill.getPharmacyCharges();
    newBill.updatePharmacyCharges(55.55);

    newBill.setRoomRent(500.00);
    b=newBill.getRoomRent();
    newBill.updateRoomRent(500.00);

    newBill.setDoctorFee(2500.00);
    b=newBill.getDoctorFee();
    newBill.updateDoctorFee(799.00);

    b= newBill.billingAmount();
    
    newBill.printBill();
    system("read");
	//system("pause");
    
    return 0;
}
