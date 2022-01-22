#include <iostream>
using namespace std;



int mindre_an(const double[], int antal, double specialtal);

int main()
{
    const int max=10;
    double vektor[max];
    int n ,antal;
    int i =0;
    double specialtal;
    
    cout << "Hur många många tal, max är 10" ;
    cin >> n;

    cout << n << " st reela tal efter varandra" ;
    while (i < n)
    {
    cin >> vektor(i);
    i++;
    }


    cout << "Ange ett extra tal" ;
    cin >> specialtal;
    
    antal=mindre_an(vektor,n,specialtal);

    cout <<antal <<endl;

    return 0;

    
}

int mindre_an(const double[], int antal, double specialtal)
{
int sum=0;
for ( int i = 0; i < antal; i++ )
    {
      if ( x[ i ] < specialtal )
	sum++;
    }

  return sum;
}

