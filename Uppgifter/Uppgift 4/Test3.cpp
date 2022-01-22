#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


string namn_pa_fil();
void inlasning(string fin);


int main()
{
  string filnamn;
  cout << "Ange filnamn: ";
  getline( cin, filnamn);

  ifstream fin( filnamn.c_str() ); 
  string nyckel (".txt");
  size_t found = filnamn.rfind(nyckel);

 /* if (found!= string::npos)
{
  filnamn += nyckel;
  }
  */

if ( !fin ) 
    {
      cout << "Filen existerar ej eller ligger nånstans"
           << endl;
      exit( EXIT_FAILURE );
    }
  char c;
  while ( fin.get(c) )
    {
      // och skriv varje tecken
      cout << c;
    }
  return 0;
}


string namn_pa_fil()
{


  string filnamn;
  cout << "Ange filnamn: ";
  getline( cin, filnamn);


  ifstream fin( filnamn.c_str() ); 
  string nyckel (".txt");
  size_t found = filnamn.rfind(nyckel);

  if (found!= string::npos)
{
  filnamn += nyckel;
  }

if ( !fin ) 
    {
      cout << "Filen existerar ej eller ligger nånstans"
           << endl;
      exit( EXIT_FAILURE );
    }

return filnamn;

}

void inlasning(string filnamn)
{

  ifstream fin( filnamn.c_str() ); 
  char c;
  while ( fin.get(c) )
    {
      // och skriv varje tecken
      cout << c;
    }

}