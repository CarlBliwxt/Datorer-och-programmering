// minMax.cpp
// L�ser in 10 heltal och avg�r vilket som �r minst resp. st�rst

#include <iostream>
using namespace std;

int main()
{
  int min, max, tal;  // variabel f�r min, max och inl�st tal
  int min_nr, max_nr; // nummerordning f�r min resp max


  min=INT_MAX;    // Initiera min till det st�rsta heltalet
  max=INT_MIN;    // Initiera max till det minsta heltalet

  min_nr=-1;      // Initiera till "knasiga" v�rden
  max_nr=-1;

  // Loopvariabeln i varierar fr�n 1 till 10
  // Variabeln i �r nummerordning f�r talen
  for (int i=1; i<=10; i++)
    {
      cout << "Ge ett tal:";
      cin >> tal;

      //byt v�rde p� max om det inmatade �r st�rre �n max      
      if(tal>max) 
	{ 
	  max=tal;
	  max_nr=i; // uppdatera �ven numret
	}

      //byt v�rde p� min om det inmatade �r mindre �n min      
      if(tal<min) 
	{ 
	  min=tal;
	  min_nr=i;  // uppdatera �ven numret
	}
    }
  
  cout << "min=" << min << " max=" << max << endl;

  // Fundera sj�lva:
  // H�r saknas en l�mplig utskriftssats som kan ge en 
  // utskrift av typen:
  // "Inmatade tal nr 2 var st�rst och inmatade tal nr 5 var minst".

  return 0;
}

//
// Alternativ l�sning: 
//
// L�s in det f�rsta talet f�re loopen och initiera
// min och max till detta f�rsta tal samt initiera
// min_nr och max_nr till ett.
// Loopen m�ste nu justeras att g� bara nio varv.





