// tvaertom.cpp
#include <iostream> 
using namespace std;

const int MAX=10; // En global konstant

void laesin(int n, int heltal[]);   // Funktions-deklaration 
void tvaertom(int n, int heltal[]); //        "
void skrivut(int n, const int heltal[]);   //       "

// Huvudfunktion
int main() 
{   
  int tal[MAX];  // arrayen
  int antal=MAX;     // aktuellt antal tal i arrayen

  laesin(antal,tal);   // skicka ett heltal och arrayen till funktionen 
  tvaertom(antal,tal); //       "

  skrivut(antal,tal);  //       "

  return 0; 
}

// L�ser in v�rdena i arrayen
// n �r antalet tal som skall l�sas in
void laesin(int n, int heltal[])  
{   
  cout << "Skriv in " <<  n << " heltal: " << "\n"; 

  for(int i=0; i<n; i++) 
    cin >> heltal[i];  // L�s in element f�r element
}

// V�nder om v�rdena i arrayen
// n �r antalet tal i arryen
void tvaertom(int n, int heltal[])
{   
  int temp[MAX]; // beh�ver en lokal tempor�r array med fix storlek
  // Kan ej deklarera:
  // int temp[n];  
  // eftersom n �r en variabel

  // kopiera bakl�nges fr�n heltal till temp
  // Om n=10:
  // dvs temp[0]=heltal[9], temp[1]=heltal[8], etc
  for(int i=0; i<n; i++)
    temp[n-1-i]=heltal[i];

  // kopiera fr�n arrayen temp till heltal
  // dvs heltal[0]=temp[0], heltal[1]=temp[1], etc
  for(int i=0; i<n; i++) // kopiera temp till heltal
    heltal[i]=temp[i];

  // Kan du komma p� ett s�tt som v�nder om v�rden i arrayn
  // utan ett helt array temp?
}

// Skriver ut inneh�llet i arrayen
// n �r antalet tal i arryen
void skrivut(int n, const int heltal[]) // OBS! const
{
 // Loopa igenom arrayen och skriv ut inneh�llet i resp. element
  for(int i=0; i<n; i++) 
    cout << heltal[i] <<  "\n"; 
}