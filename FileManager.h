#pragma once

#include"DataSourceInterface.h"
#include"Fileshelper.h"


class FileManager : public DataSourceInterface
{
  public:
    //===============================//
    void  addClient(Client obj) {
      	Fileshelper::SaveClient(obj);
      	}

    void  addEmployee(Employee obj) {
        Fileshelper::SaveEmployee(obj);
    }

    void addAdmin(Admin obj){
        Fileshelper::SaveAdmin(obj);
    }

    //===============================//
    void  updateClients() {
      	removeAllClients();

      	 for(cIt = allClients.begin();cIt != allClients.end(); cIt++){
                addClient(*cIt);
                }
      	}


    void  updateEmployees() {
         for(eIt = allEmployees.begin();eIt != allEmployees.end(); eIt++){
                addEmployee(*eIt);
         }

    }


    void updateAdmins(){
         for(aIt = allAdmins.begin();aIt != allAdmins.end(); aIt++){
                addAdmin(*aIt);
         }

        }


  //===============================//

    void getAllClients() {
        Fileshelper::getClients();
    }

     void getAllEmployees() {
	     Fileshelper::getEmployees();
	 }

	 void getAllAdmins() {
	     Fileshelper::getAdmins();
	 }

    void getAllData(){
        getAllAdmins();
        getAllEmployees();
        getAllClients();

    }


  //===============================//

	 void removeAllClients() {
	     Fileshelper::ClearFile(C_File_Path,C_File_ID_Path, 0);
	 }

	 void removeAllEmployees() {
	      Fileshelper::ClearFile(E_File_Path,E_File_ID_Path, 100);
	 }

	  void removeAllAdmins() {
	     Fileshelper::ClearFile(A_File_Path,A_File_ID_Path, 1000);
	 }





};


