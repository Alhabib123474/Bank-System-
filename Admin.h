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

// ================= Add clients =================

void addclient(Client& client){
    allClients.push_back(client);
}




// ================= search client =================
	Client* search_client(int cl_id) {
	    for(cIt = allClients.begin(); cIt != allClients.end(); cIt++){
	        if(cIt->getid()== cl_id)
                return &(*cIt);

	    }
	    return nullptr;
	}



// ================= List clients =================
	void list_clients(){
	    for(cIt = allClients.begin(); cIt != allClients.end(); cIt++){
	      cIt->display();
	      cout << "-------------------" << endl;

	    }
	}




// ================= Edit clients =================

	void edit_client(Client* c, string cl_name, string cl_password, double cl_balance) {
	    c->setname(cl_name);
	    c->setpassword(cl_password);
	    c->setBalance(cl_balance);
	}



//========================================Employee============================================//



// ================= Add Employees =================

void addEmployee(Employee& employee){
    allEmployees.push_back(employee);
}




// ================= search Employees =================
	Employee* search_employees(int e_id) {
	    for(eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++){
	        if(eIt->getid()== e_id)
                return &(*eIt);

	    }
	    return nullptr;
	}



// ================= List Employees =================
	void list_Employees(){
	    for(eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++){

	        eIt->display();
            cout << "-------------------" << endl;


	    }
	}




// ================= Edit Employees =================

	void edit_Employee(Employee* e, string e_name, string e_password, double e_salary) {
	    e->setname(e_name);
	    e->setpassword(e_password);
	    e->setsalary(e_salary);
	}




	void display()override
	{
		cout << "Admin details: " << endl;
		Person::display();
		cout << "salary: " << salary << endl;
	}

};

static vector<Admin> allAdmins;
