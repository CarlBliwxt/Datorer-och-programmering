//-------------------------------------------
// pekare_array.cpp

#include <iostream>
#include <string>
using namespace std;

// SWAP
// Byter värden på två tal.
//
// In : Två pekare, a och b, till int.
// Ut : Två pekare, a och b, till int.
//
void swap( int *a, int *b)
{
  int slask = *a;
  *a = *b;
  *b = slask;
}

// MIN
// Söker pekaren till det minsta talet i en array.
//
// In : Två parametrar. 
//      a - en pekare till det aktuella fältet
//      n - antal element som finns i fältet
// Ut : Pekare till minsta elementet
int *min( int *a, int n )
{
  int i;
  int *val = a;       // minsta talet hittills
  for (i=1; i<n; i++) // undersök övriga element
    {                 
      if ( *(a+i) < *val) // nytt min?
        {
          val = a+i;  // spara minsta talet
        }
    }
  return val;         // returnera minsta talet
}


// URVALSSORTERING
// Sorterar ett heltalsfält i stigande ordning, 
// enligt urvalssorterings algoritmen:
//   1. Sök minsta värdet i fältet
//   2. Byt plats på det minsta och första värdet.
//   3. Upprepa 1. och 2. tills fältet är sorterat
//
// In : Två parametrar.
//      a - en pekare till det aktuella fältet
//      n - antal element som finns i fältet
// Ut : Ett sorterat fält.
void urvals_sortering( int *a, int n)
{
  int *val;               // pekare till minsta talet
  for (int i=0; i<n; i++) // för alla element
    {
      val = min(a+i, n-i);// sök minsta talet
      swap( a+i, val );   // byt plats
    }
}

// BINÄR SÖKNING:
// Söker efter ett tal i ett sorterat fält (array),
// genom att rekursivt halvera sökfältet.
//
// IN: Tre parametrar
//     sokt    - det sökta talet
//     *forsta - pekare till fältets första element
//     *sista  - pekare till fältets sista element
// UT: Pekare till det element i fältet där det sökta
//     talet finns
//
int *bin_sok(int sokt, int *forsta, int *sista)
{
  if ( forsta > sista ) // fältet saknar element
    {
      return 0;         // Null-pointer
    }
  // låt pekaren mitten peka på elementet som ligger i mitten
  int *mitten = forsta + (sista-forsta)/2;
  if ( sokt < *mitten ) // ligger sokt i vänstra halvan?
    {
      // rekursivt anrop med vänstra halvan
      return bin_sok( sokt, forsta, mitten-1 );
    }
  else if ( sokt > *mitten ) // ligger sokt i högra halvan?
    {
      // rekursivt anrop med högra halvan
      return bin_sok( sokt, mitten+1, sista );
    }
  else                  // vi har hittat sokt och
    return mitten;      // returnerar pekaren till sokt
}

// HUVUDPROGRAM
// Skapar och läser in tal till ett dynamiskt fält.
// Sorterar fältet i växande storleksordning.
// Söker efter ett tal i fältet mha binär sökning.
// Skriver ut resultatet.
int main()
{
  int storlek;              // storlek på dynamiska fältet
  cout << "Ge storlek : ";  
  cin >> storlek;           
  int *array;               // pekare till int deklareras
  array = new int[storlek]; // allokera minne för array

  int i;
  for (i=0; i<storlek; i++) // läs in element till array
    {
      cout << "Ge tal nr " << i+1 << " : ";
      cin >> array[i];
    }

  // sortera vår array mha urvals sortering
  urvals_sortering( array, storlek ); 

  cout << "Sorterad array: ";
  for (i=0; i<storlek; i++)
    {
      cout << array[i] << " ";
    }
  cout << endl;

  int nyckel;               // sökta nyckeln
  cout << "Ge nyckel : ";
  cin >> nyckel;

  int *p;                   // pekare till int
  // Sök efter nyckel i array mha binär sökning
  p = bin_sok( nyckel, array, array+(storlek-1) );

  if ( p != 0 )             // Nyckel funnen
    {
      cout << "Nyckel hittades!" << endl;
      cout << endl;
      cout << "Nyckel : " << *p << endl;
      cout << "Plats  : " << p-array << endl;
      cout << "Minne  : " << p << endl;
    }
  else                      // Null-pointer
    {
      cout << "Nyckeln fanns inte i arrayen" << endl;
    }

  delete[] array;           // avallokera minne för array
  return 0;
}

/* 
 * Körexempel:
 *   $ CC pekare_array.cc
 *   $ a.out
 *   Ge storlek : 7
 *   Ge tal nr 1 : 9
 *   Ge tal nr 2 : 4
 *   Ge tal nr 3 : 7
 *   Ge tal nr 4 : 2
 *   Ge tal nr 5 : 0
 *   Ge tal nr 6 : -3
 *   Ge tal nr 7 : 1
 *   Sorterad array: -3 0 1 2 4 7 9 
 *   Ge nyckel : 4
 *   Nyckel hittades!
 *   
 *   Nyckel : 4
 *   Plats  : 4
 *   Minne  : 63438
 *   $
 */ 
