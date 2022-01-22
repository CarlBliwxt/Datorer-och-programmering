// urvalssortering.cpp
//
// Urvalssortering i stigande ordning.


#include <iostream>
using namespace std;

//-----------------------------------------------------------------------
void urvalssortering( const double v[], int a );       // Urvalssortering.
//-----------------------------------------------------------------------
int main ()
{
  const int max = 100;
  double vektor[max];
  int n;

  cout  << "Hur många tal idag? Max = " << max << endl;
  cin >> n;                      
  cout << "Ge talen!" << endl; 

  int i;

  for ( i = 0; i < n; i++ ) 
    {
      cin >> vektor[ i ];
    }

  urvalssortering( vektor, n );

  cout << "Sorterade tal:" << endl;

  for ( i = 0; i < n; i++ ) 
    {
      cout << i << "  " << vektor[ i ] << endl;
    }

  return 0;
}
//-----------------------------------------------------------------------
void urvalssortering( const double v[], int a )       // Urvalssortering.
{

  for ( int i = 0; i<= a-2; i++ )
     {    
       // Hitta min i delvektorn definierad av
       // index i, i+1, ..., a-1.

       double min = v[ i ];  int minind = i;         // startgissning 

       for ( int j = i+1; j <= a-1; j++ )
	 {
	   if ( v[ j ] < min )                       // ga igenom resten 
	     {                                       // och uppdatera min 
	       min    = v[ j ];                      // samt minind 
	       minind = j;
	     }
	 }

       // Nu har vi min och minind (index för min)!
       // Byt med första elementet i delvektorn, dvs v[i]:
       cout << "Min = " << min << " byts med första = " << v[i] << endl;
 
       v[ minind ] = v[ i ];
       v[ i ] = min;           // min är ju värdet på plats v[ minind ].
     }
}
//-----------------------------------------------------------------------
