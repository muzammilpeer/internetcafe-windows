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
      << "<head><title>Using POST with Forms</title></head>";
      cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<".style1 {"
	  <<"font-family: Geneva, Arial, Helvetica, sans-serif"
      <<"}"
      <<".style4 {"
	  <<"font-family: Geneva, Arial, Helvetica, sans-serif;"
	  <<"font-weight: bold;"
	  <<"font-style: italic;"
      <<"}"
      <<"-->"
      <<"</style>";
      cout<<"<body>";
  /* cout<<"<style type=\"text/css\">"
      <<"<!--"
      <<"body {"
	  <<"background-image: url(http://localhost/vista%20home.jpg);"
      <<"}"
      <<"-->"
     <<"</style>";
   */// output XHTML form
  
   ifstream nu("req.txt");
   char limit[30];
   nu>>limit;
   nu.close();
   int bound=atoi(limit);
      ifstream in("request.txt");
     for(int i=0;i<bound;i++)
      {
      in>>username;
      in>>subject;
      in>>request;
      in>>url;
      change(username);
      change(subject);
      change(request);
      changeto(url);
      cout<<"<hr/>";
    cout<<" <table width=\"500\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">"
  <<"<tr>"
    <<"<td height=\"19\" bgcolor=\"#996699\" class=\"pageName\"><div align=\"left\">"
      <<"<p><strong>"<<username<<" </strong></p>"
      <<"</div></td>"
  <<"</tr>"
  <<"<tr>"
    <<"<td class=\"bodyText\"><p class=\"style1\"><strong></strong><span class=\"style4\">"<<subject<<"</span> </p>"
      <<"<p class=\"style1\">"<<request 
        <<"</p>"
      <<"<p><em>"<<url<<"</em>"
        <<"</div>"
<<"</p></td>"
  <<"</tr>"
<<"</table>";
     // in.close();
}
      cout<<"<hr/><form id=\"form1\" name=\"form1\" method=\"post\" action=\"display_all_request.exe\" target=\"_self\">"
      <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" Refresh Status\" />"
      <<"</label></form>"; 
  // cout<<"<p> VISITOR NUMBER IS 
   cout << "</body></html>";
   return 0;
} // end main
