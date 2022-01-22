//
// Programskal till inl�mningsuppgift 4 - deluppgift B
//
// Hanterar fallet med 26 bokst�ver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
#include <array>
using namespace std;

// Globala konstanter:

// Tips: Anv�nd de globala konstanterna ANTAL_BOKSTAVER och ANTAL_SPRAK
// ist�llet f�r v�rdena 26 och 4 i programmet.
const int ANTAL_BOKSTAVER = 26; //A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP inneh�ller bokstavsfrekvensen i %
// f�r fyra spr�k. TOLK_HJALP[0][0] �r frekvensen av
// bokstaven a f�r engelska. TOLK_HJALP[0][25] �r frekvensen av
// bokstaven z f�r engelska.
// Arrayen �r en GLOBAL KONSTANT och skall allts� ej skickas
// som parameter till den funktion som beh�ver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER] =
    {{8.27, 1.48, 2.94, 4.03, 11.78, 2.22, 1.72, 6.77, //engelska
      7.39, 0.12, 0.81, 3.76, 2.85, 6.71, 7.79, 1.54,
      0.05, 5.95, 6.69, 9.07, 2.66, 1.13, 2.14, 0.19,
      1.89, 0.03},
     {7.97, 1.40, 3.55, 3.79, 16.89, 1.02, 1.00, 0.75, //franska
      7.08, 0.38, 0.04, 5.51, 2.82, 8.11, 5.19, 2.78,
      1.01, 6.69, 8.35, 7.22, 6.09, 1.35, 0.02, 0.54,
      0.30, 0.15},
     {9.50, 1.11, 1.53, 5.30, 8.94, 1.74, 3.57, 3.94, //svenska
      3.98, 0.89, 3.26, 4.93, 3.41, 8.46, 5.01, 1.77,
      0.00, 6.73, 5.56, 9.20, 1.94, 2.42, 0.00, 0.05,
      0.45, 0.00},
     {5.12, 1.95, 3.57, 5.07, 16.87, 1.35, 3.00, 5.79, //tyska
      8.63, 0.19, 1.14, 3.68, 3.12, 10.64, 1.74, 0.42,
      0.01, 6.30, 6.99, 5.19, 3.92, 0.77, 1.79, 0.01,
      0.69, 1.24}};

// Globala variabler �r ej till�tna

//--------------------------------------------------------
// Funktionsdeklarationer:

// Deklarationer av dina egna funktioner
// Anv�nd exakt de funktionsnamn som finns nedan

// Funktionen berakna_histogram_abs
// denna skrevs i A-uppgiften och kan klippas in h�r
int berakna_histogram_abs(double alfapet[], string &text);

// Funktionen abs_till_rel -- Absoluta till relativa värden i histogrammet - aka
void abs_till_rel(double alfapet[], int sum);

// Funktionen plotta_histogram_rel
void plotta_histogram_rel(double alfapet[], int sum);

// Funktionen tolkning
void tolkning(double alfapet[], int sum);

string namn_pa_fil();
string inlasning(string filnamn); 

//--------------------------------------------------------
// Huvudprogram:

int main()
{
  int sum;
  string text;
  string fil;
  double alfapet[ANTAL_BOKSTAVER] = {};
  fil = namn_pa_fil();
  text = inlasning(fil);

  sum = berakna_histogram_abs(alfapet, text);

  
  abs_till_rel(alfapet, sum);

  plotta_histogram_rel(alfapet, sum);
  
  tolkning(alfapet, sum);

  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:
int berakna_histogram_abs(double alfapet[], string &str)
{
  int temp, sum = 0; //Variabler

  for (int k = 0; k < str.length(); k++) //Loopar igenom varje char i stringen
  {

    if (str.at(k) > 96 && str.at(k) < 123) //Små bokstäver
    {
      temp = str.at(k) - 97; //Lagrar plasen för bokstaven i en temp variabel, 97 är ASCII värdet för a
      alfapet[temp]++;       //Lägger till 1 på platsen i arrayen för char
      sum++;                 //Sum räknar totala antalet bokstäver
    }

    if (str.at(k) > 64 && str.at(k) < 91) //Stora bokstäver
    {
      temp = str.at(k) - 65;
      alfapet[temp]++;
      sum++;
    }
  }
  return sum;
}

void abs_till_rel(double alfapet[], int sum)
{
  cout << "Hello world" << endl;
  cout << sum << endl;

  for (int k = 0; k < ANTAL_BOKSTAVER; k++)
  {
    alfapet[k] = (alfapet[k] / sum) * 100.0;
  }
}

void plotta_histogram_rel(double alfapet[], int sum)
{
  cout << "Körning av plotter" << endl;

  if (sum > 0)
  {
    cout << "Något har skrivits in" << endl;
    string stjarnor_array[ANTAL_BOKSTAVER] = {};
    string stjarna = "";

    for (int p = 0; p < ANTAL_BOKSTAVER; p++)
    {
      for (int q = 0; q < alfapet[p]; q++)
      {
        stjarna += "*";
      }
      stjarnor_array[p] = stjarna;
      stjarna = "";
    }

    for (int i = 0; i < ANTAL_BOKSTAVER; i++)
    {
      char letters = char(i + 65); //Konverterar platserna i arrayen till stora bokstäver A-Z
      cout << letters << "\t " << stjarnor_array[i] << endl;
    }
  }

  else
  {
    cout << "Inget har skrivits in" << endl;
  }
}

void tolkning(double alfapet[], int sum)
{
  //Variabeldefinitioner
  double kvadratskillnad = 0;
  double kvadratsumma[ANTAL_SPRAK] = {0};
  string sprak[ANTAL_SPRAK] = {"Engelska", "Franska", "Svenska", "Tyska"};
  double temp = 3000000.0;
  string mest_sann;

  cout << "Tolkning sker" << endl;

  if (sum > 0)
  {
    for (int i = 0; i < ANTAL_SPRAK; i++)
    {
      for (int a = 0; a < ANTAL_BOKSTAVER; a++)
      {
        kvadratskillnad = TOLK_HJALP[i][a] - alfapet[a];
        kvadratsumma[i] += (kvadratskillnad * kvadratskillnad);
      }

      if(kvadratsumma[i] < temp) {
        temp = kvadratsumma[i];
        mest_sann = sprak[i];

      }
    }

    cout << "Kvadratsummorna för de olika språken" << endl;

    for(int e = 0; e < ANTAL_SPRAK; e++) {

      cout << sprak[e] << "\t" << kvadratsumma[e] << endl;
    }

    cout << "Det mest sannolika språket är: " << mest_sann << endl;
  }

  else
  {
    cout << "Tolkning omöjlig då inga bokstäver skrivits in" << endl;
  }
}

// -------------------------------------------------------
// Rapport om uppgiften
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

