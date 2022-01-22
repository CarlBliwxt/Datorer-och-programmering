#include <iostream>
using namespace std; 

char LasTecken(); // Deklaration av funktion 

int main() 
{ 
  char svar; 
  svar = LasTecken(); 
  cout << "Svaret = " << svar << endl; 
  return 0; 
} 

char LasTecken() // Definition av funktion 
{ 
  char tecken; 
  char t1='A'; // Godkända tecken 
  char t2='B'; 
  char t3='C'; 

  cout << "Ge ett tecken " << t1 << " , " << t2 << " eller " 
       << t3 << " : " << endl; 
  cin >> tecken; 

  // Så länge som fel tecken 
  while ( ! ( (tecken==t1) || (tecken==t2) || (tecken==t3) ) ) 
    { 
      cout << "Fel tecken! " << endl; 
      cout << "Ge ett tecken " << t1 << " , " << t2 << " eller " 
	   << t3 << " : " << endl; 
      cin >> tecken; 
    } 
  return tecken; 
}
                   