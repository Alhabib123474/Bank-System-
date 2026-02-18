#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Person
{
		protected:
		string name;
		int id;
		string password;
public:

	Person(string n, int i, string p) :name(n), id(i), password(p){}
	
	void setname(string n)
	{
		if (name.length() >= 5 && name.length() <= 20) {

			for(int i = 0; i < name.length(); i++)
			{
				char c = name[i];
				if (!((c>='a'&&c<='z')||(c>='A'&&c<='Z'))) {
					cout << "name must be characters only " << endl;
					return;
				}
			}
			name = n;
		}
		else {
			cout << "name must be between 5 and 20 characters" << endl;
		}
	}

	void setpassword(string p)
	{
		if (password.length() >= 8 && password.length() <= 20)
		{
			password = p;
		}
		else {
			cout << "password must be between 8 and 20 only " << endl;
		}
	}
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
	virtual void display()
	{
		cout << "name: " << name << endl;
		cout << "id: " << id << endl;
	}
};
