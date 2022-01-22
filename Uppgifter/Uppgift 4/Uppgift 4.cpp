#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
 
const int ANTAL_BOKSTAVER = 26;
 
const int antalBokstaever=26;
// Dekl. av funktion som beräknar och skriver ut
// frekvensen av bokstäverna i strängen str
int *  histo(const string &str);
void  skriv_histogram_abs(int* f);
// Anm. Värdeanrop, dvs. void histo(string str);
// också möjligt.
 
int main()
{
    string rad;
    int *f;
  int  summa;

  cout<<"Mata in den ba: ";
  getline(cin,rad);
  
   f = histo(rad);

   skriv_histogram_abs(f);





 
  return 0;
}
 
int * histo(const string &str) 
{
  
  // En array f att lagra frekvensen i
  // Antal platser är lika med antalet olika bokstäver
  
  int f[antalBokstaever];
  int index;
  int sum;
  //Nollställ f:
  for (int i=0; i<antalBokstaever; i++) 
    f[i] = 0;
 
  // Loopa igenom hela strängen, tecken för tecken
  for ( int i=0; i< (int) str.length(); i++)
    {
 
      // Om tecknet är en gemen
      if (str.at(i)>='a' && str.at(i)<='z') 
    { 
          // räkna ut platsen i arrayen
      index = str.at(i) - 'a';
          // uppdatera räknaren på rätt plats 
      f[index]++;
        }
      
      // Om tecknet är en versal
      if (str.at(i)>='A' && str.at(i)<='Z')  
    {
      // räkna ut platsen i arrayen
      index = str.at(i) - 'A'; 
      // uppdatera räknaren på rätt plats
      f[index]++;
        }
    sum+=f[index]; // Beräkna 
    }

    cout << sum << endl;
    struct f;

}


void  skriv_histogram_abs(int* f) 
{
    //Skriv ut frekvensen i en tabell
  cout<<"\nBokstav\tFrekvens\n";
  // Loopa över alla platser i arrayen
  for (int i=0; i<antalBokstaever; i++)
    {
      // Konvertera platsen till ett teckenvärde
      char b = char (i+'A'); 
      if (f) cout << b << "\t" << f <<endl;
    }
}
