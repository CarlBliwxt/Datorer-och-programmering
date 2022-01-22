//
// Filen : reverse.cpp 
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string infilnamn, utfilnamn, rad;

  // Läs namn för den skadade filen

  cout << "Ge filnamn för den skadade filen: " ;
  getline( cin, infilnamn );
  ifstream infil( infilnamn.c_str() ); // �ppna och koppla! 

  if ( !infil.good() )  // Felhantering
    {
      cout << "Filen gick inte att �ppna!" << endl;
      return 0;
    }

  // �ppna en ny fil (den �terst�llda filen, dvs utfil)

  cout << "Ge filnamn f�r den �terst�llda filen: " ;
  getline( cin, utfilnamn );
  ofstream utfil( utfilnamn.c_str() ); // �ppna och koppla!

  if ( !utfil.good() )  // Felhantering
    {
      cout << "Filen gick inte att �ppna!" << endl;
      return 0;
    }

  // L�s en rad i taget tills vi kommit till slutet
  while ( getline( infil, rad ) )
    {
      // V�nd p� raden: skriv ut tecknen i omv�nd ordning
      
      for (int i = rad.length()-1; i >= 0; i--)
	utfil << rad.at(i);
      utfil << endl;  // L�gg till radbrytning
    }

  // St�ng filerna. G�rs eg. automatiskt.
  infil.close();
  utfil.close();
  
  return 0;
}
