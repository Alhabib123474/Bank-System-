#pragma once
#include"FileManager.h"

FileManager f;

class ClientManager
{
    static void printClientMenu(){

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

    static Client* login(int id, string password){
            for(cIt = allClients.begin();cIt != allClients.end(); cIt++){
	        if(cIt->getid() == id && cIt->getpassword() == password)
                return &(*cIt);
                }
                return nullptr;


    }




    static void updatePassword(Person* person){
        string newpass;
        do{
            cout<< "Enter New password: ";
            cin>>newpass;
        }
        while(!Validation::validate_pass(newpass));
            person->setpassword(newpass);
            cout<< "Password Updated successfully" <<endl;




    }


//==============================================================================//

  static bool ClientOptions(Client* client){
      printClientMenu();

      int choice;
      int id;
      double amount;

      Client* recipient;
      Employee e;


      cout<<"Enter your choice"<< endl;
      cin>>choice;

      switch(choice)   {
case 1:
    system("cls");
    client->display();
    break;
case 2:
    system("cls");
    client->checkBalance();
    break;
case 3: //
    system("cls");
    updatePassword(client);
    f.updateClients();
    break;
case 4: //withdraw
    system("cls");
    amount = Validation::getDoubleNumbers("Enter amount: ");
    client->withdraw(amount);
    f.updateClients();
    break;
case 5: //deposit
    system("cls");
    amount = Validation::getDoubleNumbers("Enter amount: ");
    client->deposit(amount);
    f.updateClients();
    break;
case 6: //transfer
    system("cls");
    id = Validation::getIntegerNumbers("Enter recipient id: ");

    recipient = e.search_client(id);
    if(recipient != nullptr){
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
    ClientOptions(client);
    return true;
      }

      back_exit(client);
      return true;


  }


};


