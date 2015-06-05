// 13.12 SalariedEmployee.cpp
// Description: Problem 2 of 2 due week 6
// Programmer: Parker Esmay
// Date: 03/02/2015

#include <iostream>
#include <stdexcept>

#include "SalariedEmployee.h" 

// constructor
SalariedEmployee::SalariedEmployee(const string &first, const string &last, const string &ssn, int month, int day, int year,
	double salary): Employee(first, last, ssn, month, day, year)
{
	setWeeklySalary(salary);
} 

// set salary
void SalariedEmployee::setWeeklySalary(double salary)
{
	if (salary >= 0.0)
		weeklySalary = salary;
	else
		throw invalid_argument("Weekly salary must be >= 0.0");
} 

// return salary
double SalariedEmployee::getWeeklySalary() const
{
	return weeklySalary;
} 

// calculate earnings;
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const
{
	return getWeeklySalary();
} 

// print SalariedEmployee's information
void SalariedEmployee::print() const
{
	cout << "salaried employee: ";	
	Employee::print(); // reuse abstract base-class print function
	cout << "\nweekly salary: " << getWeeklySalary();
} 
