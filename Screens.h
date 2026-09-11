    #pragma once
    #include "AdminManager.h"
    #include <stdlib.h>
    #include <chrono>
    #include <thread>
    #include <cstdlib>
    #define sleep(x) std::this_thread::sleep_for(std::chrono::seconds(x))

    class Screens
    {

        static void BankName() {

            cout<<"\n\n\n\n\n\n\n\n\n";

            cout<< "\t\t\t           *   *              * * *             *     *   *   *  "<< endl;
            cout<< "\t\t\t     *     *  *      *        *    *     *      * *   *   *  *   "<< endl;
            cout<< "\t\t\t    * *    **       * *       * * *     * *     *  *  *   **     "<< endl;
            cout<< "\t\t\t   * * *   *  *    * * *      *    *   * * *    *   * *   *  *   "<< endl;
            cout<< "\t\t\t  *     *  *   *  *     *     * * *   *     *   *     *   *   *  "<< endl;
            sleep(2);

        }


        static void Welcome(){
            system("color 8f");
            BankName();

            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n";

            cout << "\t\t\t *       *  *******  *       *        ******   *        *  *******"<<endl;
            cout << "\t\t\t *       *  *        *       *       *      *  * *    * *  *      "<<endl;
            cout << "\t\t\t *   *   *  *****    *       *       *      *  *   **   *  *****  "<<endl;
            cout << "\t\t\t *  * *  *  *        *       *       *      *  *        *  *      "<<endl;
            cout << "\t\t\t * *   * *  *        *       *       *      *  *        *  *      "<<endl;
            cout << "\t\t\t **     **  *******  ******* *******  ******   *        *  *******"<<endl;

            sleep(1);
            system("cls");
            system("color 0f");


        }


        static void LoginOptions(){
            cout<<"(1) Admin "<<endl;
            cout<<"(2) Employee "<<endl;
            cout<<"(3) Client \n "<<endl;
        }




        static int LoginAs(){

            LoginOptions();

            int choice = Validation::getIntegerNumbers("Login as: ");

            if(choice == 1 || choice == 2 || choice == 3){
                system("cls");
                return choice;
            }
            else{
                system("cls");
                return LoginAs();
            }


        }


        static void Invalid(int c){
            system("cls");
            cout<<"Invalid Id or Password!\n"<<endl;
            LoginScreen(c);
        }


        static void Logout(){
            system("cls");
            LoginScreen(LoginAs());
        }


    public:
      static void LoginScreen(int c){
    int choice = c, id;
    string pass;

    id = Validation::getIntegerNumbers("Enter id:");
    pass = Validation::EnterPassword("Enter Password:");

    switch(choice)
    {
    case 1:
    {
       // auto admin = AdminManager::login(id, pass);
       Admin* admin = AdminManager::login(id, pass);
        if (admin != nullptr) {
             while (AdminManager::AdminOptions(admin))
             ;
            //while (AdminManager::AdminOptions(admin) != false);
            Logout();
        }
        else Invalid(1);
        break;
    }

    case 2:
    {
        auto employee = EmployeeManager::login(id, pass);
        if (employee != nullptr) {
            while (EmployeeManager::EmployeeOptions(employee) != false)
                ;
            Logout();
        }
        else Invalid(2);
        break;
    }

    case 3:
    {
        auto client = ClientManager::login(id, pass);
        if (client != nullptr) {
            while (ClientManager::ClientOptions(client) != false)
                ;
            Logout();
        }
        else Invalid(3);
        break;
    }

    default:
        system("cls");
        LoginScreen(LoginAs());
        break;
    }
}


        static void RunApp(){



            Fileshelper::getAdmins();
            Fileshelper::getEmployees();
            Fileshelper::getClients();
            //f.getAllData();
            Welcome();

            LoginScreen(LoginAs());

        }




    };


