#include <iostream>
// 13.12 BasePlusCommissionEmployee.cpp
// Description: Problem 2 of 2 due week 6
// Programmer: Parker Esmay
// Date: 03/02/2015

#include <stdexcept>

#include "BasePlusCommissionEmployee.h"

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee( const string &first, const string &last, const string &ssn,
	int month, int day, int year, double sales, double rate, double salary ) : 
	CommissionEmployee(first, last, ssn, month, day, year, sales, rate)
{
 setBaseSalary( salary ); // validate and store base salary
} 

 // set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary >= 0.0)
		baseSalary = salary;
	else
		throw invalid_argument("Salary must be >= 0.0");
} 

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
return baseSalary;
} 

// calculate earnings;
// override pure virtual function earnings in Employee
double BasePlusCommissionEmployee::earnings() const
{
return getBaseSalary() + CommissionEmployee::earnings();
} 

// print BasePlusCommissionEmployee's information
void BasePlusCommissionEmployee::print() const
{
	cout << "base-salaried ";
	CommissionEmployee::print(); // code reuse
	cout << "; base salary: " << getBaseSalary();
}
