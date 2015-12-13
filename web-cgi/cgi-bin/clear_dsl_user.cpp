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
#include<stdio.h>
/*
using std::string;
using std::strlen;*/
#include <cstdlib>/*
using std::getenv;
using std::atoi;*/
using namespace std; 

    void cat(string& path,string& source,int len)
     {
    //     source=new char[len];
     int j=0;
while(source[j]!='\0')
{j++;}
     int i;
     int k=0;
     for (i=len;i<j;i++)
     {
         path[i]=source[k];
         k++;
     }
    }
          int strlength(char* st)
{
    return (*st) ? strlength(++st) + 1 : 0;
}
int main()
{
   time_t curtime = time(NULL);//
   struct tm *loctime = localtime(&curtime);//loctime is providing struct of time fully       
 
   char postString[ 1024 ] = ""; // variable to hold POST data
   string dataString = "";
   string ip="";
   
   int contentLength = 0;
   
   // content was submitted
   if ( getenv( "CONTENT_LENGTH" ) ) 
   {
      contentLength = atoi( getenv( "CONTENT_LENGTH" ) );
      cin.read( postString, contentLength );
      dataString = postString;
   } // end if

   cout << "Content-Type: text/html\n\n"; // output header
   
   // output XML declaration and DOCTYPE                       
   cout << "<?xml version = \"1.0\"?>"                         
      << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" "
      << "\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">";  

   // output XHTML element and some of its contents
   cout << "<html xmlns = \"http://www.w3.org/1999/xhtml\">"
      << "<head><title>Update Account</title></head><body>";
  cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/vista%20home.jpg);"
      <<"}"
      <<"-->"
     <<"</style>"; 
   // output XHTML form
   cout << "<p><h1>Update Account </h1></p>";
   
   // data was sent using POST
          int l_location = dataString.find( "ip=" ) + 3;
          int l_endLocation = dataString.find( "&delete" ) ;
  
      // retrieve entered word
      if (l_location>0)
      ip = dataString.substr(l_location, l_endLocation - l_location);
      ofstream out("temp.txt",ios::trunc);
      out<<ip<<endl;
      out.close();
      char file[2];
      ifstream in("temp.txt");
      in>>file;
      in.close();
      //ofstream ou("temp.txt",ios::trunc);
     // char start[10]="192.168.1";
     char path[18];
     char ext[5]=".txt";
      int l=0;
      while(ip[l]!='\0')
      {l++;}
      for(int i=0;i<l;i++)
      {
       path[i]=ip[i];
      }
      for (int i=0;i<5;i++)
      {
          path[l]=ext[i];
          l++;
      }
    //cout<<path<<endl;
      char word[30];
      ofstream sysinfo(path,ios::trunc);
     // sysinfo<<endl;
      sysinfo.close();
     cout<<"<hr/><form id=\"form1\" name=\"form1\" method=\"post\" action=\"http://localhost/admin/updates.html\" target=\"_self\">"
      <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" << Back\" />"
      <<"</label></form>"; 
  // cout<<"<p> VISITOR NUMBER IS 
   cout << "</body></html>";
   return 0;
} // end main
