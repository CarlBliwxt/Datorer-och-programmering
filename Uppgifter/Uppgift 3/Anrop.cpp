
#include <iostream>
#include <cmath>  
using namespace std;

int main() //main1, första varianten
{
  // Variabler som main behöver (lokala i main)

  double kat1, kat2, hypo; 


  // Ledtext och inläsning av värden på kateter.

  cout << "Ge de två kateterna: ";
  cin  >> kat1 >> kat2;

  // Anropa funktionen och lagra resultatet i variabeln hypo
  // dvs hypo får värdet av funktionen hypotenusa som
  // anropas med de två parametrarna kat1 resp kat2 

  hypo = hypotenusa(kat1, kat2);
 

  // Testa och skriv ut värdet av det uträknade

  if ( hypo >= 0 )
    cout << "Hypotenusan = " << hypo << endl;
  else
    cout << "Felaktigt kateterval gjordes" << endl;

  return 0;
}