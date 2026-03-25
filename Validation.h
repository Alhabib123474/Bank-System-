#pragma once
#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Validation
{
public:
	static bool validate_name(string n)
	{
		if (n.length() >= 3 && n.length() <= 20) {

			for (int i = 0; i < n.length(); i++)
			{
				char c = n[i];
				if (!(tolower(c) >= 'a' && tolower(c) <= 'z')) {
					cout << "name must be characters only " << endl;
					return false;
				}
			}
			return true;
		}
		else {
			cout << "name must be between 5 and 20 characters" << endl;
			return false;
		}
	}

	static bool validate_pass(string p)
	{
		if (p.length() >= 8 && p.length() <= 20)
		{

			for (int i = 0; i < p.size(); i++) {
				if (p[i] == ' ') {
					cout << "Password must be without spaces!" << endl;
					return false;
				}

			}

			return true;
		}
		else {
			cout << "password must be between 8 and 20 only " << endl;
			return false;
		}
	}


	static bool validate_bal(double b)
	{
		if (b >= 1500) {
			return true;
		}
		else {
			cout << "Balance must be at least 1500." << endl;
			return false;
		}
	}

	static bool validate_sal(double s) {
		if (s >= 5000) {

			return true;
		}
		cout << "Salary must be at least 5000." << endl;
		return false;
	}


//===================================================================================//

	static double getDoubleNumbers(string msg){
	    double value;

	    while(true){
                cout<< msg <<endl;
                cin>> value;

	    }

            if(cin.fail()){
                cout<< "Invalid Input please enter valid number : "<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            }

            else{
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }





	}

	static int getIntegerNumbers(string msg){
	    int value;

	    while(true){
                cout<< msg <<endl;
                cin>> value;

	    }

            if(cin.fail()){
                cout<< "Invalid Input please enter valid number : "<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            }

            else{
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }





	}

//===================================================================================//


static string EnterName(string msg){
    string name;
    do{
       cout<<msg<<endl;
       getline(cin,name);
    }
    while(!validate_name(name));
    return name;
}


static string EnterPassword(string msg){
    string pass;
       do{
       cout<<msg<<endl;
       getline(cin,pass);
    }
    while(!validate_pass(pass));
    return pass;
}


static double EnterBalance(string msg){
    double balance;
        do{
       cout<<msg<<endl;
       cin>>balance;
    }
    while(!validate_bal(balance));
    return balance;
}


static double EnterSalary(string msg){
    double sal;
        do{
       cout<<msg<<endl;
       cin>>sal;
    }
    while(!validate_sal(sal));
    return sal;
}
};

