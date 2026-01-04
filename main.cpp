/*
~~~~~~~~~~~~~ Hospital Projecton ~~~~~~~~~~~~~
				  Submitters:
			  Nir Maman 322698747
			  Tal Ritz 315420422
*/


#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "hospital.h"
#include "department.h"
#include "worker.h"
#include "date.h"
#include "nurse.h"
#include "doctor.h"
#include "patient.h"

// main function headers
void AddDepartmentFunc(Hospital& h);
void RemoveDepartmentFunc(Hospital &h);



void main()
{
	char input1[20], input2[20];
	int select = 0;
	cout << "Welcome to the hospital administration system\n";
	cout << "Please enter hospital name: ";
	cin >> input1;
	cout << "\nPlease enter research center name: ";
	cin >> input2;
	Researchcenter rc(input2);
	Hospital h(input1, rc);
	do
	{
		cout << "\nPlease select an option by entering corresponding number:" <<
			"\n(1)\tAdd department" <<
			"\n(2)\tRemove department" <<
			"\n(3)\tAdd nurse" <<
			"\n(4)\tAdd doctor" <<
			"\n(5)\tInsert patient visit" <<
			"\n(6)\tAdd a researcher" <<
			"\n(7)\tAdd a research paper" <<
			"\n(8)\tShow department information (workers/patients)" <<
			"\n(9)\tShow all medical staff" <<
			"\n(10)\tSearch patient by ID" <<
			"\n(11)\tExit" <<
			"\nUser Input: ";
		cin >> select;
		switch (select)
		{
		case 1:
			AddDepartmentFunc(h);
			break;
		case 2:
			RemoveDepartmentFunc(h);
			break;
		case 3:
			//AddNurseFunc();
			break;
		case 4:
			//AddDoctorFunc();
			break;
		case 5:
			//InsertPatientVisitFunc();
			break;
		case 6:
			//AddResearcherFunc();
			break;
		case 7:
			//AddPaperFunc();
			break;
		case 8:
			//ShowDeparmentInfoFunc();
			break;
		case 9:
			//ShowMedicalStaffFunc();
			break;
		case 10:
			//SearchPatientIDFunc();
			break;
		case 11:
			break;
		default:
			cout << "\nInvalid input, try again\n";
			break;
		}
	} while (select != 11);
}

void AddDepartmentFunc(Hospital &h)
{
	char input[20];
	cout << "\nInsert department name: ";
	cin >> input;
	Department temp(input);
	if (h.addDepartment(temp) == true)
		cout << "\nDepartment " << input << " was added succesfully\n";
	else
		cout << "\nfailed to add department\n";
}

void RemoveDepartmentFunc(Hospital& h)
{
	char input[20];
	bool flag;
	cout << "\nInsert department name to remove: ";
	cin >> input;
	flag = h.removeDepartment(*h.getDepartmentByName(input));
	if (flag == true)
		cout << "\nDepartment " << input << " removed succesfully\n";
	else
		cout << "\nDepartment not found, departments unchanged\n";
}




	// hardcoded hospital benchmark
	/*
	Researchcenter researchCenter("Zubi");
	Hospital hospital("Sheeba",researchCenter);
	cout << "Hospital name is: " << hospital;
	cout << "\nHospital Reasearch Center is: " << hospital.getResearchCenterName();
	Department a("Emergency"), b("Kids"), c("Teeth"), d("Clincs");
	hospital.addDepartment(a);
	hospital.addDepartment(b);
	hospital.addDepartment(c);
	hospital.addDepartment(d);
	hospital.printDepartments();
	hospital.removeDepartment(b);
	hospital.printDepartments();
	Date date;
	Worker w1("Nir", 1000 , date , Person::MALE, &b);
	Nurse n1("Liora", 1001, date, Person::FEMALE, &b, 3);
	Nurse n2("Mike", 1002, date, Person::MALE, &b, 5);
	Nurse n3("Abi", 1003, date, Person::OTHER, &b);
	Doctor d1("zubi",10005,date,"heart",Person::MALE,&a);
	Patient p1("dubi",10007,date,Person::OTHER,"heart stroke",date,&a,&d1);
	hospital.printWorkersInDepartment(b);
	hospital.printWorkersInDepartment(a);
	b.removeWorker(&n2);
	hospital.printWorkersInDepartment(b);
	*/

// common functions (for now)
/*
void printDepartments(Hospital &hospital)
{
	cout << "\nHospital departments are : \n";
	for (int i = 0; i < hospital.getDepartmentsCount(); i++)
		cout << "(" << i << ") " << hospital.getDepartmentName(i) << "\n";
}

void printWorkersInDepartment(Department& department)
{
	cout << "\nDepartment " << department << " workers are : \n";
	if (department.getWorkersAmount() == 0)
		cout << "There are no workers in this department\n";
	else
	{
		for (int i = 0; i < department.getWorkersAmount(); i++)
			cout << "(" << i << ") " << department.getWorkerByIndex(i) << "\n\n";
	}
	//add for patients
	
} */