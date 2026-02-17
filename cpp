#include<iostream>
#include<string>
#include<cmath>
using namespace std;    

class person
{
	protected:
		string name;
		int id;
		string password;
public:

	person(string n, int i, string p) :name(n), id(i), password(p){}
	
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


class Admin : public person
{
private:
	double salary;
public:
	Admin(string n, int i, string p, double s) :person(n, i, p), salary(s) {}

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
		person::display();
		cout << "salary: " << salary << endl;
	}

};
class Employee : public person {
private:
	double salary;

public:
	Employee(string n, int i, string p, double s) : person(n, i, p), salary(s) {}

	bool setSalary(double salary) {
		if (salary >= 5000) {
			this->salary = salary;
			return true;
		}
		return false;
	}

	double getSalary() {
		return salary;
	}

	void display()override {
		person::display();
		cout << "Salary: " << salary << endl;
	}
};
class client : public person {
private:
	double balance;
public:
	client(string n, int i, string p, double b) :person(n, i, p), balance(b) {}
	void setBalance(double b)
	{
		if (balance >= 1500) {
			balance = b;
		}
		else {
			cout << "balance must be greater than or equal to 1500" << endl;
		}
	}
	double getBalance()
	{
		return balance;
	}
	void deposit(double amount)
	{
		if (amount > 0) {
			balance += amount;
		}
		else {
			cout << "Deposit amount must be positive." << endl;
		}
	}
	void withdraw(double amount)
	{
		if (amount > 0 && amount <= balance) {
			balance -= amount;
		}
		else {
			cout << "Invalid withdrawal amount." << endl;
		}
	}
	void transfer(client& recipient, double amount)
	{
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			recipient.deposit(amount);
		}
		else {
			cout << "Invalid transfer " << endl;
		}
	}
	void checkBalance()
	{
		cout << " balance: " << balance << endl;
	}
	void display()override
	{
		person::display();
		cout << "balance: " << balance << endl;
		
	}
};


int main()
{




    return 0;
}