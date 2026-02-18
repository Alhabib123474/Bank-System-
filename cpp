#include<iostream>
#include<string>
#include<cmath>
#include <fstream>
#include <sstream>
#include"Person.h"
#include"Admin.h"
#include"Employee.h"
#include"Client.h"
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

class Employee : public Person {
private:
	double salary;

public:
	Employee(string n, int i, string p, double s) : Person(n, i, p), salary(s) {}

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

	// ================= LOGIN =================
	static bool login_E(int employee_id, string employee_pass)
	{
		ifstream file("employees.txt");
		if (!file.is_open())
		{
			cout << "Cannot open employee file!" << endl;
			return false;
		}

		string line;

		while (getline(file, line))
		{

			if (line.empty())
				continue;

			stringstream ss(line);
			string id_str, name, pass, sal_str;

			getline(ss, id_str, ',');
			getline(ss, name, ',');
			getline(ss, pass, ',');
			getline(ss, sal_str, ',');

			if (id_str.empty())
				continue;

			
			if (stoi(id_str) == employee_id && pass == employee_pass)
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
// ================= search client =================
	bool search_client(int cl_id) {
		ifstream file("clients.txt", ios::in);
		bool found = false;

		if (!file.is_open()) {
			cout << "Error: Could not open file." << endl;
			return 1;
		}

		string line;
		while (getline(file, line)) {
			

			stringstream ss(line);
			string id_str, name, pass, bal_str;
			getline(ss, id_str, ',');
			getline(ss, name, ',');
			getline(ss, pass, ',');
			getline(ss, bal_str, ',');


			if (id_str.empty()) continue;

			if (stoi(id_str) == cl_id) {
				cout << "Client Found!" << endl;
				cout << "ID: " << id_str << endl;
				cout << "Name: " << name << endl;
				cout << "Password: " << pass << endl;
				cout << "Balance: " << bal_str << endl;
				found = true;
				break;
			}
		}
		

		if (!found)
			cout << "Client with ID " << cl_id << " not found." << endl;

		file.close();

		if (found == true) return true;
		else return false;

	}

// ================= List clients =================
	void list_clients(){
		ifstream file("clients.txt", ios::in);
	
		if (!file.is_open()) {
			cout << "Error: Could not open file." << endl;
			return;
		}

		cout << "===== Clients =====" << endl;

		string line;
		while (getline(file, line)) {


			stringstream ss(line);
			string id_str, name, pass, bal_str;
			getline(ss, id_str, ',');
			getline(ss, name, ',');
			getline(ss, pass, ',');
			getline(ss, bal_str, ',');

			if (id_str.empty()) continue;

			
			cout << "ID: " << id_str <<". Name: " << name <<". Password: " << pass << ". Balance: " << bal_str << "." << endl;
			cout << "-------------------" << endl;
		}

		file.close();
	}

// ================= Add clients =================

void add_client(int cl_id,string cl_name,string cl_pass,double cl_bal){


		//change on the cout needed.
		if (search_client(cl_id)) {}

		else {
			ofstream file("clients.txt", ios::app);
			if (file.is_open()) {
				file << cl_id << "," << cl_name << "," << cl_pass << "," << cl_bal << endl;
				file.close();
				cout << "Client added successfully." << endl;
			}
			else {
				cout << "Error: Could not open file." << endl;
			}
			list_clients();
		}
	
	
	
}


// ================= Edit clients =================

	void edit_client_name(int cl_id) {
		ifstream file("clients.txt");
		string all_data = "";
		string line;
		bool found = false;

		while (getline(file, line)) {
			stringstream ss(line);
			string id_str, name, pass, bal_str;
			getline(ss, id_str, ',');
			getline(ss, name, ',');
			getline(ss, pass, ',');
			getline(ss, bal_str, ',');

			if (stoi(id_str) == cl_id) {
				found = true;
				string new_name;
				cout << "Enter new name: ";
				cin >> new_name;
				line = id_str + "," + new_name + "," + pass + "," + bal_str;
			}

			all_data += line + "\n";
		}
		file.close();

		ofstream outfile("clients.txt", ios::trunc);
		outfile << all_data;
		outfile.close();

		if (found) {
			cout << "Name updated successfully." << endl;
			list_clients();
		}
		else
			cout << "Client not found." << endl;
	}
	void edit_client_pass(int cl_id) {
		ifstream file("clients.txt");
		string all_data = "";
		string line;
		bool found = false;

		while (getline(file, line)) {
			stringstream ss(line);
			string id_str, name, pass, bal_str;
			getline(ss, id_str, ',');
			getline(ss, name, ',');
			getline(ss, pass, ',');
			getline(ss, bal_str, ',');

			if (stoi(id_str) == cl_id) {
				found = true;
				string new_pass;
				cout << "Enter new pass: ";
				cin >> new_pass;
				line = id_str + "," + name + "," + new_pass + "," + bal_str;
			}

			all_data += line + "\n";
		}
		file.close();

		ofstream outfile("clients.txt", ios::trunc);
		outfile << all_data;
		outfile.close();

		if (found) {
			cout << "Password updated successfully." << endl;
			list_clients();
		}
		else
			cout << "Client not found." << endl;
	}
	void edit_client_balance(int cl_id){
		ifstream file("clients.txt");
		string all_data = "";
		string line;
		bool found = false;

		while (getline(file, line)) {
			stringstream ss(line);
			string id_str, name, pass, bal_str;
			getline(ss, id_str, ',');
			getline(ss, name, ',');
			getline(ss, pass, ',');
			getline(ss, bal_str, ',');

			if (stoi(id_str) == cl_id) {
				found = true;
				string new_balance;
				cout << "Enter new balance: ";
				cin >> new_balance;
				line = id_str + "," + name + "," + pass + "," + new_balance;
			}

			all_data += line + "\n";
		}
		file.close();

		ofstream outfile("clients.txt", ios::trunc);
		outfile << all_data;
		outfile.close();

		if (found) {
			cout << "Balance updated successfully." << endl;
			list_clients();
		}
		else
			cout << "Client not found." << endl;
	} 




	void display()override {
		cout << "Employee details: " << endl;
		Person::display();
		cout << "Salary: " << salary << endl;
	}
};
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



int main()
{


cout << "Welcome to the Banking System!" << endl;
cout << "Please select your role: " << endl;

    return 0;
}
