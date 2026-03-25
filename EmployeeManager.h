#pragma once

class EmployeeManager
{
    static void printEmployeetMenu(){

    system("cls");
    cout<<"(1) Display my info" <<endl;
    cout<<"(2) Check Balance" <<endl;
    cout<<"(3) Update Password" <<endl;
    cout<<"(4) withdraw" <<endl;
    cout<<"(5) Deposit" <<endl;
    cout<<"(6) Transfer amount" <<endl;
    cout<<"(7) Logout\n "<<endl;

    }

    static void back_exit(Client* client){
        int c;

        do{

            cout<<"\n\n(1) Options\t\t(0) Exit\n";
            switch(c){

    case 0:
        exit(0);
        break;

    case 1:
        system("cls");
        ClientOptions(client);
        break;

    default:
        cout<<"Invalid!"<<endl;
        break;

    }
        }while(c < 0 || c > 1);


    }



   public:

       static Employee* login(int id, string password){
            for(eIt = allEmployees.begin();eIt != allClients.end(); eIt++){
	        if(eIt->getid() == id && eIt->getpasssword() == password)
                return &(*eIt);
                }
                return nullptr;

        }





       static void newCLient(Employee* employee){

           Client client;
           int id = Fileshelper::GetLast(C_File_ID_Path ) + 1;
           Client.setid(id);
           client.setname(Validation::EnterName("Enter client name : "));
           Client.setpassword(Validation::EnterPassword("Enter client password : "));
           Client.setBalance(Validation::EnterBalance("Enter client balance : "));

           employee->addClient(Client);
           FileManager::addClient(Client);
           cout<<"Client added successfully"<<endl;

}


        static void listallClients(Employee* employee){

            cout<<"All Clients : \n"<<endl;
            employee->list_clients();



        }


        static void searchForClient(Employee* employee){

            int id;
            id = Validation::getIntegerNumbers("Enter client id: "):

            Client* client = employee->search_client(id);

            if(client==nullptr) cout<<"Client not found!"<<endl;
            else client->display();


        }


        static void  editClientInfo(Employee* employee){
            int id;
            id = Validation::getIntegerNumbers("Enter client id: "):

            Client* client = employee->search_client(id);

            if(client!=nullptr){
            cout<<"======= update data ======="<<endl;

            string name = Validation::EnterName("Enter client name : ");
            string pass = Validation::EnterPassword("Enter client password : ");
            double balance = Validation::EnterBalance("Enter client balance : ");

            employee->edit_client(client,name,pass,balance);

             FileManager::updateClients();

             cout<<"Client data updated successfully"<<endl;
            }

            else{
                cout<<"Client not found!"<<endl;
            }
        }





//==========================================================================================//




    static bool EmployeeOptions(Employee* employee){
        printClientMenu();
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
    FileManage::updateEmployees();
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
    amount = Validation::getDoubleNumbers("Enter amount: ");
    client->deposit(amount);
    FileManager::updateClients();
    break;
case 6: //Edit client
    system("cls");
    id = Validation::getIntegerNumbers("Enter recipient id: ");
    client->transfer(amount);

    recipient = e.search_client(id);
    if(recipient){
      amount = Validation::getDoubleNumbers("Enter amount: ");
      client->transfer(*recipient, amount) ;
    }
    else{
        cout<< "Account not found!" <<endl;
    }

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

