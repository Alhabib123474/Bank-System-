#pragma once

#include <vector>
#include"Validation.h"


class Person
{
protected:
		string name;
		int id;
		string password;
public:
//============default const=========///
	Person() {
		id = 0;
}

	Person(int i, string n,  string p){
	this-> id= i;
	setname(n);
	setpassword(p);


	}


//=====setters====//

    void setid(int i)
	{
	    this->id = i;

	}



	void setname(string n)
	{
	    if(Validation::validate_name(n)){
           this->name = n;
	    }
	}


	void setpassword(string p)
	{
		if (Validation::validate_pass(p))
		this->password = p;
	}


	//=========getters==========//
	int getid()
	{
		return id;
	}
	string getname()
	{
		return name;
	}
	string getpassword()
	{
		return password;
	}



//=======methods=====//


	virtual void display()
	{
		cout << "name: " << name << endl;
		cout << "id: " << id << endl;
	}
};
