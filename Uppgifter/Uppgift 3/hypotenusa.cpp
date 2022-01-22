// hypotenusa.cpp
#include <iostream>
#include <cmath>  
using namespace std;
       
// "cmath" behövs för att sqrt(), 
// dvs inbyggda funktionen "roten ur" skall fungera
//----------------------------------------------------------------------
// Här definieras en funktion med namnet hypotenusa:
// Den har 2 st parametrar (argument) som vi anger inom parentesen:
//    formellt kallar vi dem för kat1 resp kat2 och anger även
//    vilken datatyp (double) de skall vara

// Den har en returtyp (double) som vi skriver före funktionens namn
// 

double hypotenusa ( double kat1, double kat2 )
{
  // en lokal variabel hypo deklareras inne i funktionen
  // (lokala variabler existerar bara i funktionen, dör sedan.)
  // variabeln används till att lagra värdet av det som beräknas 

  double hypo;

  if ( kat1 > 0 && kat2 > 0 )   // testa om parametrarna är OK
    {
      // beräkna och lagra värdet
      hypo = sqrt(kat1*kat1 + kat2*kat2);
      return hypo;       //  returnera värdet av hypo (double)
    }
  else
    return(-1.0);  // Om det blir fel, dvs någon sida är mindre än eller
                   // lika med noll returneras ett negativ värde.
}  // slut på funktionsdefinitionen

// main1.cpp
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