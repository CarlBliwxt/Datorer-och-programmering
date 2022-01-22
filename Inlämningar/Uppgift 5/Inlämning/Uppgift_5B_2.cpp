//
// Programmeringsuppgift 5B Klasser
// Skriven av Carl Blixt 
// Ett program som läser in filer och analyserar bosktavsfrekvens mha klasser
// Kan även säga vilket språk filen är troligaste vara 
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
    double f_rel[ANTAL_BOKSTAVER]; // Relativa förekomsten av bokstäverna
    string textin;
    int sum;


    public: 
    // Från uppgift 5A
    Text(); // Default-konstuktur 
    void setText( const string &nyText ); // Sätter input till textin
    bool beraknaHistogramAbs(); // Beräknar absoluta förekomsten
    void skrivHistogramAbs(); // plottar beraknaHistogramAbs 
    //Från uppgift 5B
    void absTillRel(); // Beräknar relativa histogrammet från det absoluta
    void plottaHistogramRel(); // Plottar med symbolen *
    void beraknaHistogram(); // Anrop av berknaHistoABS och absTillrel
    string tolka(); // Jämförning av språk 
    
};
// Funktionsdeklartion
    string namn_pa_fil();
    string inlasning(string filnamn);

// -------------------------------------------------------

// Huvudprogram:

int main()
{
 // Deklarera variabler
  string sprak;
  int antal;
  string rad;
  string fil;
  Text minText;  // Ett objekt av typen Text skapas
  
  fil = namn_pa_fil(); // Läser in  namnet på filen
  rad = inlasning(fil);
  // Skicka strängen text till objektet minText
  minText.setText(rad);

  // Beräkna och skriv ut histogrammet
  minText.beraknaHistogram( );
  sprak = minText.tolka();
  cout << sprak << " är det mest sannolika språket." << endl;
  minText.plottaHistogramRel( );

  
}


// Klassimplementationen

// Default-konstruktor
Text::Text() 
{
    textin=""; // Nollställer textin till en tom string
    sum=0; // Ärsumman av bokstäverna i texten
}

// Medlemsfunktion, läser in texten
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
        // Om inmatat tecken är storbokstav 
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

// Relativa förekomsten av bokstäver 
void Text::absTillRel()
{
// Beräknar den procentuella förekomsten mha en for loop. 
    for ( int i = 0; i < ANTAL_BOKSTAVER; i++ )
	{ 
	     f_rel[i]=100.0*(double)f_abs[i]/sum; // updaterar vektorn med procent istället
	} 

}

void Text:: plottaHistogramRel()
{
    //Variabeldeklaration
    int avrundningstal[ANTAL_BOKSTAVER]; // En avrundingsvektor
    int faktor = 2; //faktor 2
    int antalstjarnor[ANTAL_BOKSTAVER]; // En vektor med antalet stjärnor 
    int temp; 
    string stjarna;

    cout << "Frekvetstabell:" << endl;
    cout << "Bokstav\t Procent" << endl;

    for ( int i = 0; i < ANTAL_BOKSTAVER; i++ )
    {
      stjarna = ""; // Stringen sätt som tom
      

      avrundningstal[i]= int(f_rel[i] + 0.5); // Avrundar till heltal
      antalstjarnor[i]= avrundningstal[i] * faktor; // Multiplicerar med 2, hela vektorn uppdateras

      temp=antalstjarnor[i]; // Det aktuella iterationen lagras som ett värde



      while (temp > 0) 
      {
          stjarna += "*"; // Lägg till en stjärna för varje gång temp > 0. 
          temp=temp-1; // Ta bort 1 frårn varje iteration. 
      }

// Utskrift
    char b = char(i + 'A'); // Lägg en ny char varje iteration osv, för att kunna få en korrekt utskrift

    cout << b << "\t" << fixed << stjarna << endl;

    }
  

}
// Ankallalse av både absoluta och det relativa 
void Text::beraknaHistogram()
{
  Text::beraknaHistogramAbs(); // Beräknar det absoluta
    if (sum > 0) // Om det finns pokstäver genomför absTillRel, annars inte.
    { 
      Text::absTillRel();
    }
}
        
    
// Denna har gjorts om från Uppgift 4B, båda två metoderna fungerar denna är bara korta och mer enkel att förstå
string Text::tolka()
{
// Variabeldeklaration
    double sprak_summa[ANTAL_SPRAK] ={0}; // Nollställning
    string sprak_namn[ANTAL_SPRAK] = {"Engelska", "Franska", "Svenska", "Tyska"}; // De 4 språken
    double min = INT_MAX; // Störta integer som finns i c++ 
    int sannoliktsprak;
    double kvadratskillnad;

// För att få det som utksriften är i Facit, så att det blir rätt ordning  
if (sum == 0)
  {
      cout << "Inga bokstäver givna" << endl;
  }

  else
  {
    // Om någon bokstav har matas in genomför else. 
    cout << "Resultatet för bokstäverna A-Z "
         << endl
         << ""
         << endl 
         << "Totalt antal bokstäver: " << sum << endl;
  
   
    for (int i = 0; i < ANTAL_SPRAK; i++) // For loop som håller på tills alla språk har behandlas
    {
        for (int j = 0; j < ANTAL_BOKSTAVER; j++)
        {
          kvadratskillnad = TOLK_HJALP[i][j]- f_rel[j]; // Utför samma sak som tidigare metod men nu görs allt här istället för att ha 4 stycken olika deklarationer
          sprak_summa[i] += kvadratskillnad*kvadratskillnad;
        
        }

          if (sprak_summa[i] > min) // Detta är alltid sant för första iterationen
          {
            min = sprak_summa[i]; // Sätt nyaste språk summan till minet,
            sannoliktsprak = i; // Uppdatera position
            // Upprepa iteration, kontrollera om den minskar 
          }

    cout << sprak_namn[i] << " har kvadratsumma = " << sprak_summa[i] << endl; // Utskrift
    }
  }
return sprak_namn[sannoliktsprak];
}

//--------------------------------------------------------
// Funktionsdefinitioner:
// Tar filnamn och kontrollerar om dom har .txt om inte lägg till
string namn_pa_fil()
{
  string filnamn;
  cout << "Ange filnamn: ";
  getline( cin, filnamn);

  if (filnamn.rfind(".txt") != string::npos) // Alltså om .txt finns gör inget, annars gå till else
  {
  }
  else // om .txt inte finns i filnamn, lägg till det och returnerar filnamn;
  {
    filnamn += ".txt";
  }
return  filnamn;
}
string inlasning(string filnamn)
{
  ifstream fin( filnamn.c_str()); // Inläsning av fil
  char c;
  string fil_innehall;

  if ( !fin )  // Kontroll om filen finns 
    {
      cout << "Filen "<< filnamn << " kunde inte hittas vänligen försök igen"
           << endl;
      exit( EXIT_FAILURE );
    }

  
  while ( fin.get(c) ) // Inläsning char för char för att kunna få ut fil innhållet, 
    {
    c;
    fil_innehall +=c; // Lägger till en varje iteration, fortsätter tills filen är slut
    
    }

  return fil_innehall;
}