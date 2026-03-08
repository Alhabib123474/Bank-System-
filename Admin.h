#pragma once
#include <string>
#include"Employee.h"



class Admin : public Person {

private:
	double salary;

public:

    Admin():Person(){
        salary = 0;

    }

	Admin(int i,string n, string p, double s) :Person(i, n, p), salary(s) {}

	//======setters======//

	void setid(int i){
	    this->id = i;

	}


	void setname(string n){
	    this->name = n;

	}


	void setpass(string p){
	    this->password = p;
	}


	bool setsalary(double salary) {
		if (salary >= 5000) {
			this->salary = salary;
			return true;
		}
		return false;
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
