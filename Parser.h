#pragma once
#include "Employee.h"
#include "Admin.h"
#include "Client.h"


#include <sstream>
using namespace std;



class Parser{

private:

       static vector<string> split(string line){
        vector<string> parts;
        string part;
        stringstream ss(line);

        while(getline(ss,part,',')){
            parts.push_back(part);
        }
        return parts;
    }



public:



    static Client ParseTOClient(string line){

        vector<string> parts = split(line);
        Client c;
        c.setid(stoi(parts[0]));
        c.setname(parts[1]);
        c.setpassword(parts [2]);
        c.setBalance(stod(parts[3]));

       return c;

    }

    static Employee ParseTOEmployee(string line){

        vector<string> parts = split(line);
        Employee e;
        e.setid(stoi(parts[0]));
        e.setname(parts[1]);
        e.setpassword(parts [2]);
        e.setsalary(stod(parts[3]));

       return e;

    }

    static Admin ParseTOAdmin(string line){

        vector<string> parts = split(line);
        Admin a;
        a.setid(stoi(parts[0]));
        a.setname(parts[1]);
        a.setpassword(parts [2]);
        a.setsalary(stod(parts[3]));

       return a;

    }









    };










