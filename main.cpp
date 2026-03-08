#include<iostream>
#include<string>
#include<cmath>
#include"Admin.h"
#include"Parser.h"
using namespace std;


int main()
{


cout << "Welcome to AKA Banking System!" << endl;

Admin a = Parser::ParseTOAdmin("1005,yassen,0000,5000");
a.display();


    return 0;
}
