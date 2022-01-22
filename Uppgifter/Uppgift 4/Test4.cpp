
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

string namn_pa_fil();
string inlasning(string filnamn);
int main() 
{
  string b;
  string a;
  a=namn_pa_fil();
  b=inlasning(a);

  cout << b ;
return 0;
}
string namn_pa_fil()
{
  string filnamn;
  cout << "Ange filnamn: ";
  getline( cin, filnamn);

  if (filnamn.rfind(".txt") != string::npos)
{
  }
  else{
    filnamn += ".txt";
  }
return  filnamn;
}

string inlasning(string filnamn)
{
  ifstream fin( filnamn.c_str() ); 
  char c;
  string s;
  
  while ( fin.get(c) )
    {
    c;
    s +=c;
    
    }

  return s;
}

if ( !fin ) 
    {
      cout << "Filen existerar ej eller ligger nånstans"
           << endl;
      exit( EXIT_FAILURE );
    }