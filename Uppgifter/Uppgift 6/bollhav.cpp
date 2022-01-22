#include <iostream>
#include <cmath>
using namespace std;

// bollhav.cpp
// Simuleringa av ett tvådimensionellt
// bollhav, dvs små platta bollar
// finns ett kvadratiskt område
// (en kvadratmeter). 
// Bollarna rör sig slumpmässigt.

//--------------------------cirkel--- 
const double pi = M_PI;

class cirkel 
{
private:
  double x, y;                       //position
  double radie;                      // storlek

public:
  cirkel();                          
  cirkel(double r);                  
  cirkel(double xp, double yp, double r);
  double R();              // returnera radie
  void lasin();            // läs in attributen
  void skrivut();          // skriv ut atttributen
  double hamtax();         // returnera x
  double hamtay();         // returnera y
  void flytta(double dx, 
              double dy);    // flytta cirkeln
  void skala(double faktor); // skala cirkelns storlek
  double omkrets();          // beräkna cirkelns omkrets
  double yta();              // beräkna cirkelns yta
  int krock( cirkel annan ); // kolla om krock med annan
  cirkel ihop( cirkel & annan );   // smält ihop två cirklar...
};
//------------------------bollhav-----

const int MAX = 40; // Max 100 bollar.

class bollhav
{
private:
  cirkel bollar[MAX];    // bollar i bollhav
  int antal;             // antal bollar

public:
  bollhav(); // Standard konstruktor.
             // Slumpa ut bollar i rummet.
  bollhav( int antboll, double radie ); 
  void flytta();    // Flytta slumpmässigt
  void skrivut();   // Skriv info om bollar
  int utanfoer();   // Antal bollar utanför?
  void krock();  // Krockar bollar?
};


//-- Testa det hela---

int main() 
{
  // Initiera "slumptalsgeneratorn".

  long froe = long( time(NULL) );
  srand48( froe );
  
  // Deklarera bollhav och testa lite:

  //  bollhav MacDonalds( 25, 0.05 );
  bollhav MacDonalds( 10, 0.15 );
  MacDonalds.skrivut();
  MacDonalds.flytta();
  MacDonalds.krock();
  int antutan = MacDonalds.utanfoer();

  cout << "Dumma ungar, nu är " << antutan 
       << " st bollar utanför bollhavsområdet!!!" 
       << endl;
  MacDonalds.skrivut();

 return 0;
}
//---------------------------------------------
// Standardkonstruktorn, skapar en cirkel med
// radien 1 i origo.

cirkel::cirkel() 
{ 
  x = y = 0.0; 
  radie = 1.0;
}
//---------------------------------------------------------------
// Skapar en cirkel med radien r i origo.

cirkel::cirkel( double r ) 
{ 
  x = y = 0.0; 
  radie = r;
}
//---------------------------------------------------------------
// Skapar en cirkel enligt order.

cirkel::cirkel( double xp, double yp, double r ) 
{ 
  x = xp; 
  y = yp; 
  radie = r;
}
//---------------------------------------------------------------
// Läser in cirkelns attribut från tangentbordet.

void cirkel::lasin() 
{ 
  cout << "Ge position och radie: ";
  cin >> x >> y >> radie;
}
//---------------------------------------------------------------
// Skriver ut cirkelns egenskaper.

void cirkel::skrivut() 
{
  cout << "Cirkeln ligger i position " << x << " " << y
       << " med radien " << radie << endl;
}
//--------------------------------------------------------------
// Returnera x
double cirkel:: hamtax()
{
  return x;
}
//--------------------------------------------------------------
// Returnera y
double cirkel:: hamtay()
{
  return y;
}
//---------------------------------------------------------------
// Returnera radien.

double cirkel:: R()
{
  return radie;
}
//---------------------------------------------------------------
// Flyttar cirkeln angiven sträcka
// i x- och y-led.

void cirkel::flytta( double dx, double dy ) 
{
  x += dx;
  y += dy;
}
//---------------------------------------------------------------
// Skala cirkelns radie angiven faktor,
// dvs förminska eller förstora.

void cirkel::skala( double faktor ) 
{
  radie *= faktor;
}
//---------------------------------------------------------------
// Beräkna och returnera cirkelns omkrets.

double cirkel::omkrets() 
{
  return 2*radie*pi;
}
//---------------------------------------------------------------
// Beräkna och returnera cirkelns yta.

double cirkel::yta() 
{
  return pi*radie*radie;
}

//---------------------------------------------------------------
// Två specialare bara för att visa att man 
// kan returnera objekt och att man kan ha 
// lokala objekt (deklarerade i en metod). 

int cirkel:: krock( cirkel  annan )
// Kolla om aktuella objektet krockar med annan.
{
  if ( sqrt( (x - annan.x)*(x - annan.x) +
	     (y - annan.y)*(y - annan.y) ) <=
       radie + annan.radie )
    return 1; //"true"
  else
    return 0; //"false"
}

cirkel cirkel:: ihop( cirkel & annan )  
  // Smält ihop två cirklar.
  // Låt oss ta medelvärden av attributen till 
  // den nya cirkeln.
  // Egentligen borde de gamla cirklarna 
  // försvinna efter sammanslagningen;
  // vi löser det med att deras radier blir noll.
  // Eftersom "annan" ändrar värde, så måste den
  // vara referensparameter.

{
  cirkel c;  // temporär cirkel som vi bygger 
             // upp attribut för attribut
             // och sedan returnerar

  c.x = 0.5*(x + annan.x);
  c.y = 0.5*(y + annan.y);
  c.radie = 0.5*(radie + annan.radie);

  radie = 0;
  // kräver att "annan" är  referensparameter
  annan.radie = 0; 

  return c;
}

//-------------------bollhav-------
// Skapa ett bollhav som är tomt
// på bollar.

bollhav:: bollhav()
:antal(0)
  // Autom anropas cirkeklassens
  // standardkonstruktor MAX ggr.
{}
//-------------------------------------------------
// Skapa ett bollhav genom att slumpmässigt 
// placera dem i enhetskvadraten.

bollhav:: bollhav ( int antboll, double radie )
: antal(antboll)
{
  for ( int i = 0; i < antal; i++ )
    {
      bollar[i] = cirkel( drand48(), drand48(), radie );
    }
}
//-------------------------------------------------
// Flytta alla små bollar i bollhavet lite 
// slumpmässigt i x- och y-led. Simulerar att barn 
// hoppar i bollhavet:
// x = x + dx, dx = tecken1*radie*slumptal,
// y = y + dy, dy = tecken2*radie*slumptal,
// där dx och dy är 
// små tal och tecken1, tecken2 
// anger bollens riktning i x- och y-led,
// dvs positivt eller negativt hopp. . 
// För att få tecken, så tar vi ett slumptal
// igen och om det är mindre än 0.5, så
// blir det "minus", om det är större 
// än eller lika med 0.5 blir det "plus".
// Hur stora avstånd bollarna kan hoppa
// beror även på deras radie. 


void bollhav:: flytta()
{
  double dx, dy;
  int tecken1, tecken2;
  double radie;

  for ( int i = 0; i < antal; i++ )
    {
      // Åt vilket håll?

      if ( drand48() < 0.5 )
	tecken1 = -1;
      else 
	tecken1 = 1;

      if ( drand48() < 0.5 )
	tecken2 = -1;
      else 
	tecken2 = 1;

      // Radie hos boll nr "i":
      radie = bollar[i].R();

      // Hur mycket skall boll nr "i" flyttas?

      dx = drand48()*radie*tecken1;
      dy = drand48()*radie*tecken2;

      // Själva flyttningen:
      bollar[i].flytta( dx, dy );
    }
}
//-------------------------------------------------
// Skriv ut info om alla bollarna.

void bollhav:: skrivut()
{
  cout << "Antal bollar i bollhavet = " 
       << antal << endl;

  for ( int i = 0; i < antal; i++ )
    bollar[i].skrivut();
}
//-------------------------------------------------
// Räkna antal bollar som hamnat utanför bollhavet,
// dvs utanför enhetskvadraten.

int bollhav:: utanfoer()
{
  //Antag ingen boll utanför rutan [0,1]x[0,1] först.

  int utan = 0; 

  for ( int i = 0; i < antal; i++ )
    {
      if ( bollar[i].hamtax() < 0.0 ||
           bollar[i].hamtax() > 1.0 ||
           bollar[i].hamtay() < 0.0 ||
           bollar[i].hamtay() > 1.0 )
        utan++;
    }
  return utan;
}
//-------------------------------------------------
// Om två bollar krockar skriv ut det.
// Egentligen kan man bygga vidare här på
// ngt vettigt sätt...

void bollhav:: krock()
{
  // Kolla om alla bollar krockar med alla
  // andra utom sig själva...
  // Kanske inte så bra metod, men
  // vi vill illustrera hur objekt 
  // i samma klass kan samverka.

  for ( int i = 0; i < antal; i++ )
    {
      for ( int j = i+1; j < antal; j++ )
        {
	  // Testutskrift för att se att vi kollar 
          // om alla krockar med alla enbart en gång, dvs
	  // t.ex. om bollar[0] krockar med bollar[2]
	  // så vill vi ej kolla 
	  // om bollar[2] krockar med bollar[0] också.
	  // Vill ej kolla krock med sig själv heller.
	  // Därför börjar j-loopen vid i+1.

	  //	  cout << " i och j  " << i << " " 
          //           << j << endl;
	  
	  if ( bollar[i].krock( bollar[j] ) )
	    {
	          cout << "Krock " << i << " " << j << endl;
            }
        }
    }
}

/* Körningsexempel:
Antal bollar i bollhavet = 10
Cirkeln ligger i position 0.457019 0.0817211 med radien 0.15
Cirkeln ligger i position 0.629911 0.679146 med radien 0.15
Cirkeln ligger i position 0.630906 0.0472351 med radien 0.15
Cirkeln ligger i position 0.988206 0.0279785 med radien 0.15
Cirkeln ligger i position 0.901221 0.970399 med radien 0.15
Cirkeln ligger i position 0.0501205 0.893273 med radien 0.15
Cirkeln ligger i position 0.481016 0.617818 med radien 0.15
Cirkeln ligger i position 0.0500591 0.796019 med radien 0.15
Cirkeln ligger i position 0.833715 0.0887616 med radien 0.15
Cirkeln ligger i position 0.319892 0.855343 med radien 0.15
Krock 0 2
Krock 1 6
Krock 2 3
Krock 2 8
Krock 3 8
Krock 5 7
Dumma ungar, nu är 4 st bollar utanför bollhavsområdet!!!
Antal bollar i bollhavet = 10
Cirkeln ligger i position 0.546748 -0.0131854 med radien 0.15
Cirkeln ligger i position 0.524011 0.532737 med radien 0.15
Cirkeln ligger i position 0.728764 0.0550331 med radien 0.15
Cirkeln ligger i position 0.877011 0.0329369 med radien 0.15
Cirkeln ligger i position 0.978918 1.05933 med radien 0.15
Cirkeln ligger i position -0.0778384 0.844929 med radien 0.15
Cirkeln ligger i position 0.519031 0.47908 med radien 0.15
Cirkeln ligger i position -0.0551472 0.942515 med radien 0.15
Cirkeln ligger i position 0.79597 0.191667 med radien 0.15
Cirkeln ligger i position 0.320938 0.79592 med radien 0.15
*/
