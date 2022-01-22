//
// Programmeringsuppgift 5A Klasser
// Skriven av Carl Blixt 
// Ett program som läser in en textrad och analyserar bosktavsfrekvens
// Klasser används istället för vanliga funktioner
//Hanterar fallet med 26 bokstäver A-Z, hanterar ej Å-Ö

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:
const int ANTAL_BOKSTAVER = 26;  //A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP innehåller bokstavsfrekvensen i %
// för fyra språk. TOLK_HJALP[0][0] är frekvensen av
// bokstaven a för engelska.TOLK_HJALP[0][25] är frekvensen av
// bokstaven z för engelska.
// Arrayen är en GLOBAL KONSTANT och skall alltså ej skickas 
// som parameter till den funktion som behöver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, //engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, //franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  //svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, //tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};


//--------------------------------------------------------
// Här kommer klassdeklarationen 
class Text 
{
  private:
    int f_abs[ANTAL_BOKSTAVER]; // Absoluta förekomsten av bokstäverna
    string textin;
    int sum;


    public: 
    Text(); // Default-konstuktur 
    void setText( const string &nyText ); // Sätter input till textin
    bool beraknaHistogramAbs(); // Beräknar absoluta förekomsten
    void skrivHistogramAbs(); // plottar beraknaHistogramAbs 
};

// -------------------------------------------------------
// Huvudprogram:

int main()
{
 // Deklarera variabler
  string text;
  int antal;
  Text minText;  // Ett objekt av typen Text skapas

  // Läs in en rad med text från tangentbordet
  cout <<"Ge en rad med text:" << endl;
  getline(cin,text);
  // Skicka strängen text till objektet minText
  minText.setText(text);

  // Beräkna och skriv ut histogrammet
  antal = minText.beraknaHistogramAbs( );
  minText.skrivHistogramAbs( );

}


// -- Klassimplementationen -- 

// Default-konstruktor
Text::Text() 
{
    textin=""; // Nollställer textin till en tom string
    sum=0;
}

// Medlemsfunktioner

void Text:: setText( const string &nyText )
{
    textin=nyText; // Ansätter nytt värde på textin
}


bool Text::beraknaHistogramAbs()
{
// Variabeldeklaration
int index;

// Nollställning av f genom att göra en for loop 
for (int i = 0; i < ANTAL_BOKSTAVER; i++)
  f_abs[i] = 0;

// Loopa igenom hela strängen, tecken för tecken, lägg på 1 på i efter varje iteration
// där 0 motsvarar A och 26 motsvarar Z
  for (int i = 0; i < (int)textin.length(); i++)
  {
        // Om inmatat tecken är liten bokstav
        if (textin.at(i) >= 'a' && textin.at(i) <= 'z')
        {
           // sätter så index får rätt plats i array beroende på bokstav
            index = textin.at(i) - 'a';
            // uppdatera räknaren på rätt plats
            f_abs[index]++;
            //Uppdaterar det totala antalet bokstäver
            sum++;

        }
        // Om inmatat tecken är storbokstav, gör samma sak som ovan 
        if (textin.at(i) >= 'A' && textin.at(i) <= 'Z')
        {
        
            index = textin.at(i) - 'A';
            // uppdatera räknaren på rätt plats
            f_abs[index]++;
            
            sum++;

        }
  }
        
 
    return sum;
 }
 // Skriver ut den absoluta förekomsten 
void Text:: skrivHistogramAbs()
{

    cout << "Resultatet för bokstäverna A-Z "
         << endl
         << ""
         << endl
         << "Totalt antal bokstäver: " << sum << endl;
    //Skriv ut frekvensen i en tabell
    cout << "\nBokstavsfördelning \n";
    // Loopa som pågår och fyller alla platser i arrayen
    for (int i = 0; i < ANTAL_BOKSTAVER; i++)
    {
        // Konvertera platsen till ett teckenvärde
        char b = char(i + 'A');
        if (f_abs[i] >= 0) // gör detta så länge f
            cout << b << "\t" << f_abs[i] << endl;
    }

}
