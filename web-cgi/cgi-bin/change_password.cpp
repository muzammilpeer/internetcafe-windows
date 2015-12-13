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
   char postString[ 1024 ] = "";
   string dataString = "";
   string nameString = "";
   string passwordString = "";
   int contentLength = 0;
   string query="";
   
   // data was posted
   if ( getenv( "CONTENT_LENGTH" ) )
      contentLength = atoi( getenv( "CONTENT_LENGTH" ) );
       if ( getenv( "REMOTE_ADDR" ) ) // QUERY_STRING variable exists    
        query = getenv( "REMOTE_ADDR" ); // retrieve QUERY_STRING value
   
   cin.read( postString, contentLength );
   dataString = postString;
   
   // search string for input data                       
   int namelocation = dataString.find( "muzi=" ) + 5; 
   int endNamelocation = dataString.find( "&" );    
   nameString = dataString.substr(                                  
      namelocation, endNamelocation - namelocation );            
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
      <<"<head>"
      <<"<meta http-equiv=\"Pragma\" content=\"no-cache\">"
      <<"<meta http-equiv=\"expires\" content=\"0\">"
      <<"<title>User Session </title></head><body><h5>Pearl Server >> User >> Profile Search</h5>";
cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/vista%20home.jpg);"
      <<"}"
      <<"-->"
     <<"</style>";
cout      <<"<h1>Search User Profile </h1></hr><p></p>";
      
      ifstream u_no("number.txt");
      char num[6];
      u_no>>num;
      int total=atoi(num);
      u_no.close();
      char path[6];
      char ext[5]=".txt";
      char pass[30];
      char name[30];
     cout<<"<table width=\"600\" border=\"1\">"
       <<"<tr>"
       <<"<th scope=\"col\">Full Name</th>"
       <<"<th scope=\"col\">User Name</th>"
       <<"<th scope=\"col\">Password</th>"
       <<"<th scope=\"col\">Sex</th>"
       <<"<th scope=\"col\">Date of Birth</th>"
       <<"</tr>";
    for (int i=10001;i<=total;i++)
    {
    sprintf(path,"%d",i);
    strcat(path,ext);    
    ifstream in(path);
    in>>name;    
    
        cout<<"<tr>";
        if (name==nameString)
        {
        in>>pass;
        char f_name[30];
        char l_name[30];
        char sex[30];
        char day[30];
        char month[30];
        char year[30];
        in>>f_name; 
        in>>l_name;
        in>>sex;
        in>>month;
        in>>day;
        in>>year;         
        int l=0;
             while (pass[l]!='\0')
             {l++;
             }
             for (int i=0;i<l;i++)
             {
             pass[i]=pass[i]-25;
             }           
        cout<<"<td>"<<f_name<<" "<<l_name<<"</td>";
        cout<<"<td>"<<name<<"</td>";
        cout<<"<td>"<<pass<<"</td>";
        cout<<"<td>"<<sex<<"</td>";
        cout<<"<td>"<<month<<day<<", "<<year<<"</td>";
        }
        cout<<"</tr>";
    }
    cout<<"</table>";
    cout<<"<p></p>";
    cout<<"<form id=\"form1\" name=\"form1\" method=\"post\" action=\"../admin/table.html\" target=\"_self\">"
    <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" Back &lt;&lt;\" />"
    <<"</label></form>";
   cout << "</body></html>";
   return 0;
} // end main
