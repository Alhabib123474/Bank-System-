#pragma once
#include"EmployeeManager.h"

class AdminManager
{
   static void printAdmintMenu(){

    system("cls");
    cout<<"(1) Display my info" <<endl;
    cout<<"(2) update password" <<endl;
    cout<<"(3) add new client" <<endl;
    cout<<"(4) search for client" <<endl;
    cout<<"(5) list all clients" <<endl;
    cout<<"(6) Edit client" <<endl;
    cout<<"(7) add new Employee" <<endl;
    cout<<"(8) search for Employee" <<endl;
    cout<<"(9) list all Employees" <<endl;
    cout<<"(10) Edit Employee" <<endl;
    cout<<"(11) Logout\n "<<endl;

    }

    static void back_exit(Admin* admin){
        int c;

        do{

            cout<<"\n\n(1) Options\t\t(0) Exit\n";
            switch(c){

    case 0:
        exit(0);
        break;

    case 1:
        system("cls");
        AdminOptions(admin);
        break;

    default:
        cout<<"Invalid!"<<endl;
        break;

    }
        }while(c < 0 || c > 1);


    }



   public:

       static Admin* login(int id, string password){
            for(aIt = allAdmins.begin();aIt != allAdmins.end(); aIt++){
	        if(aIt->getid() == id && aIt->getpassword() == password)
                return &(*aIt);
                }
                return nullptr;

        }





       static void newEmployee(Admin* admin){

           Employee emp;
           int id = Fileshelper::GetLast(E_File_ID_Path ) + 1;
           emp.setid(id);
           emp.setname(Validation::EnterName("Enter admin name : "));
           emp.setpassword(Validation::EnterPassword("Enter admin password : "));
           emp.setsalary(Validation::EnterBalance("Enter admin salary : "));

           admin->addEmployee(emp);
           f.addEmployee(emp);
           cout<<"Employee added successfully"<<endl;

}


        static void listallEmployees(Admin* admin){

            cout<<"All Employees : \n"<<endl;
            admin->list_Employees();



        }


        static void searchForEmployee(Admin* admin){

            int id;
            id = Validation::getIntegerNumbers("Enter client id: ");

            Employee* emp = admin->search_employees(id);

            if(emp==nullptr) cout<<"employee not found!"<<endl;
            else emp->display();


        }


        static void  editEmployeeInfo(Admin* admin){
            int id;
            id = Validation::getIntegerNumbers("Enter Employee id: ");

            Employee* employee = admin->search_employees(id);

            if(employee!=nullptr){
            cout<<"======= update data ======="<<endl;

            string name = Validation::EnterName("Enter Employee name : ");
            string pass = Validation::EnterPassword("Enter Employee password : ");
            double salary = Validation::EnterBalance("Enter Employee salary : ");

            admin->edit_Employee(employee,name,pass,salary);

             f.updateEmployees();

             cout<<"Employee data updated successfully"<<endl;
            }

            else{
                cout<<"Employee not found!"<<endl;
            }
        }




//==========================================================================================//




    static bool AdminOptions(Admin* admin){
        printAdmintMenu();
      int choice;


      cout<<"Enter your choice"<< endl;
      cin>>choice;

      switch(choice)   {
case 1:
    system("cls");
    admin->display();
    break;
case 2://update password
    system("cls");
    ClientManager::updatePassword(admin);
    f.updateAdmins();
    break;
case 3: //add new Employee
    system("cls");
    newEmployee(admin);
    break;
case 4: //search for Employee
    system("cls");
    searchForEmployee(admin);
    break;
case 5: //list all Employee
    system("cls");
    listallEmployees(admin);
    break;
case 6: //Edit Employee
    system("cls");
    editEmployeeInfo(admin);
    break;
 case 7: //add new Employee
    system("cls");
    newEmployee(admin);
    break;
case 8: //search for Employee
    system("cls");
    searchForEmployee(admin);
    break;
case 9: //list all Employee
    system("cls");
    listallEmployees(admin);
    break;
case 10: //Edit Employee
    system("cls");
    editEmployeeInfo(admin);
    break;

case 11: //logout
    return false;
    break;
default:
    system("cls");
    AdminOptions(admin);
    return true;
    }

      back_exit(admin);
      return true;


  }
};


