#pragma once
#include"ClientManager.h"

class EmployeeManager
{
    static void printEmployeetMenu(){

    system("cls");
    cout<<"(1) Display my info" <<endl;
    cout<<"(2) update password" <<endl;
    cout<<"(3) add new client" <<endl;
    cout<<"(4) search for client" <<endl;
    cout<<"(5) list all clients" <<endl;
    cout<<"(6) Edit client" <<endl;
    cout<<"(7) Logout\n "<<endl;

    }

    static void back_exit(Employee* employee){
        int c;

        do{

            cout<<"\n\n(1) Options\t\t(0) Exit\n";
            switch(c){

    case 0:
        exit(0);
        break;

    case 1:
        system("cls");
        EmployeeOptions(employee);
        break;

    default:
        cout<<"Invalid!"<<endl;
        break;

    }
        }while(c < 0 || c > 1);


    }



   public:

       static Employee* login(int id, string password){
            for(eIt = allEmployees.begin();eIt != allEmployees.end(); eIt++){
	        if(eIt->getid() == id && eIt->getpassword() == password)
                return &(*eIt);
                }
                return nullptr;

        }





       static void newCLient(Employee* employee){

           Client client;
           int id = Fileshelper::GetLast(C_File_ID_Path ) + 1;
           client.setid(id);
           client.setname(Validation::EnterName("Enter client name : "));
           client.setpassword(Validation::EnterPassword("Enter client password : "));
           client.setBalance(Validation::EnterBalance("Enter client balance : "));

           employee->addclient(client);
           f.addClient(client);
           cout<<"Client added successfully"<<endl;

}


        static void listallClients(Employee* employee){

            cout<<"All Clients : \n"<<endl;
            employee->list_clients();



        }


        static void searchForClient(Employee* employee){

            int id;
            id = Validation::getIntegerNumbers("Enter client id: ");

            Client* cl = employee->search_client(id);

            if(cl==nullptr) cout<<"Client not found!"<<endl;
            else cl->display();


        }


        static void  editClientInfo(Employee* employee){
            int id;
            id = Validation::getIntegerNumbers("Enter client id: ");

            Client* cl = employee->search_client(id);

            if(cl!=nullptr){
            cout<<"======= update data ======="<<endl;

            string name = Validation::EnterName("Enter client name : ");
            string pass = Validation::EnterPassword("Enter client password : ");
            double balance = Validation::EnterBalance("Enter client balance : ");

            employee->edit_client(cl,name,pass,balance);

            f.updateClients();

             cout<<"Client data updated successfully"<<endl;
            }

            else{
                cout<<"Client not found!"<<endl;
            }
        }





//==========================================================================================//




    static bool EmployeeOptions(Employee* employee){
        printEmployeetMenu();
      int choice;


      cout<<"Enter your choice"<< endl;
      cin>>choice;

      switch(choice)   {
case 1:
    system("cls");
    employee->display();
    break;
case 2://update password
    system("cls");
    ClientManager::updatePassword(employee);
    f.updateEmployees();
    break;
case 3: //add new client
    system("cls");
    newCLient(employee);
    break;
case 4: //search for client
    system("cls");
    searchForClient(employee);
    break;
case 5: //list all clients
    system("cls");
    listallClients(employee);
    break;
case 6: //Edit client
    system("cls");
    editClientInfo(employee);
    break;

case 7: //logout

    return false;
    break;

default:
    system("cls");
    EmployeeOptions(employee);
    return true;
      }

      back_exit(employee);
      return true;


  }





};

