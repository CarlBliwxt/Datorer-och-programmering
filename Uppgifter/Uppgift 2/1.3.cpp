#include <iostream>
using namespace std;
// Exempel 1.3 Prog.teknik
int main()
{
   // Deklarera variabler:
   char tecken;
   double tal, summa;
   double sum = 0;
   double medel;
   int antal;

   // Ge ledtext. Läs in värden.
   cout << "Ge antalet tal som skall läsas in: ";
  cin >> antal;
  cout << "Ge nu " << antal << " st heltal!" << endl;

  // Kontroll av antalet tal

  if (antal == 0.0)
    cout << "Inga tal har bearbetas";

    else
    {
        cin >> tal;
     sum +=tal;
for (int i = 1; i <= antal; i++) 
 medel = sum/antal;


   cout << "Summan av talen är " << sum 
       << " och medel är " << medel 
       << endl;
    }

 

  return 0;
}
