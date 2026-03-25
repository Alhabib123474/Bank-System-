#pragma once
#include"Person.h"


class Client : public Person {
private:
	double balance;
public:

//========default const=====//
	Client():Person(){
		balance = 0;
}



	Client(int i, string n, string p, double b) :Person(i, n, p) {
	setBalance(b);
	}



//======setters====//

	void setBalance(double b)
	{
		if (Validation::validate_bal(b))
            balance = b;
	}


//=======getters=====//




	double getBalance()
	{
		return balance;
	}



//=========methods===========//

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

	void transfer(Client& recipient, double amount)
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
		cout << "Client details: " << endl;
		Person::display();
		cout << "balance: " << balance << endl;

	}


};
static vector <Client> allClients;
static vector<Client>::iterator cIt;


