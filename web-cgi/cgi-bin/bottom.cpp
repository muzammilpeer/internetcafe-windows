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

   string query="";
   cout << "Content-Type: text/html\n\n"; // output HTTP header
   if ( getenv( "REMOTE_USER" ) ) // QUERY_STRING variable exists    
        query = getenv( "REMOTE_USER" ); // retrieve QUERY_STRING value
   // output XML declaration and DOCTYPE                       
   cout << "<?xml version = \"1.0\"?>"                         
      << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" "
      << "\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">";  
   
   // output html element and some of its contents
   cout << "<html xmlns = \"http://www.w3.org/1999/xhtml\">"
      << "<head>"
      <<"<meta http-equiv=\"Pragma\" content=\"no-cache\">"
      <<"<meta http-equiv=\"expires\" content=\"0\">"
      <<"<title>Pearl Server </title></head><body>";
cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/BACKGROUND.png);"
      <<"}"
      <<"-->"
     <<"</style>";
         cout << "<hr />";
         char serial[10];
         ifstream number("counter.txt");
         number>>serial;
         number.close();
         int i=atoi(serial);
         i++;
         ofstream writenumber("counter.txt",ios::trunc);
         writenumber<<i<<endl;
         writenumber.close();      
         int thous=i;
 
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
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p>";
cout<<"<p>&nbsp;</p><hr/>";
cout<<"<p><b>You Are Visitor Number :";
cout<<"<img src=\"http://localhost/"<<ten_tho<<".jpg\" width=\"50\" height=\"48\" />"
    <<"<img src=\"http://localhost/"<<tho<<".jpg\" width=\"50\" height=\"48\" />"
    <<"<img src=\"http://localhost/"<<hund<<".jpg\" width=\"50\" height=\"48\" />"
    <<"<img src=\"http://localhost/"<<ten<<".jpg\" width=\"50\" height=\"48\" />"
    <<"<img src=\"http://localhost/"<<unit<<".jpg\" width=\"50\" height=\"48\" /></b></p>";

        // cout<<"<h1>Visitor Number :"<<ten<<"</h1>";
  
   cout << "</body></html>";
   return 0;
} // end main
