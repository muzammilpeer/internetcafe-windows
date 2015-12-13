// Fig. 19.14: portal.cpp
// Handles entry to Bug2Bug Travel.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;
bool strcmpr(char first[30],char second[30])
{
     bool check=true;
     int len=strlen(first);
     for(int i=0;i<len;i++)
     {
      if (first[i]!=second[i])
      {check=false;}
     }
     
     return check;
}
int main()
{

   string query="";
   cout << "Content-Type: text/html\n\n"; // output HTTP header
   if ( getenv( "REMOTE_USER" ) ) // QUERY_STRING variable exists    
        query = getenv( "REMOTE_USER" ); // retrieve QUERY_STRING value
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
cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/BACKGROUND.png);"
      <<"}"
      <<"-->"
     <<"</style>";
cout<<"     <style type=\"text/css\">"
<<"<!--"
<<".style2 {"
<<"	font-size: xx-large;"
<<"	font-style: italic;"
<<"}"
<<".style3 {font-weight: bold; font-family: Geneva, Arial, Helvetica, sans-serif;}"
<<"-->"
<<"</style>";
         cout << "<hr />";

ifstream u_no("number.txt");
      bool check=false;
      char num[6];
      u_no>>num;
      int total=atoi(num);
      u_no.close();
      char path[6];
      char ext[5]=".txt";
      char load_name[30];
      char status[30];
      char user[10]="";
      cout<<"<h2>Online People</h2><hr/>";
      for (int i=10000;i<=total;i++)
          {
          sprintf(path,"%d",i);
          strcat(path,ext);    
          ifstream in(path);
          in>>load_name;
          for(int i=0;i<=8;i++)
          {
          in.getline(status,30,'\n');    
          }
          int l=0;
             /*if (strcmpr("online",status)==true)
               {
                 check=true;  
                 strcat(user,path);  
                 ifstream first("tempi.txt");
                 char f_name[30];
                 first.getline(f_name,30,'\n');
                 first.close();
                 cout<<"<form id=\"form3\" name=\"form3\" method=\"post\" action=\"/cgi-bin/chat.exe\">"
                 <<"<label>"
                 <<"<input name=\"first\" type=\"hidden\" id=\"first\" value=\""<<f_name<<"\" />"
                 <<"</label>"
                 <<"<label>"
                 <<"<input name=\"second\" type=\"text\" id=\"second\" value=\""<<load_name<<"\" />"
                 <<"</label><label>"
                 <<"<input type=\"submit\" name=\"chat\" id=\"chat\" value=\"Chat\" />"
                 <<"</label></form>";

               }*/
          }
ifstream first("tempi.txt");
                 char f_name[30];
                 first.getline(f_name,30,'\n');
                 first.close();
cout<<"<form id=\"form3\" name=\"form3\" method=\"post\" action=\"/cgi-bin/chat.exe\">"
                 <<"<label>"
                 <<"<input name=\"first\" type=\"hidden\" id=\"first\" value=\""<<f_name<<"\" />"
                 <<"</label>"
                 <<"<label>"
                 <<"<input name=\"second\" type=\"text\" id=\"second\" value=\""<<load_name<<"\" />"
                 <<"</label><label>"
                 <<"<input type=\"submit\" name=\"chat\" id=\"chat\" value=\"Chat\" />"
                 <<"</label></form>";
         //cout<<"<meta http-equiv=\"Refresh\" content=\"0\" />";
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
<<"</form>";

/*cout<<"<form action=\"/cgi-bin/chat.exe\" enctype=\"application/x-www-form-urlencoded\" method=\"post\" name=\"form2\" target=\"_self\" id=\"form2\">"
 <<" <label>"
  <<"<input name=\"message\" type=\"text\" id=\"message\" size=\"35\" />"
  <<"<input type=\"submit\" name=\"send\" id=\"send\" value=\"Send\" />"
  <<"</label>"
<<"</form>"                               
<<"<p class=\"style2\">&nbsp;</p>";*/
 //cout<<"<meta http-equiv=\"refresh\" content=\"2;URL=http://localhost/cgi-bin/next.exe\"/>"; 
   cout << "</body></html>";
   return 0;
} // end main
