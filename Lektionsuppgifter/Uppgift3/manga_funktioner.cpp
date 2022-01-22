// Exempel på många små funktioner av olika typ, dvs
// * Med 0, 1 eller flera parametrar.
// * Returnerar heltalsvärde eller inget värde.

#include <iostream>
using namespace std;
//----------------------------------
// Funktionsdeklarationer.

void skriv_hej();
void laes_in_tal( int & a, int & b );
int  max_av( int a, int b );
void skriv_resultat( int result );

//----------------------------------
// Huvudprogram med variabeldeklaration+funktionsanrop

int main ()
{
  int tal1, tal2, max;

  skriv_hej();
  laes_in_tal( tal1, tal2 );  
  max = max_av( tal1, tal2 );
  skriv_resultat( max );

  return 0;
}
//----------------------------------
//----------------------------------
// Funktionsdefinitioner
//----------------------------------
void skriv_hej()
{
  cout << "Hej och välkommen till programmet!" << endl;
}
//----------------------------------
void laes_in_tal( int & a , int & b )
{
  cout << "Ge två tal: ";
  cin >> a >> b;
}
//----------------------------------
int  max_av( int a, int b )
{
  cout << "Nu beräknas max av två tal!" << endl;

  if ( a > b ) return a;
  else return b;
}
//----------------------------------
void skriv_resultat( int result )
{
  cout << "Resultatet aer: " << result << endl;
}
//----------------------------------