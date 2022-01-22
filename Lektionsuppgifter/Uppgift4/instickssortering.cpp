// instickssortering.cpp
#include <iostream>
using namespace std;
// instickssorteringen

// Stick in v[a] i sorterade arrayen v[0]..v[a-1].
// Arrayen v[0]..v[a] kommer vara sorterad efter anropet.
void stickIn( double v[], int a);

// Instickssortera v
void insticksSortera( double v[], int n);

//-----------------------------------------------------------------------

int main ()
{
  const int max = 100;
  double vektor[max];
  int n;

  cout  << "Hur många? ";
  cin >> n;                      //index 0, 1, ..., n-1!

  // stoppa in ett tal i taget i arrayen
  int i;

  for ( i = 0; i < n; i++ )
    { 
      cout << "Ge tal nr " << i << " så stoppar jag in i arrayen" 
	   << endl;
      cin >> vektor[i];
    }
  
  insticksSortera( vektor, n );

  // Skriv ut sorterade vektorn!

  for ( i = 0; i < n; i++ ) 
    cout << i << "  " << vektor[ i ] << endl;

  return 0;
}

//-----------------------------------------------
// Stick in v[a] i sorterade arrayen v[0]..v[a-1].
// Arrayen v[0]..v[a] kommer vara sorterad efter anropet.
void stickIn( double v[], int a)
{
  int index;
  double ny = v[a];
  // Leta bakifrån efter den plats som det nya talet ska in på.
  // Så länge man inte funnit det ska elementen flyttas ett steg åt höger.
  for (index=a; (index>0) && (v[index-1]>ny); index--)
    {
      v[index] = v[index-1];
    }

  // Stoppa in det nya talet
  v[index] = ny;
}

// Instickssortera v
void insticksSortera( double v[], int n)
{
  // Loopen kan börja på 1, eftersom arrayen med ett element
  // redan är sorterad
  for(int i=1; i<n; i++)
    stickIn(v,i);
}
