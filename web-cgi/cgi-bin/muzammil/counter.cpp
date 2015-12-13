#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;
int main()
{
 int thous=12345;
 
 int hund;
 int ten;
 int unit;
 int temp;
 int tho;
 int ten_tho;
 ten_tho=thous/10000;
 temp=thous%10000;
 tho=temp/1000;
 temp=temp%1000;
 hund=temp/100;
 temp=temp%100;
 ten=temp/10;
 unit=thous%10;
 cout<<"Ten thous"<<ten_tho<<"Thous"<<tho<<"Hund "<<hund<<" Ten "<<ten<<" Uint "<<unit<<endl;
    system("pause");
       return 0;
} // end main
