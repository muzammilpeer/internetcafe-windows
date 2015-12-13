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
   string remember="";
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
   int namelocation = dataString.find( "namebox=" ) + 8; 
   int endNamelocation = dataString.find( "&" );         
   int password = dataString.find( "passwordbox=" ) + 12;
   int endPassword = dataString.find( "&remember" );
   int rememberlocation=dataString.find( "remember=" )+9;
   int end_remember=dataString.find( "&login" );
   
   // get values for name and password                                    
   nameString = dataString.substr(                                        
      namelocation, endNamelocation - namelocation );                     
   passwordString = dataString.substr( password, endPassword - password );
   remember = dataString.substr( rememberlocation, end_remember - rememberlocation );
   
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
      <<"<title>Pearl Server </title></head><body>";
  /*cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/vista%20home.jpg);"
      <<"}"
      <<"-->"
     <<"</style>";*/ 
   // output specials
      ifstream u_no("number.txt");
      bool check=false;
      char num[6];
      u_no>>num;
      int total=atoi(num);
      u_no.close();
      char path[6];
      char ext[5]=".txt";
      char load_name[30];
      char load_password[30];
      char user[10]="";
      for (int i=10000;i<=total;i++)
          {
          sprintf(path,"%d",i);
          strcat(path,ext);    
          ifstream in(path);
          in>>load_name;
          in>>load_password;    
          int l=0;
             while (load_password[l]!='\0')
             {l++;
             }
             for (int i=0;i<l;i++)
             {
             load_password[i]=load_password[i]-25;
             }
             if (passwordString ==load_password && nameString == load_name)
               {
                 check=true;  
                 strcat(user,path);               
               }
          }

         if ( check==true ) // password is correct
         {
          cout << "<h1>Welcome " << nameString << "!</h1>"
          << "<p>Wait for few second.......</p>"
          << "<ul><li>Will Enjoy Downloading </li>";
         cout << "<hr /><p> "
         << "Your are Verified.</p>";
         ofstream sysinfo(user,ios::app);
         sysinfo<<"online"<<endl;
         sysinfo.close();
         ofstream sess("tempi.txt");
         sess<<nameString<<endl;
         sess.close();
         cout<<" <form action=\"http://localhost/macerma/index.html\" method=\"post\" name=\"form1\" target=\"_parent\" id=\"form1\">"
         <<"<label>"
         <<"<input type=\"submit\" name=\"move forward\" id=\"move forward\" value=\"Forward &gt;&gt;\" />"
         <<"</label>"
         <<"</form>";
         }
         else
         {
              cout << "<p><hr/>Sorry. Wrong User Name And Password. </p>";
              cout<<"<meta http-equiv=\"refresh\" content=\"1;URL=http://"<<query<<"/main/left.html\"/>";
       
         }
   cout << "</body></html>";
   return 0;
} // end main
