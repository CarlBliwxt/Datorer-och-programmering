#include <iostream>
using namespace std;

void write_date ( string text, int d = 31, int m = 12, int y = 2021 );

int main()
{
  cout << "Test av en datumfunktion: " << endl;

  write_date( "Dagens datum, 2:a november 2021", 2, 11 );
  write_date( "Sista dagen på året" ); 
  write_date( "Sista december, 2010", 2010);
  write_date( "Första dagen nästa år", 1, 1, 2022 );  
  write_date( "Julafton i år", 24 );  
  return 0;
}

void write_date ( string text, int d, int m, int y )
{
  // Funktion som skriver ut en text och ett datum på formen 2021-06-27.
  // Specialbehandlar om d < 10 eller m < 10 för att få ut nollan
  // före själva siffran i månaden eller dagen.
  
  const int noll = 0;

  // Skriv ut år.
  cout << text << ": " << y << "-";

  // Skriv ut månad.
  if ( m < 10 ) 
    cout << noll;
  cout << m << "-";

  // Skriv ut dag.
  if ( d < 10 ) 
    cout << noll;
  cout << d << endl;
}