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


	void setBalanceRaw(double b)
	{
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
	while (amount <= 0) {
		cout << "Invalid deposit amount. Try again." << endl;
		amount = Validation::getDoubleNumbers("Enter amount: ");
	}
	balance += amount;
	cout << "Amount deposited successfully" << endl;
}



void withdraw(double amount)
{
	while (amount <= 0 || amount > balance) {
		cout << "Invalid withdraw amount. Try again." << endl;
		amount = Validation::getDoubleNumbers("Enter amount: ");
	}
	balance -= amount;
	cout << "Amount withdrawn successfully" << endl;
}





void transfer(Client& recipient, double amount)
{
	while (amount <= 0 || amount > balance) {
		cout << "Invalid transfer amount. Try again." << endl;
		amount = Validation::getDoubleNumbers("Enter amount: ");
	}
	balance -= amount;
	recipient.deposit(amount);
	cout << "Amount transferred successfully" << endl;
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


