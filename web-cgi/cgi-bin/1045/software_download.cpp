// Fig. 19.14: portal.cpp
// Handles entry to Bug2Bug Travel.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include<iomanip>
using namespace std;
int main()
{
   char postString[ 1024 ] = "";
   string dataString = "";
   string search = "";
   int contentLength = 0;
   
   // data was posted
   if ( getenv( "CONTENT_LENGTH" ) )
      contentLength = atoi( getenv( "CONTENT_LENGTH" ) );
   cin.read( postString, contentLength );
   dataString = postString;
   
   // search string for input data                       
   int namelocation = dataString.find( "search=" ) + 7; 
   int endNamelocation = dataString.find( "&go" );    
   search = dataString.substr(namelocation, endNamelocation - namelocation );            
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
      <<"<title>Fast Downloading </title></head><body><h5>Search </h5>"
      <<"<h1>Results </h1><hr/><p></p>";
   ofstream p("path.txt",ios::trunc);
   p<<search<<endl;
   p.close();
   ifstream in("path.txt");
   char file[50]="";
   char name[30];
   in.getline(name,30,'\n');
   in.close();
   strcat(file,name);
   char ext[5]=".exe";
   char full_path[255]="http://localhost/data/software/";
   strcat(file,ext);
   strcat(full_path,file);
   ifstream sea(file);
   if (sea.is_open()==true)
   {
   cout<<"<p>1 File Found </p>";                        
   cout<<"<h3>"<<file<<"</h3>";                        
   cout<<"<a href=\""<<full_path<<"\"><img src=\"http://localhost/macerma/pages/download.jpg\" "
   <<"width=\"50\" height=\"50\" /></a></h1>";

   }
   else  cout<<"<p>No File with this name exist. </p></h1>"; 
    /*cout<<"<form id=\"form1\" name=\"form1\" method=\"post\" action=\"../admin/table.html\" target=\"_self\">"
    <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" Back &lt;&lt;\" />"
    <<"</label></form>";
  */ cout << "</body></html>";

   return 0;
} // end main
