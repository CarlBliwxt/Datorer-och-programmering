#include <iostream>
using namespace std;
// max_av_tre_1.cpp
// Funktionsdefinition för "max_av_3"
// a, b, c är formella parametrar

int max_av_3 ( int a, int b, int c )
{
  if ( a > b ) {
    if ( a > c )
      return a;
    else
      return c;
  }
  else {
    if ( b > c )
      return b;
    else
      return c;
  }  
}

int main()
{
  int tal1 = 2, tal2 = 6;    //Det går bra att initiera i deklarationen

  // funktionen anropas med de aktuella parametrarna: tal2,tal1,3
  tal1 = max_av_3(tal2, tal1, 3);

  // Skriv ut värdet av det uträknade
  cout << "tal1 = " << tal1 << endl;

  // funktionen anropas med de aktuella parametrarna:
  //     3, 10, tal1 
  tal2 = max_av_3(3, 5*2, tal1);

  // Skriv ut värdet av det uträknade
  cout << "tal2 = " << tal2 << endl;

  return 0;
}

