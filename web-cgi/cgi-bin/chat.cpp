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
   
   // data was posted
   if ( getenv( "CONTENT_LENGTH" ) )
      contentLength = atoi( getenv( "CONTENT_LENGTH" ) );
       if ( getenv( "REMOTE_ADDR" ) ) // QUERY_STRING variable exists    
        query = getenv( "REMOTE_ADDR" ); // retrieve QUERY_STRING value
   
   cin.read( postString, contentLength );
   dataString = postString;
   
   // search string for input data                       
   int namelocation = dataString.find( "first=" ) + 6; 
   int endNamelocation = dataString.find( "&second" );         
   
   // get values for name and password                                    
   nameString = dataString.substr(                                        
      namelocation, endNamelocation - namelocation );                     
  
   cout << "Content-Type: text/html\n\n"; // output HTTP header
   
   // output XML declaration and DOCTYPE                       
   cout << "<?xml version = \"1.0\"?>"                         
      << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" "
      << "\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">";  
   
   // output html element and some of its contents
   cout << "<html xmlns = \"http://www.w3.org/1999/xhtml\">"
      << "<head>"
      <<"<meta http-equiv=\"Pragma\" content=\"no-cache\">"
      <<"<meta http-equiv=\"expires\" content=\"0\">"
      <<"<title>Refresh </title></head><body>";
     /* ofstream lad("chat_session.txt",ios::app);
      change(nameString);
      lad<<nameString<<">>"<<endl;
     */// cout<<"<meta http-equiv=\"refresh\" content=\"2;URL=http://"<<query<<"/cgi-bin/next.exe\"/>";
  cout<<"<h1 class=\"style2\"><span class=\"style3\">Chat Session:</span></h1>"
<<"<form action="" method=\"post\" enctype=\"application/x-www-form-urlencoded\" name=\"form1\" target=\"mainFrame\" id=\"form1\">"
  <<"<label>"
  <<"<textarea name=\"past_messages\" cols=\"32\" rows=\"10\" wrap=\"virtual\" id=\"past_messages\">";

ifstream load("chat_session.txt");
char text[255]="";
while(!load.eof())
{
load.getline(text,255,'\n');
cout<<text<<endl;
}
load.close();
cout<<"</textarea>"
 <<" </label>"
<<"</form>"
<<"<form action=\"/cgi-bin/send_message.exe\" enctype=\"application/x-www-form-urlencoded\" method=\"post\" name=\"form2\" target=\"_self\" id=\"form2\">"
<<"<label>"
  <<"<input name=\"message\" type=\"text\" id=\"message\" size=\"35\" />"
  <<"<label>"
  <<"<input name=\"first\" type=\"hidden\" id=\"first\" value=\""<<nameString<<"\" />"
  <<"</label>"
  <<"<input type=\"submit\" name=\"send\" id=\"send\" value=\"Send\" />"
  <<"</label>"
<<"</form>"
<<"<p class=\"style2\">&nbsp;</p>";
   cout << "</body></html>";
   return 0;
} // end main
