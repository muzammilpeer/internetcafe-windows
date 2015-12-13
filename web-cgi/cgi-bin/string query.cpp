#include <iostream>
  using std::cout;
   #include <string>
   using std::string;
 
   #include <cstdlib>
  using::getenv;

  int main()
  {
     string nameString = "";
    string wordString = "";
     string query = "";

     if ( getenv( "REMOTE_ADDR" ) ) // QUERY_STRING variable exists    
        query = getenv( "REMOTE_ADDR" ); // retrieve QUERY_STRING value

     cout << "Content-Type: text/html\n\n"; // output HTTP header

     // output XML declaration and DOCTYPE
     cout << "<?xml version = \"1.0\"?>"
        << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" "
        << "\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">";
time_t curtime = time(NULL);//
  struct tm *loctime = localtime(&curtime);//loctime is providing struct of time fully       
  
     // output html element and some of its contents
     cout << "<html xmlns = \"http://www.w3.org/1999/xhtml\">"
        << "<head><title><marquee>Detect IP </marquee></title></head><body>";


     // output xhtml form
     cout << "<p>Enter one of your favorite words here:</p>"
        << "<form method = \"get\" action = \"string query.exe\">"
        << "<input type = \"text\" name = \"word\"/>"
        << "<input type = \"submit\" value = \"Submit Word\"/></form>";

        cout<<"<p> IP : "<<query<<"</p>";           

    
     cout << "</body></html>";

     return 0;
  } // end main
