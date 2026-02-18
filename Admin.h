#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include"Person.h"
using namespace std;
class Admin : public Person
{
private:
	double salary;
public:
	Admin(string n, int i, string p, double s) :Person(n, i, p), salary(s) {}

	void setSalary(double s)
	{
		if (salary >= 5000) {
			salary = s;
		}
		else {
			cout << "salary must be greater than 5000" << endl;
		}
	}
	double getSalary()
	{
		return salary;
	}
	void display()override
	{
		cout << "Admin details: " << endl;
		Person::display();
		cout << "salary: " << salary << endl;
	}

};