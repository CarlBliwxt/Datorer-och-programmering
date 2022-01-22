//
// Filen: kvitto.cpp
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
  double sum1 = 0.0, sum2 = 0.0;
  string namn1, namn2;

  // Skapa str�mvariabel, koppla till filen.
  // Kontroll att infilen OK.
  
  ifstream IN( "betalat.txt" );

  if ( IN )
    cout << "L�ser in namn och belopp fr�n filen betalat.txt" << endl;
  else
    {
      cout << "ERROR. Infilen kanske p� annan katalog??" << endl;
      return 0;
    }
      
  // L�s personers namn fr�n infilen. 
  
  getline( IN, namn1 );
  getline( IN, namn2 );

  // L�s namn och belopp fr�n resterande rader i infilen.
  // Ackumulera summor f�r varje person.
  // namn, belopp �r tempor�ra variabler.
  // Anta inga andra namn �r med av misstag!
  // Vi vet ej innan hur m�nga kvitton det var...
 
  double belopp;
  string namn;

  while( IN >> namn >> belopp ) 
    {
      if ( namn == namn1 ) // Dvs namn1 betalat ngt
        sum1 += belopp;
      else if ( namn == namn2 ) //Dvs namn2 betalat ngt
        sum2 += belopp;
    }
  
  // Hur mycket skall var och en betala varandra...
  
  cout << namn1 << " har betalat " << sum1 << " kr totalt." << endl;
  cout << namn2 << " har betalat " << sum2 << " kr totalt." << endl;
  
  if ( sum1 > sum2 )
    cout << "Resultat: " << namn2 << " skall betala " 
         << namn1 << " " << (sum1-sum2)/2.0 << " kr." << endl;
  else
    cout << "Resultat: " << namn1 << " skall betala " 
         << namn2 << " " << (sum2-sum1)/2.0 << " kr." << endl;
  
  return 0;
}
