#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

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
   char postString[ 1024 ] = "";
   string dataString = "";
   string category = "";
   string item="";
   int contentLength = 0;
   
   if ( getenv( "CONTENT_LENGTH" ) )
      contentLength = atoi( getenv( "CONTENT_LENGTH" ) );
   cin.read( postString, contentLength );
   dataString = postString;
   
   int catlocation = dataString.find( "category=" ) + 9; 
   int endcatlocation = dataString.find( "&item" );    
   category = dataString.substr(catlocation, endcatlocation - catlocation );            
   int itemlocation = dataString.find( "item=" ) + 5; 
   int enditemlocation = dataString.find( "&search" );    
   item = dataString.substr(itemlocation, enditemlocation - itemlocation );            
   
   cout << "Content-Type: text/html\n\n"; 
   cout << "<?xml version = \"1.0\"?>"                         
      << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" "
      << "\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"  
      << "<html xmlns = \"http://www.w3.org/1999/xhtml\">"
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
      <<"<title>Fast Downloading </title></head><body><h5>Search </h5>"
      <<"<h1>Results </h1><hr/><p></p>";
   ofstream p("path.txt",ios::trunc);
   change(category);
   change(item);
   p<<category<<endl;
   p<<item<<endl;
   p.close();
   ifstream in("path.txt");
   char file[255]="";
   char name[30];
   char cate[30];
   in.getline(cate,30,'\n');
   in.getline(name,30,'\n');
   in.close();
   char dir[80]="D:/Program Files/Apache Software Foundation/Apache2.2/htdocs/data/";
   char file_path[255]="";
   char *ext;
  // cout<<file;

   //Category Declaration 
   char alb_song[30]="Album Songs";
   char aud_song[30]="Audio Song";
   char soft[30]="Software";
   char vid_song[30]="Video Song";
   char game[30]="Game";
   char os[30]="Operating System";
   char movie[30]="Movie";
   //[\]Category Declaration
   bool album=strcmpr(alb_song,cate);
   bool audio=strcmpr(aud_song,cate);
   bool software=strcmpr(soft,cate);
   bool video=strcmpr(vid_song,cate);
   bool game_=strcmpr(game,cate);
   bool os_=strcmpr(os,cate);
   bool movie_=strcmpr(movie,cate);
  //[\ Booleans]
  //[]Checks
   ext=new char [5];
   char slash[2]="/";
  
   if(album==true)
   {
   ext=".zip";
   strcat(file,alb_song);
   strcat(file,slash);
   strcat(file,name);
   strcat(file,ext);
   cout<<"<h3>Album Song</h3><hr/>";
   }
   else if(audio==true)
   {
   ext=".mp3";
   strcat(file,aud_song);
   strcat(file,slash);
   strcat(file,name);
   strcat(file,ext);
   cout<<"<h3>MP3 Songs</h3><hr/>";
   }
   else if(software==true)
   {
   ext=".zip";
   strcat(file,soft);
   strcat(file,slash);
   strcat(file,name);
   strcat(file,ext);
   cout<<"<h3>Software</h3><hr/>";
   }
   else if(video==true)
   {
   ext=".flv";
   strcat(file,vid_song);
   strcat(file,slash);
   strcat(file,name);
   strcat(file,ext);
   cout<<"<h3>Video Songs</h3><hr/>";
   }
   else if(game_==true)
   {
   ext=".iso";
   strcat(file,game);
   strcat(file,slash);
   strcat(file,name);
   strcat(file,ext);
   cout<<"<h3>Game </h3><hr/>";
   }
   else if(os_==true)
   {
   ext=".iso";
   strcat(file,os);
   strcat(file,slash);
   strcat(file,name);
   strcat(file,ext);
   cout<<"<h3>Operating System </h3><hr/>";
   }
   else if(movie_==true)
   {
   ext=".zip";
   strcat(file,movie);
   strcat(file,slash);
   strcat(file,name);
   strcat(file,ext);
   cout<<"<h3>Movies</h3><hr/>";
   }
   char full_path[100]="http://localhost/data/";
   strcat(full_path,file);
   strcat(dir,file);
   ifstream sea(dir);
   if (sea.is_open()==true)
   {
   cout<<"<p><p></p>1 File Found </p>";                        
   cout<<"<h3>"<<name<<" ";                        
   cout<<"<a href=\""<<full_path<<"\"><img src=\"http://localhost/macerma/pages/download.jpg\" "
   <<"width=\"50\" height=\"50\" /></a></h3>";

   }
   else  cout<<"<p><p></p>No File with this name exist. </p></h1>"; 
   
   cout<<"<form id=\"form1\" name=\"form1\" method=\"post\" action=\"http://localhost/macerma/main/bottom.html\" target=\"_self\">"
   <<"<label>  <input type=\"submit\" name=\"back\" id=\"back\" value=\"  Back \" />"
   <<"</label></form>";
   cout << "</body></html>";
   
   return 0;
} // end main
