// skivbutik.cpp
#include <iostream> 
using namespace std;

int main() 
{   
  const int pris = 0, antal = 1; 
  int skiva;
  // En 2D-array:
  // När första index är noll så betyder elementens värde CDn's pris
  //   skivarray[0][0] innehåller alltså priset för den första skivan
  // När första index är ett så betyder elementens värde antalet CD
  //   skivarray[1][0] innehåller alltså antalet exemplar av första skivan
  int skivarray[2][10]; 
  int lagervaerde = 0; 

  for(skiva=0; skiva<10; skiva++) 
  { 
    cout << "Pris skiva nummer: "<< skiva << ": "; 
    cin >> skivarray[pris][skiva]; 
    cout << "Antal skivor: "; 
    cin >> skivarray[antal][skiva]; 
  }

  for(skiva=0; skiva<10; skiva++) 
    lagervaerde += skivarray[pris][skiva] * skivarray[antal][skiva]; 

  cout << "Lagervärdet är: "<< lagervaerde; 
  return 0; 
}