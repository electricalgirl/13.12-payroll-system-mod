// 13.12 SalariedEmployee.h
// Description: Problem 2 of 2 due week 6
// Programmer: Parker Esmay
// Date: 03/02/2015

#ifndef SALARIED_H
#define SALARIED_H

#include "Employee.h"

class SalariedEmployee : public Employee
{
	public:
		SalariedEmployee( const string &, const string &, const string &, int, int, int, double = 0.0 );

		void setWeeklySalary( double ); // set weekly salary
		double getWeeklySalary() const; // return weekly salary

		// keyword virtual signals intent to override
		virtual double earnings() const; // calculate earnings
		virtual void print() const; // print SalariedEmployee object

	private:
		double weeklySalary; // salary per week
};

#endif 

