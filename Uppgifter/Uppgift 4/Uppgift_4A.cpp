/*
Programmeringsuppgift 4A Strängar och Arrayer 
Skriven av Carl Blixt 
Ett program som läser in filer och analyserar bosktavsfrekvens
Kan även säga vilket språk filen är troligaste vara 
Hanterar fallet med 26 bokstäver A-Z, hanterar ej Å-Ö
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

//Global konstant
const int ANTAL_BOKSTAVER = 26; // 26 Bokstäver A-Z

//Funktionsdeklarationer

int berakna_histo_abs(int f[], const string &str); 
void skriv_histogram_abs(int f[], int sum);

int main()
{
    //Definerar variabler 
    string rad;
    int f[ANTAL_BOKSTAVER];
    int sum; 

    // Inläsning från tagentbordet get mha av getline. 
    cout << "Ge en rad med text ";
    getline(cin, rad);

    sum = berakna_histo_abs(f, rad); // Lagrar summan från funktionen

    skriv_histogram_abs(f, sum); // Funktion som printar. 

    return 0;
}

int berakna_histo_abs(int f[], const string &str)
{

    // Variabeldeklaration
    int index;
    int sum=0;
    // Nollställning av f genom att göra en for loop 
    for (int i = 0; i < ANTAL_BOKSTAVER; i++)
    {
        f[i] = 0;
    }

    // Loopa igenom hela strängen, tecken för tecken, lägg på 1 på i efter varje iteration
    // där 0 motsvarar A och 26 motsvarar Z (lånad från övningsuppgift host)
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
        // Om inmatat tecken är storbokstav 
        if (str.at(i) >= 'A' && str.at(i) <= 'Z')
        {
        
            index = str.at(i) - 'A';
            // uppdatera räknaren på rätt plats
            f[index]++;
            
            sum++;

        }
    }

    return sum;
 }

void skriv_histogram_abs(int f[], int sum)
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
        if (f[i] >= 0)
            cout << b << "\t" << f[i] << endl;
    }
}
 