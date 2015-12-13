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
   time_t curtime = time(NULL);//
   struct tm *loctime = localtime(&curtime);//loctime is providing struct of time fully       
 
   char postString[ 1024 ] = ""; // variable to hold POST data
   string dataString = "";
   string cabinet="";
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
      << "<head><title>Close Account</title></head><body>";
  cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/vista%20home.jpg);"
      <<"}"
      <<"-->"
     <<"</style>"; 
   // output XHTML form
   cout << "<p><h1>Close Account </h1></p>";
   
   // data was sent using POST
          
          int l_location = dataString.find( "cabinet=" ) + 8;
          int l_endLocation = dataString.find( "&close" ) ;
      // retrieve entered word
      if (l_location>0)
      cabinet = dataString.substr(l_location, l_endLocation - l_location);
      ofstream out("temp.txt",ios::trunc);
      out<<cabinet<<endl;
      out.close();
      char file[2];
      ifstream in("temp.txt");
      in>>file;
      in.close();
      char ext[5]=".txt";
      char* never;
      never = new char[7];
      strcat(never,file);
      strcat(never,ext);
      char hour_t[5];
      char min_t[5];
      string client_name;
      ifstream info(never);
      info>>client_name;
      info>>hour_t;
      info>>min_t;
      info.close();
      int hour=atoi(hour_t);
      int min=atoi(min_t);
      if (hour==0 && min==0)
      {
      hour=loctime->tm_hour;
      min=loctime->tm_min;
      }
      int end_hour=loctime->tm_hour;
      int end_min=loctime->tm_min;
      int diff_hour;
      int diff_min;
      int t_hour;
      int t_min;
      int rate_hour=20;
      float rate_min=0.333;
      float amount;
      if (min>end_min)
      {
      diff_hour=end_hour-hour;
      diff_min=min-end_min;
     
      t_min=diff_min;
      diff_hour-=1;
      t_hour=diff_hour;
      diff_min-=60;
      amount=(t_hour*rate_hour) + (-diff_min*rate_min);
      }
      else
      {
      diff_hour=end_hour-hour;
      diff_min=end_min-min;
      t_hour=diff_hour;
      t_min=diff_min;
      amount=(t_hour*rate_hour) + (t_min*rate_min);
      }
     /* if (t_hour>2)
      {
      amount/=100;
      amount*=90;
      }*/
      change(client_name);
      cout<<"<table width=\"600\" border=\"1\">"
       <<"<tr>"
       <<"<th scope=\"col\">Client Name</th>"
       <<"<th scope=\"col\">Initial Time</th>"
       <<"<th scope=\"col\">Final Time</th>"
       <<"<th scope=\"col\">Total Time</th>"
       <<"<th scope=\"col\">Total Amount</th>"
       <<"<th scope=\"col\">Discount </th>"
       <<"</tr>";
       cout<<"<tr>"
          <<"<td><b>"<<client_name<<"</b></td>"
          <<"<td>"<<hour<<" : "<<min<<"</td>"
          <<"<td>"<<end_hour<<" : "<<end_min<<"</td>"
          <<"<td>"<<diff_hour<<" : "<<diff_min<<"</td>"
          <<"<td><i>"<<amount<<"</i></td>"
          <<"<td><i>"<<"10%"<<"</i></td>"
          <<"</tr>";
    
      cout<<"</table>";
      cout<<"<hr/><form id=\"form1\" name=\"form1\" method=\"post\" action=\"http://localhost/admin/personal.html\" target=\"_self\">"
      <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" << Back\" />"
      <<"</label></form>"; 
      ofstream sysinfo(never,ios::trunc);
      out<<endl;
      out.close();
  // cout<<"<p> VISITOR NUMBER IS 
   cout << "</body></html>";
   return 0;
} // end main
