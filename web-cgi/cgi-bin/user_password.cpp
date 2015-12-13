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
   
   cout << "Content-Type: text/html\n\n"; // output HTTP header
   
   // output XML declaration and DOCTYPE                       
   cout << "<?xml version = \"1.0\"?>"                         
      << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" "
      << "\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"  
   // output html element and some of its contents
      << "<html xmlns = \"http://www.w3.org/1999/xhtml\">"
      << "<script src=\"../Scripts/AC_RunActiveContent.js\" type=\"text/javascript\"></script>"
      <<"<style type=\"text/css\">"
      <<"<!--"
      <<".style1 {"
	  <<"font-size: large"
      <<"}"
      <<"-->"
      <<"</style>"
      << "<head>"
      <<"<meta http-equiv=\"Pragma\" content=\"no-cache\">"
      <<"<meta http-equiv=\"expires\" content=\"0\">"
      <<"<title>User Session </title>";
      cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/vista%20home.jpg);"
      <<"}"
      <<"-->"
     <<"</style>";
      cout<<"</head><body><h5>Pearl Server >> User >> User Password</h5>"
      <<"<h1>User Password Session </h1></hr><p></p>";
      
      ifstream u_no("number.txt");
      char num[6];
      u_no>>num;
      int total=atoi(num);
      u_no.close();
      char path[6];
      char ext[5]=".txt";
      char name[30];
      char password[30];
    cout<<"<table width=\"500\" border=\"1\">"
    <<"<tr>"
    <<"<td width=\"250\"><p class=\"style1\"><b><i> User Name</b></i></p></td>"
    <<"<td><b><i><p class=\"style1\"> Password </b></i></p></td>"
    <<"</tr>";
    for (int i=10001;i<=total;i++)
    {
    sprintf(path,"%d",i);
    strcat(path,ext);    
    ifstream in(path);
    in>>name;
    in>>password;    
   int l=0;
             while (password[l]!='\0')
             {l++;
             }
             for (int i=0;i<l;i++)
             {
             password[i]=password[i]-25;
             }
    cout<<"<tr>"
    <<"<td>"<<name<<"</td>"
    <<"<td>"<<password<<"</td>"
    <<"</tr>";
    }
    cout<<"</table>";
    cout<<"<p></p>";
    cout<<"<form id=\"form1\" name=\"form1\" method=\"post\" action=\"../admin/table.html\" target=\"_self\">"
    <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" Back &lt;&lt;\" />"
    <<"</label></form>";
   cout << "</body></html>";
   return 0;
} // end main
