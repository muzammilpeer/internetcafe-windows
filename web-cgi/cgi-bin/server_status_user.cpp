// Fig. 19.14: portal.cpp
// Handles entry to Bug2Bug Travel.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;
void change(string& pass)
{
     int l=0;
     while(pass[l]!='\0')
     {l++;
     }
     for( int i=0;i<l;i++)
     {
          if (pass[i]==43)
          {
          pass[i]=32;
          }
      }
 }
int main()
{
   string statusString = "";
   string descriptionString = "";
  
   time_t currentTime;
   time( &currentTime ); 
   cout << "Content-Type: text/html\n\n"; // output HTTP header
   
   // output XML declaration and DOCTYPE                       
   cout << "<?xml version = \"1.0\"?>"                         
      << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" "
      << "\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">";  
   
   // output html element and some of its contents
   cout << "<html xmlns = \"http://www.w3.org/1999/xhtml\">"
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
      << "<head>"
      <<"<meta http-equiv=\"Pragma\" content=\"no-cache\">"
      <<"<meta http-equiv=\"expires\" content=\"0\">"
      <<"<title>Pearl Server </title></head><body>";
   cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/vista%20home.jpg);"
      <<"}"
      <<"-->"
     <<"</style>";

   // output specials
      ifstream in("server_status.txt");
      in>>statusString;
      in>>descriptionString;
      in.close();
      change(statusString);
      change(descriptionString);
      cout<<"<hr/><p><b><i>Server Status :</i></b>"
      <<"<input name=\"status\" type=\"text\" size=\"15\"id=\"1\" value=\""<<statusString<<"\" />"
      <<"</p><hr/><h3>Description</h3><textarea name=\"description\" id=\"description\" cols=\"45\" rows=\"10\">"
      <<descriptionString<<"</textarea>";
      cout<<"<form id=\"form1\" name=\"form1\" method=\"post\" action=\"http://localhost/server_status.html\" target=\"_self\">"
    <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" Refresh Status\" />"
    <<"</label></form>"; 
   cout << "</body></html>";
   return 0;
} // end main
