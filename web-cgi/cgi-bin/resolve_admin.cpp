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

          int strlength(char* st)
{
    return (*st) ? strlength(++st) + 1 : 0;
}
int main()
{
  char postString[ 1024 ] = ""; // variable to hold POST data
   string dataString = "";
   string subject;//[150];
   string request;//[150];
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
   
   // output XHTML form
   cout << "<p><h1>Resloved : </h1></p>";
   
   // data was sent using POST
          int subjectlocation = dataString.find_first_of( "subject=" ) + 8;
          int sub_endLocation = dataString.find_first_of( "&" ) ;
          int req_loc=dataString.find("description=")+12;
          int req_endLocation =dataString.find("&send");
          
      // retrieve entered word
      if (subjectlocation>0)
      subject = dataString.substr(subjectlocation, sub_endLocation - subjectlocation);
      if (req_loc>0)
      request = dataString.substr(req_loc,req_endLocation-req_loc);
     //output specials
      ofstream out("resolved.txt",ios::app);
      out<<subject<<endl;
      out<<request<<endl;
      out.close();
      cout<<"<hr/><form id=\"form1\" name=\"form1\" method=\"post\" action=\"http://localhost/admin/request_options.html\" target=\"_self\">"
      <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\" Refresh Status\" />"
      <<"</label></form>"; 
  // cout<<"<p> VISITOR NUMBER IS 
   cout << "</body></html>";
   return 0;
} // end main
