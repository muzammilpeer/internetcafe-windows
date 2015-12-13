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

void change(char pass[30])
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
   string username = "";
   string subject = "";
   string request="";
   string url="";
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
      << "<head><title>Status</title></head><body>";
 cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/vista%20home.jpg);"
      <<"}"
      <<"-->"
     <<"</style>";  
   // output XHTML form
   cout << "<p><h1>Cleared. </h1></p>";
       char ext[5]=".txt";
       
      for (int i=1;i<=9;i++)
      {
       ofstream in;
       if(i==1)
       in.open("1.txt",ios::trunc);
       else if(i==2)
       in.open("2.txt",ios::trunc);
       else if(i==3)
       in.open("3.txt",ios::trunc);
       else if(i==4)
       in.open("4.txt",ios::trunc);
       else if(i==5)
       in.open("5.txt",ios::trunc);
       else if(i==6)
       in.open("6.txt",ios::trunc);
       else if(i==7)
       in.open("7.txt",ios::trunc);
       else if(i==8)
       in.open("8.txt",ios::trunc);
       else in.open("9.txt");
       
       in.close();
     }
   
   
      cout<<"<hr/><form id=\"form1\" name=\"form1\" method=\"post\" action=\"http://localhost/admin/personal.html\" target=\"_self\">"
      <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" << Back\" />"
      <<"</label></form>"; 
  
      // cout<<"<p> VISITOR NUMBER IS 
   cout << "</body></html>";
   return 0;
} // end main
