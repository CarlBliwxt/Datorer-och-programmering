// 2dimfunk.cpp
// Exempel p� 2D-array (tabell) som parametrar i funktion
// Programmet l�ser in en tabell med v�rden, 
// skriver sedan ut tabellen och r�knar ut summan
// av v�rdena i tabellen.

#include <iostream>
using namespace std;

const int MAX1 = 10;
const int MAX2 = 20;

double summa( const double tabell[MAX1][MAX2], int n1, int n2 );
void lasin( double tabell[MAX1][MAX2], int &n1, int &n2 );
void skriv( const double tabell[MAX1][MAX2], int n1, int n2 );

// Anm: OK att skippa 1:a index om man vill...
// double summa( const double tabell[][MAX2], int n1, int n2 );
// men enklast ha med b�da.

int main()
{
  double tal[MAX1][MAX2]; // En 2D-array
  int dim1, dim2;

  lasin( tal, dim1, dim2 ); // L�s in v�rden och lagra i arrayen
  skriv( tal, dim1, dim2 ); // Skriv ut v�rdena
  // Skriv ut summan av v�rdena
  cout << "Summan �r: " 
       << summa( tal, dim1, dim2 ) << endl;

  return 0;
}

void lasin( double tabell[MAX1][MAX2], int &n1, int &n2 )
  // L�ser in tabell med v�rden
{
  cout << "Ge antal rader och kolonner i tabellen: ";
  cin >> n1 >> n2;

  // Antag att anv�ndaren ger n1<=MAX1 och n2<=MAX2.

  for ( int i = 0; i < n1; i++ )
    {
      cout << "Ge rad nummer " << i << " : ";
      
      for ( int j = 0; j < n2; j++ )
	cin >> tabell[i][j];
    }
  cout << endl;
}

double summa( const double tabell[MAX1][MAX2], int n1, int n2 )
  // Ber�knar summan av tabellens v�rden
{
  double sum = 0.0;
  
  for ( int i = 0; i < n1; i++ )
    for ( int j = 0; j < n2; j++ )
      sum += tabell[i][j];

  return sum;
}

void skriv( const double tabell[MAX1][MAX2], int n1, int n2 )
  // Skriver ut tabellen med värden
{
  for ( int i = 0; i < n1; i++ )
    {
      cout << "Rad: " << i << ": ";

      for ( int j = 0; j < n2; j++ )
	cout << tabell[i][j] << "\t";
      cout << endl;
    }
}

/*
K�rexempel:

Ge antal rader och kolonner i tabellen: 4 3
Ge rad nummer 0 : 1 2 3
Ge rad nummer 1 : 4 5 6
Ge rad nummer 2 : 1 2 1
Ge rad nummer 3 : 4 5 6

Rad: 0: 1       2       3       
Rad: 1: 4       5       6       
Rad: 2: 1       2       1       
Rad: 3: 4       5       6       
Summan �r: 40
*/
