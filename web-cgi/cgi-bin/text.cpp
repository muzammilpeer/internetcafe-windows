#include <iostream>
using namespace std;
int main()
{
    
cout<<"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">"
<<"<html xmlns=\"http://www.w3.org/1999/xhtml\">"
<<"<head>"
<<"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />"
<<"<title>Main Frame</title>"
<<"<style type=\"text/css\">"
<<"<!--"
<<".style2 {"
<<"	font-size: xx-large;"
<<"	font-style: italic;"
<<"}"
<<".style3 {font-weight: bold; font-family: Geneva, Arial, Helvetica, sans-serif;}"
<<"-->"
<<"</style>"
<<"</head>"

<<"<body>"
<<"<h1 class=\"style2\"><span class=\"style3\">Chat Session:</span></h1>"
<<"<form action="" method=\"post\" name=\"form1\" target=\"mainFrame\" id=\"form1\">"
<<"  <label>"
<<"  <textarea name=\"past_messages\" cols=\"32\" rows=\"5\" wrap=\"virtual\" id=\"past_messages\">"
<<"Hello World!"<<"</textarea>"
<<"  </label>"
<<"</form>"
<<"<form action=\"/cgi-bin/chat.exe\" method=\"post\" name=\"form2\" target=\"_self\" id=\"form2\">"
<<"  <label>"
<<"  <input name=\"message\" type=\"text\" id=\"message\" size=\"35\" />"
<<"  <input type=\"submit\" name=\"send\" id=\"send\" value=\"Send\" />"
<<"  </label>"
<<"</form>"
<<"<p class=\"style2\">&nbsp;</p>"
<<"</body>"
<<"</html>";
return 0;
}
