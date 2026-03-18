#pragma once
#include"Parser.h"
#include"fstream"

#define C_File_Path  "data/clients.txt"
#define E_File_Path  "data/employees.txt"
#define A_File_Path  "data/admins.txt"

#define C_File_ID_Path  "data/LastClient'sID.txt"
#define E_File_ID_Path  "data/LastEmployee'sID.txt"
#define A_File_ID_Path  "data/LastAdmin'sID.txt"


class Fileshelper
{
    public:

   static void SaveLast(string filename,int id){
        fstream file(filename,ios::out);
        file<<id;
        file.close();

    }


    static int GetLast(string filename){
        fstream file;
        file.open(filename,ios::in);
        int id;
        file>>id;
        return id;
        }


    static void SaveClient(Client c){
        fstream file(C_File_Path,ios::app);

        file<<c.getid()<<","<<c.getname()<<","<<c.getpassword()<<","<<c.getBalance()<<endl;
        file.close();

        SaveLast(C_File_ID_Path,c.getid());

      }


   static void SaveEmployee(Employee e){
        fstream file(E_File_Path,ios::app);

        file<<e.getid()<<","<<e.getname()<<","<<e.getpassword()<<","<<e.getSalary()<<endl;
        file.close();

        SaveLast(E_File_ID_Path,e.getid());


      }


    static void SaveAdmin(Admin a){
        fstream file(A_File_Path,ios::app);

        file<<a.getid()<<","<<a.getname()<<","<<a.getpassword()<<","<<a.getSalary()<<endl;
        file.close();

        SaveLast(A_File_ID_Path,a.getid());


      }




    static void getClients(){
        fstream file(C_File_Path, ios::in);

        string line;
        while(getline(file,line)){
            allClients.push_back(Parser::ParseTOClient(line));
        }
        file.close();

    }


    static void getEmployees(){
        fstream file(E_File_Path, ios::in);

        string line;
        while(getline(file,line)){
            allEmployees.push_back(Parser::ParseTOEmployee(line));
        }
        file.close();

    }

    static void getAdmins(){
        fstream file(A_File_Path, ios::in);

        string line;
        while(getline(file,line)){
            allAdmins.push_back(Parser::ParseTOAdmin(line));
        }
        file.close();

    }


    static void ClearFile(string filename,string lastidfile, int startid){
    fstream file;
    file.open(filename , ios::out);
    file.close();
    file.open(filename , ios::out);
    file << startid;
    file.close();



    }


};


