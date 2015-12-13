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
          if (pass[i]==32)
          {
          pass[i]=43;
          }
      }
 }
int main()
{
   char postString[ 1024 ] = "";
   string dataString = "";
   string statusString = "";
   string descriptionString = "";
   int contentLength = 0;
   string query="";
   time_t currentTime;
   time( &currentTime ); 
   // data was posted
   if ( getenv( "CONTENT_LENGTH" ) )
      contentLength = atoi( getenv( "CONTENT_LENGTH" ) );
       if ( getenv( "REMOTE_ADDR" ) ) // QUERY_STRING variable exists    
        query = getenv( "REMOTE_ADDR" ); // retrieve QUERY_STRING value
   
   cin.read( postString, contentLength );
   dataString = postString;
   
   // search string for input data                       
   int statuslocation = dataString.find( "status_server=" ) + 14; 
   int endstatuslocation = dataString.find( "&" );         
   int description = dataString.find( "description=" ) + 12;
   int enddescription = dataString.find( "&update" );       
   
   // get values for name and password                                    
   statusString = dataString.substr(                                        
      statuslocation, endstatuslocation - statuslocation );                     
   descriptionString = dataString.substr( description, enddescription - description );
   
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
      ofstream out("server_status.txt",ios::trunc);
      out<<statusString<<endl;
      string time=asctime( localtime( &currentTime ) );
      int l=0;
      change(time);
      while(descriptionString[l]!='\0')
      {l++;}
      if (l>1)
      out<<descriptionString<<"+Time:+"<<time<<endl;
      else
      out<<"+Time:+"<<time<<endl;
      
      out.close();
      cout<<"<form id=\"form1\" name=\"form1\" method=\"post\" action=\"http://localhost/admin/updates.html\" target=\"_self\">"
    <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" Back &lt;&lt;\" />"
    <<"</label></form>"; 
   cout << "</body></html>";
   return 0;
} // end main
