#pragma once
#include"Client.h"


class Employee : public Person {
private:
	double salary;

public:

//========default const=====//
    Employee():Person(){
        salary = 0;

    }


	Employee(int i,string n, string p, double s) : Person(i, n, p) {
	setsalary(s);
	}



//======setters======//



	bool setsalary(double s) {
		if (Validation::validate_sal(s))
            this->salary = s;

	}



//=====getters======//



	double getSalary() {
		return salary;
	}






 // ================= Add clients =================

void addclient(Client& client){
    allClients.push_back(client);
}




// ================= search client =================
	Client* search_client(int cl_id) {
	    for(cIt = allClients.begin();cIt != allClients.end(); cIt++){
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





	void display()override {
		cout << "Employee details: " << endl;
		Person::display();
		cout << "Salary: " << salary << endl;
	}
};

static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;
