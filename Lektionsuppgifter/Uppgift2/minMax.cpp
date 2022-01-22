// minMax.cpp
// Läser in 10 heltal och avgör vilket som är minst resp. störst

#include <iostream>
using namespace std;

int main()
{
  int min, max, tal;  // variabel för min, max och inläst tal
  int min_nr, max_nr; // nummerordning för min resp max


  min=INT_MAX;    // Initiera min till det största heltalet
  max=INT_MIN;    // Initiera max till det minsta heltalet

  min_nr=-1;      // Initiera till "knasiga" värden
  max_nr=-1;

  // Loopvariabeln i varierar från 1 till 10
  // Variabeln i är nummerordning för talen
  for (int i=1; i<=10; i++)
    {
      cout << "Ge ett tal:";
      cin >> tal;

      //byt värde pÂ max om det inmatade är större än max      
      if(tal>max) 
	{ 
	  max=tal;
	  max_nr=i; // uppdatera även numret
	}

      //byt värde pÂ min om det inmatade är mindre än min      
      if(tal<min) 
	{ 
	  min=tal;
	  min_nr=i;  // uppdatera även numret
	}
    }
  
  cout << "min=" << min << " max=" << max << endl;

  // Fundera själva:
  // Här saknas en lämplig utskriftssats som kan ge en 
  // utskrift av typen:
  // "Inmatade tal nr 2 var störst och inmatade tal nr 5 var minst".

  return 0;
}

//
// Alternativ lösning: 
//
// Läs in det första talet före loopen och initiera
// min och max till detta första tal samt initiera
// min_nr och max_nr till ett.
// Loopen måste nu justeras att gå bara nio varv.





