#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>

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
   char postString[ 1024 ] = "";
   string dataString = "";
   string nameString = "";
   int contentLength = 0;
   string query="";
   string messageString="";
   // data was posted
   if ( getenv( "CONTENT_LENGTH" ) )
      contentLength = atoi( getenv( "CONTENT_LENGTH" ) );
       if ( getenv( "REMOTE_ADDR" ) ) // QUERY_STRING variable exists    
        query = getenv( "REMOTE_ADDR" ); // retrieve QUERY_STRING value
   
   cin.read( postString, contentLength );
   dataString = postString;
   
   // search string for input data                       
   int messagelocation = dataString.find( "message=" ) + 8; 
   int endmessagelocation = dataString.find( "&first" );         
   int namelocation = dataString.find( "first=" ) + 6; 
   int endNamelocation = dataString.find( "&send" );         
   
   // get values for name and password         
   messageString = dataString.substr(                                        
      messagelocation, endmessagelocation - messagelocation );                               
   nameString = dataString.substr(                                        
      namelocation, endNamelocation - namelocation );                     
   cout << "Content-Type: text/html\n\n"; // output HTTP header
   
   // output XML declaration and DOCTYPE                       
   cout << "<?xml version = \"1.0\"?=>"                         
      << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" "
      << "\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">";  
   
   // output html element and some of its contents
   cout << "<html xmlns = \"http://www.w3.org/1999/xhtml\">"
      << "<head>"
      <<"<meta http-equiv=\"Pragma\" content=\"no-cache\">"
      <<"<meta http-equiv=\"expires\" content=\"0\">"
      <<"<title>Refresh </title></head><body>";
      ofstream lad("chat_session.txt",ios::app);
      change(nameString);
      change(messageString);
      lad<<nameString<<">>"<<messageString<<endl;
      cout<<"<meta http-equiv=\"refresh\" content=\"0;URL=http://"<<query<<"/cgi-bin/response.exe\"/>";
   cout << "</body></html>";
   return 0;
} // end main
