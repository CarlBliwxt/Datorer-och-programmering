#include <iostream>

using namespace std;
// Exempel 1.3 Prog.teknik
int main()
{
   // Deklarera variabler:
   double tal;
   double sum = 0;
   double medel;
   int antal = 0;

   // Ge ledtext. Läs in värden.
  cout << "Ge tal, avsluta med 0" << endl;
    cin >> tal;

    while (tal > 0 )
    {
        antal++;
        sum = sum + tal;
        tal(antal)
    }
    
  if (antal == 0.0)
    cout << "Inga tal har bearbetas";

    else
    {
        cin >> tal;
     sum +=tal;

for (int i = 1; i <= antal; i++) 
 medel = sum/antal;
   cout << "Summan av talen är " << sum << " och medel är " << medel << endl;
    }

  return 0;
}