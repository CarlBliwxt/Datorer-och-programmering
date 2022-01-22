// tvaertom_alt.cpp
// Alternativ läsning, där en lokal array ej används
// i funktionen tvaertom. Då behövs inte heller global konstant.

#include <iostream> 
using namespace std;

void laesin(int size, int heltal[]);    // Funktions-deklaration 
void tvaertom(int size, int heltal[]);  //        - " - 
void skrivut(int n, const int heltal[]);//          "

// Huvudfunktion
int main() 
{  
  const int MAX=10;
  int tal[MAX]; 
  int antal=MAX;

  laesin(antal,tal);   // anv. av funktion 
  tvaertom(antal,tal); // anv. av funktion 

  skrivut(antal,tal); 

  return 0; 
}

// Funktionsdefinition
void laesin(int antal, int heltal[])  
{   
  cout << "Skriv in "<< antal << " heltal: \n"; 

}

// Funktionsdefinition 
void tvaertom(int antal, int heltal[])
{   
  int spara; 

  int varv=antal/2;

  // Om antal = 10
  // Byt plats pÂ elementen i arrayen
  // Varv 1 i loopen: 
  //    spara=heltal[0], heltal[0]=heltal[9], heltal[9]=spara.
  // Varv 2 i loopen: 
  //    spara=heltal[1], heltal[1]=heltal[8], heltal[8]=spara.
  // Varv 3 i loopen: 
  //    spara=heltal[2], heltal[2]=heltal[7], heltal[7]=spara.
  // Varv 4 i loopen: 
  //    spara=heltal[3], heltal[3]=heltal[6], heltal[6]=spara.
  // Sista varvet
  //    spara=heltal[4], heltal[4]=heltal[5], heltal[5]=spara.
  for(int i=0; i<varv; i++)
    {
      spara=heltal[i];
      heltal[i]=heltal[antal-i-1];
      heltal[antal-i-1]=spara;
    }
}

// Skriver ut innehållet i arrayen
// n är antalet tal i arryen
void skrivut(int n, const int heltal[])
{
 // Loopa igenom arrayen och skriv ut innehållet i resp. element
  for(int i=0; i<n; i++) 
    cout << heltal[i] <<  "\n"; 
}






