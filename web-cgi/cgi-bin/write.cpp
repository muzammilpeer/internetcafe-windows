// Fig. 19.14: portal.cpp
// Handles entry to Bug2Bug Travel.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;
int main()
{
 
   
   ofstream sea("search.txt",ios::app);
   char stri[30]="firefox";
    sea<<stri<<endl;
    sea.close();
   return 0;
} // end main
