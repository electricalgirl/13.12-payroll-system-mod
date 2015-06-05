// 13.12 main.cpp
// Description: Problem 2 of 2 due week 6
// Programmer: Parker Esmay
// Date: 03/02/2015

// (Payroll System Modification) Modify the payroll system of Figs. 13.9 - 13.17 to include private data member birthDate in 
// class Employee. Use class Date from Figs. 11.6 - 11.7 to represent an employee's birthday. Assume that payroll is processed
// once per month. Create a vector of Employee references to stroe the various employee objects. In a loop, calculate the
// payroll for each Employee (polymorphically), and add a $100 bonus to the person's payroll amount if the current month
// is the month in which the Employee's birthday occurs.

#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <conio.h>

#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

// Test the added date class from figures 11.6-11.7 to represent an employee's birthday. Assume payroll is processed 
// once per month.

void virtualViaPointer(const Employee * const); // prototype
void virtualViaReference(const Employee &); //prototype
int determineMonth(); // prototype 

int main()
{
	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// create vector of base-class pointers
	vector < Employee * > employees(3);

	// initialize vector with Employees
	employees[0] = new SalariedEmployee("John", "Smith", "111-11-1111", 7, 10, 1957, 800);
	employees[1] = new CommissionEmployee("Sue", "Jones", "333-33-3333", 3, 8, 1971, 10000, .06); // brithday month so should get bonus
	employees[2] = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 9, 25, 1968, 5000, .04, 300);

	int month = determineMonth();
	
	cout << "Employees processed polymorphically using dynamic binding" << "\n\n";
	
	cout << "Virtual function calls made off base-class pointers: \n\n";
	
	// polymorphically process each element in vector employees
	for (size_t i = 0; i < employees.size(); ++i)
	{
		virtualViaPointer(employees[i]); // output employee information
		
		// get current employee's birthday
		Date birthday = employees[i]->getBirthDate();

		// if current month is employee's birthday month, add $100 bonus to payroll amount
		if (birthday.getMonth() == month)
			cout << "\nHappy Birthday!\nYou recieved an extra $100 bonus \nearned with bonus $"
			<< (employees[i]->earnings() + 100.0) << endl << endl;
		else
			cout << endl << endl;

	}
	
	cout << "Virtual function calls made off base-class references: \n\n";
	
	for (size_t i = 0; i < employees.size(); ++i)
	{
		virtualViaReference(*employees[i]); // output employee information

		// get current employee's birthday
		Date birthday = employees[i]->getBirthDate();

		// if current month is employee's birthday month, add $100 bonus to payroll amount
		if (birthday.getMonth() == month)
			cout << "\nHappy Birthday!\nYou recieved an extra $100 bonus \nearned with bonus $"
			<< (employees[i]->earnings() + 100.0) << endl << endl;
		else
			cout << endl << endl;

	}
	
	cout << endl;

	// release objects pointed to by vector’s elements
	for (size_t j = 0; j < employees.size(); ++j)
	{
		// output class name
		cout << "deleting object of " << typeid(*employees[j]).name() << endl;

		delete employees[j];
	}
	
	getch();

	return 0;
} 

// call Employee virtual functions print and earnings off a base-class pointer using dynamic binding
void virtualViaPointer(const Employee * const baseClassPtr)
{
	baseClassPtr->print();
	cout << "\nearned $" << baseClassPtr->earnings();
}

// call Employee virtual functions print and earnings off a base-class reference using dynamic binding
void virtualViaReference(const Employee &baseClassRef)
{
	baseClassRef.print();
	cout << "\nearned $" << baseClassRef.earnings();
}

// current month using ctime
int determineMonth()
{
	time_t currentTime;
	char monthString[3];
	time(&currentTime);
	strftime(monthString, 3, "%m", localtime(&currentTime));
	return atoi(monthString);
} 
