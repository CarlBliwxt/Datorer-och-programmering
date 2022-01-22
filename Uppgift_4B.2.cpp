//
// Programskal till inlämningsuppgift 4 - deluppgift B
// Skriven av Carl Blixt 
// Hanterar fallet med 26 bokstäver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

// Tips: Använd de globala konstanterna ANTAL_BOKSTAVER och ANTAL_SPRAK 
// istället för värdena 26 och 4 i programmet.
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


// Funktionsdeklarationer:
int berakna_histo_abs(double f[], const string &str);
void abs_till_rel(double f[], int sum);
void plotta_histogram(double f[], int sum);
void tolka(double f[], int sum);
string namn_pa_fil();
string inlasning(string filnamn); 
//--------------------------------------------------------

// Huvudprogram:
int main()
{
  // Variabeldeklaration
    string rad;
    string fil;
    double f[ANTAL_BOKSTAVER];  
    int sum;
    
    fil=namn_pa_fil(); //Lagrar namnet på filen, i variabelnfil
    rad= inlasning(fil); // Läser in filen och lagrar texten i rad
    
    sum = berakna_histo_abs(f, rad);  // Tar ut summan uppdaterar f
    abs_till_rel(f,sum);
    tolka(f, sum);
    plotta_histogram(f,sum);
    

  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:

//Uppdaterar arrayen f så att gemer blir till versaler samt beräknar totala förekomsten av bokstäver. 
int berakna_histo_abs(double f[], const string &str)
{

// Variabeldeklaration
int index;
int sum=0;

// Nollställning av f genom att göra en for loop 
for (int i = 0; i < ANTAL_BOKSTAVER; i++)
f[i] = 0;

// Loopa igenom hela strängen, tecken för tecken, lägg på 1 på i efter varje iteration
// där 0 motsvarar A och 26 motsvarar Z
  for (int i = 0; i < (int)str.length(); i++)
  {

        // Om inmatat tecken är liten bokstav
        if (str.at(i) >= 'a' && str.at(i) <= 'z')
        {
           // sätter så index får rätt plats i array beroende på bokstav
            index = str.at(i) - 'a'; 

            // uppdatera räknaren på rätt plats
            f[index]++;
            //Uppdaterar det totala antalet bokstäver
            sum++;

        }
        // Om inmatat tecken är storbokstav, utför samma iteration som ovan
        if (str.at(i) >= 'A' && str.at(i) <= 'Z')
        {
        
            index = str.at(i) - 'A';
            f[index]++;
            
            sum++; 
        }
  }
        
 
    return sum;
 }


void abs_till_rel(double f[], int sum)
{
    
// Beräknar den procentuella förekomsten mha en for loop. 
    for ( int i = 0; i < ANTAL_BOKSTAVER; i++ )
	{ 
	     f[i]=100.0*f[i]/sum; // updaterar vektorn med procent istället. 
	} 

}

// Funktion som plottar histogrammet där en stjärna är lika med en procent, avrundning har använts. 
void plotta_histogram(double f[], int sum)
{
  if (sum == 0)
  {
      cout << "Inga bokstäver givna" << endl;
  }

  else
  {
    // Om någon bokstav har matas in genomför else. 
    
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
      

      avrundningstal[i]= int(f[i] + 0.5); // Avrundar till heltal
      antalstjarnor[i]= avrundningstal[i] * faktor; // Multiplicerar med 2, hela vektorn uppdateras

      temp=antalstjarnor[i]; // Det aktuella iterationen lagras som ett värde



      while (temp > 0) 
      {
          stjarna += "*"; // Lägg till en stjärna för varje gång temp > 0. 
          temp=temp-1; // Ta bort 1 frårn varje iteration. 
      }

// Utskrift
    char b = char(i + 'A');

    cout << b << "\t" << fixed << stjarna << endl;

    }
  }

}
// Funktionen bestämmer vilket språk som är mest troligt genom att beräkna kvadratskillnaden mellan angivna text
// och TOLK_HJALP. 
void tolka(double f[], int sum)
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
  
   
    for (int i =0; i < ANTAL_SPRAK; i++) // For loop som håller på tills alla språk har behandlas
    {
        for (int j=0; j<ANTAL_BOKSTAVER; j++)
        {
          kvadratskillnad = TOLK_HJALP[i][j]- f[j]; // Utför samma sak som tidigare metod men nu görs allt här istället för att ha 4 stycken olika deklarationer
          sprak_summa[i] += kvadratskillnad*kvadratskillnad; // Ändrad så att allt blir kortare 
        
        }

          if (sprak_summa[i] > min) // Detta är alltid sant för första iterationen
          {
            min = sprak_summa[i]; // Sätt nyaste språk summan till minet,
            sannoliktsprak = i; // Uppdatera position
            // Upprepa iteration, kontrollera om den minskar 
          }

    cout << sprak_namn[i] << " har kvadratsumma = " << sprak_summa[i] << endl;
    }
  }
cout << "Det mest sannolikaspråket" << sprak_namn[sannoliktsprak] << endl;
}


string namn_pa_fil()
{
  string filnamn;
  cout << "Ange filnamn: ";
  getline( cin, filnamn);

  if (filnamn.rfind(".txt") != string::npos) // kontrollerar om det finns .txt i filen
{
  }
  else // Om .txt inte finns i filen läggs .txt på stringen filnamn. 
  {
    filnamn += ".txt";
  }
return  filnamn;
}

string inlasning(string filnamn)
{
  ifstream fin( filnamn.c_str() ); 
  char c;
  string fil_innehall;

  if ( !fin ) 
    {
      cout << "Filen "<< filnamn << " kunde inte hittas vänligen försök igen"
           << endl;
      exit( EXIT_FAILURE );
    }

  
  while ( fin.get(c) ) // Inläsning av fil 
    {
    c; // default char
    fil_innehall +=c; // Lägg till hela en till char 
    
    }

  return fil_innehall;
}

