// Fig. 19.12: post.cpp
// Demonstrates POST method with XHTML form.
#include <iostream>
#include <fstream>
/*using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::ios;*/
#include <string>
#include <cstring>
/*
using std::string;
using std::strlen;*/
#include <cstdlib>/*
using std::getenv;
using std::atoi;*/
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
void changeto(string& pass)
{
     int l=0;
     while(pass[l]!='\0')
     {l++;
     }
     for( int i=0;i<l;i++)
     {
          if(pass[i]==37 && pass[i+1]==51 && pass[i+2]==65)
          {
          pass[i]=58;
          pass[i+1]=0;
          pass[i+2]=8;
          }
          if (pass[i]==37 )
          {
          pass[i]=47;
          pass[i+1]=0;
          pass[i+2]=8;
          }
           if (pass[i]==43)
          {
          pass[i]=32;
          }
      }
 
 }     
int strlength(char* st)
{
    return (*st) ? strlength(++st) + 1 : 0;
}
int main()
{
  char postString[ 1024 ] = ""; // variable to hold POST data
   string dataString = "";
   string subject = "";
   string request="";
   int contentLength = 0;
  
   cout << "Content-Type: text/html\n\n"; // output header
   
   // output XML declaration and DOCTYPE                       
   cout << "<?xml version = \"1.0\"?>"                         
      << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" "
      << "\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">";  

   // output XHTML element and some of its contents
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
      << "<head><title>Using POST with Forms</title></head><body>";
  cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/vista%20home.jpg);"
      <<"}"
      <<"-->"
     <<"</style>";
 
   // output XHTML form
   cout << "<p><h1>Resolved Updates. </h1></p>";
   cout<<"<table width=\"600\" border=\"1\">"
       <<"<tr>"
       <<"<th scope=\"col\">Subject</th>"
       <<"<th scope=\"col\">Description</th>"
       <<"</tr>";
   
      ifstream in("resolved.txt");
      while (!in.eof())
      {
      in>>subject;
      in>>request;
      change(subject);
      changeto(request);
      cout<<"<tr>"
          <<"<td><b>"<<subject<<"</b></td>"
          <<"<td>"<<request<<"</td>"
          <<"</tr>";
      }
  
      in.close();
   
      cout<<"</table>";
      cout<<"<hr/><form id=\"form1\" name=\"form1\" method=\"post\" action=\"resolve_user.exe\" target=\"_self\">"
      <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" Refresh Status\" />"
      <<"</label></form>"; 
  // cout<<"<p> VISITOR NUMBER IS 
   cout << "</body></html>";
   return 0;
} // end main
