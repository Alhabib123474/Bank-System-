#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include"Person.h"
using namespace std;

class Client : public Person {
private:
	double balance;
public:
	Client(string n, int i, string p, double b) :Person(n, i, p), balance(b) {}
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

 // ================= LOGIN =================
 static bool login_c(int client_id, string client_pass)
 {
     ifstream file("clients.txt");
     if (!file.is_open())
     {
         cout << "Cannot open clients file!" << endl;
         return false;
     }

     string line;

     while (getline(file, line))
     {
         if (line.empty())
             continue;

         stringstream ss(line);
         string id_str, name, pass, bal_str;

         getline(ss, id_str, ',');
         getline(ss, name, ',');
         getline(ss, pass, ',');
         getline(ss, bal_str, ',');

         if (id_str.empty())
             continue;

         if (stoi(id_str) == client_id && pass == client_pass)
         {
             cout << "Login successful. Welcome " << name << endl;
             file.close();
             return true;
         }
     }

     file.close();
     cout << "Invalid ID or Password." << endl;
     return false;
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
