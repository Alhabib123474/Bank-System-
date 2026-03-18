#pragma once
#include <string>
#include"Employee.h"



class Admin : public Employee {

private:
	double salary;

public:

    Admin():Employee(){
        salary = 0;

    }

	Admin(int i,string n, string p, double s) :Employee(i, n, p, s) {

	}




	void display()override
	{
		cout << "Admin details: " << endl;
		Person::display();
		cout << "salary: " << salary << endl;
	}

};

static vector<Admin> allAdmins;
