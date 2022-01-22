// Filen lasdyn.cpp
#include <iostream> // fšr cout
#include <fstream>  // fšr ifstream
#include <string>   // fšr string
using namespace std;

bool flerafiler( string &s )
{
  cout << "Ange filnamn: ";
  getline( cin, s );
  // returnera sant om namnet innehŒller nŒgot
  return ( s.length() != 0 ); 
}

int main()
{
  string filnamn;
  ifstream fin;

  while ( flerafiler(filnamn) ) 
    {
      fin.open( filnamn.c_str() );
      if ( fin.good() )
	{
	  char c;
	  while ( fin.get(c) )
	    cout << c;      
	}
      else
	cout << "kunde inte hitta filen "
             << filnamn << endl;
      fin.close();
      fin.clear();
    }
  
  return 0;
}
