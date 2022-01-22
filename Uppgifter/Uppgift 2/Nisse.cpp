#include <iostream>
using namespace std;

int main ()
{
  int tal, sum, antal;
  double medel;

  //Med for-loop...................................

  cout << "Ge antalet tal som skall läsas in: ";
  cin >> antal;
  cout << "Ge nu " << antal << " st heltal!" << endl;

  sum = 0;             //OBS! Kom ihåg att nollställa sum!

  for ( int i = 1; i <= antal; i++ )
    {
      cin >> tal;
      sum += tal;      //Lägg tal till summan "sum".
    }

  medel = double( sum )/antal;

  cout << "Summan av talen är " << sum 
       << " och medel är " << medel 
       << endl;

  return 0;
}