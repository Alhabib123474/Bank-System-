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

    void getAllClients() {
        Fileshelper::getClients();
    }

	 void getAllEmployees() {
	     Fileshelper::getEmployees();
	 }

	 void getAllAdmins() {
	     Fileshelper::getAdmins();
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


