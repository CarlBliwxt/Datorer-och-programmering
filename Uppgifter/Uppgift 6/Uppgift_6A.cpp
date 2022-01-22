/*
Datorer och programmering: Inlänminingsuppgift 6 - Alpresan
Delluppgift A, En statisk version
Skriven av Carl Blixt 
Ett program som bestämmer vem som ska betala när man har många transaktioner
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Globala konstanter
const int MAX_PERSONER = 10;
const int MAX_TRANSAKTIONER = 30;
// -- Klass deklarationer -- 

// En klass som lagrar vädret och kan hantera enskilda kvitoon
class Transaktion
{
 private: 
   string datum;
   string typ;
   string namn;
   double belopp;
   int    antal_kompisar;
   string kompisar[MAX_PERSONER];

 public:
   Transaktion();  // Konstuktor
   ~Transaktion(); // Destruktor
   string hamtaNamn(); // Hämtar namnet som en string
   double hamtaBelopp(); // Hämtar beloppet från textfiilen
   int    hamtaAntalKompisar(); // Hur många deltar
   bool   finnsKompis(const string &namnet); // Kontroll om en kompis finn eller inte
   bool   lasIn(istream &is); // Läser in från txtfil
   void   skrivUt(ostream &os); // Skriver ut data 
   void   skrivTitel(ostream &os); // 
   void   skrivHjalp(ostream &os); // Skriver hur man gör en input Tillagd (Finns ej i uppgiftsbeskrivningen)
   
}; 

// Lagrar sammanslagna transaktiondata som har deltagit i sammanhanget. 
class Person
{
  private: 
  string namn;
   double betalat_andras; // ligger ute med totalt
   double skyldig;        // skyldig totalt

 public:
   Person(); // Konstuktor
   Person(const string &namn, double betalat_andras, double skyldig); // Överlagrad konstruktur
   string hamtaNamn();
   double hamtaBetalat();
   double hamtaSkyldig();
   void skrivUt(ostream &os); // Utskrift
};
// Hanterar och håller ordningen på unika personer är med i sammanhanget, en lista
class PersonLista
 {
 private:
   int    antal_personer;
   Person personer[MAX_PERSONER];

 public:
   PersonLista(); // Konstrukor
   ~PersonLista(); // destruktor
   void   laggTill(Person ny_person);
   void   skrivUtOchFixa(ostream &os); // Använder sig av skrivUt, och ordnar dom 
   double summaSkyldig(); // Använder sig av hamtaSkyldig, för att få hur mycket personen är skyldig
   double summaBetalat(); // Hur mycket varje person har betalat 
   bool   finnsPerson(const string &namn); 
 }; 

// Helhets bild håller ordning på allt och gör en lista av det. 
 class TransaktionsLista
 {
 private:
   int         antal_transaktioner;
   Transaktion transaktioner[MAX_TRANSAKTIONER];
   Transaktion kompisar[MAX_PERSONER];

 public:
   TransaktionsLista(); // Konstruktor 
   ~TransaktionsLista(); // Destruktor
   void   lasIn(istream & is);
   void   skrivUt(ostream & os);
   void   laggTill(Transaktion & t); // Lägger till en transaktion i slutet av en array
   double totalKostnad();
   double liggerUteMed(const string &namnet); //Beräknar hur mycket man har betalat
   double arSkyldig(const string &namnet); // Beräknar hur mycket man är skyldig 
   PersonLista FixaPersoner();

 }; 


// -- Ankallelse av Main - Huvudprogram -- 
 int main ()
 {
  cout << "Startar med att läsa från en fil." << endl;

  TransaktionsLista transaktioner;
  std::ifstream     is("resa.txt");
  transaktioner.lasIn(is);

  int operation = 1;
  while (operation != 0)
    {
      cout << endl;
      cout << "Välj i menyn nedan:" << endl;
      cout << "0. Avsluta. Alla transaktioner sparas på fil." << endl;
      cout << "1. Skriv ut information om alla transaktioner." << endl;
      cout << "2. Läs in en transaktion från tangentbordet." << endl;
      cout << "3. Beräkna totala kostnaden." << endl;
      cout << "4. Hur mycket ärr en viss person skyldig?" << endl;
      cout << "5. Hur mycket ligger en viss person ute med?" << endl;
      cout << "6. Lista alla personer mm och FIXA" << endl;

      cin >> operation;
      cout << endl;

      switch (operation)
        {
          case 1:
            {
              Transaktion transaktion;
              transaktion.skrivTitel(cout);
              transaktioner.skrivUt(cout);
              break;
            }
          case 2:
            {
              Transaktion transaktion;
              cout << "Ange transaktion i följande format" << endl;
              transaktion.skrivHjalp(cout);
              transaktion.lasIn(cin);
              transaktioner.laggTill(transaktion);
              break;
            }
          case 3:
            {
              cout << "Den totala kostnanden för resan var "
                   << transaktioner.totalKostnad() << endl;
              break;
            }
          case 4:
            {
              cout << "Ange personen: ";
              string namn;
              cin >> namn;
              double ar_skyldig = transaktioner.arSkyldig(namn);
              if (ar_skyldig == 0.)
                cout << "Kan inte hitta personen " << namn << endl;
              else
                cout << namn << " är skyldig " << ar_skyldig << endl;
              break;
            }
          case 5:
            {
              cout << "Ange personen: ";
              string namn;
              cin >> namn;
              double ligger_ute_med = transaktioner.liggerUteMed(namn);
              if (ligger_ute_med == 0.)
                cout << "Kan inte hitta personen " << namn << endl;
              else
                cout << namn << " ligger ute med " << ligger_ute_med << endl;
              break;
            }
          case 6:
            {
              cout << "Nu skapar vi en personarray och reder ut det hela!" << endl;
              PersonLista lista = transaktioner.FixaPersoner();
              lista.skrivUtOchFixa(cout);
              break;
            }
        }
    }

  std::ofstream os("transaktioner.txt");
  transaktioner.skrivUt(os);

  return 0;
}
// -----------------------------------------------------
// Klassdefinitioner 

 // -- Transaktion -- : 

//Konstruktur
Transaktion::Transaktion() 
{
 //Nollstälning av befinitliga variabler
  namn="";
  datum="";
  typ="";
  belopp = 0.0;
  antal_kompisar = 0;
  {
    for (int i= 0; i < MAX_PERSONER; i++) // Nollställning av vektorn 
    kompisar[i];
  }
}
// Destruktor
 Transaktion::~Transaktion() 
 {

 }

// Selektorer
// Som hämtar information om befintliga variabler
string Transaktion::hamtaNamn()
{
  return namn;
}

double Transaktion::hamtaBelopp()
{
  return belopp;
}

int Transaktion::hamtaAntalKompisar()
{
  return antal_kompisar;


}

// Kontrollerar om kompisen finns 
bool Transaktion::finnsKompis(const string &namnet)
{   

  for (int i= 0; i < antal_kompisar ; i++) // for loop som går igenom antal kompisar
  {
    if(kompisar[i] == namnet) // Kollar varje element om string kompisar = string namnet
    {
      return true;
  } 
  }
return false;

}



// Läser data om en transaktion, ankallas av while loop 
bool Transaktion::lasIn(istream &is)
{
  // Inläsning
 is >> datum >> typ >> namn >> belopp >> antal_kompisar;

 for (int i=0; i < antal_kompisar; i++) // För att läsa in varje kompis, görs en for loop
 {
   is >> kompisar[i]; // Storar varje namn i is genom användning av for loopen
 }
 return !is.eof();
}

// Skriver ut alla data om klassen. 
void Transaktion::skrivUt(ostream &os)
{
  
 os << datum << "\t" << typ << "\t" << namn << "\t" << belopp << "\t" << antal_kompisar << "\t";
  for (int i =0; i < MAX_PERSONER; i++)
  {
    os << "\t" << kompisar[i] ;
    }
  os << endl ;
}
// Skriver titeln som beskriver kolumnen. 
void Transaktion::skrivTitel(ostream &os)
{
  os << "Datum" << "\t" << "Typ" << "\t" << "Namn" << "\t" << "Belopp" << "\t" << "Antal och lista av kompisar" << "\t" << endl;
  // Skrev om main, tror tillropet var felaktigt för att få till det alternativ 1. 
}

// Förklara hur man sak ska skriva in en ny transaktion från tagentbordet.
void Transaktion::skrivHjalp(ostream &os)
{
  os << "Datum (yymmdd) typ av transaktion namn belopp antal och lista på kompisar " << endl;
}


//   -- Person --  : 

// Kostruktur
Person::Person()
{
  namn =""; // Nollställning
  betalat_andras=0.0;
  skyldig = 0.0;
}
// Överlagrad konstuktur
Person::Person(const string &namn, double betalat_andras, double skyldig)
{
  this -> namn =namn ; // Använder pekare hittade inget annat sätt när man har samma variabelnamn som input
  this -> betalat_andras = betalat_andras;
  this -> skyldig  = skyldig;
}

// Selektorer
// Tar ut information
string Person::hamtaNamn()
{
  return namn;
}

double Person::hamtaBetalat()
{
    return betalat_andras;
}

double Person::hamtaSkyldig()
{
  return skyldig;
}

// Skriver ut hur mycket personen har betalat, hur mycket man är skyldig och och mycket pengar man ska få alternativt betala
void Person::skrivUt(ostream &os)
{
cout << namn << " ligger ute med: " << betalat_andras << " kr och är skyldig " << skyldig << " kr. ";
  if (skyldig < betalat_andras)
  {
    cout << "Skall ha " << ( betalat_andras - skyldig ) << " kr från potten!" << endl;
  }
  else
  {
  cout << "Skall lägga till " << ( skyldig - betalat_andras ) <<" kr till potten!"<< endl;
  }
}

// -- PersonLista -- : 

// Konstruktor, nollstälning
PersonLista::PersonLista()
{
  antal_personer = 0;
  {
     for (int i= 0; i < MAX_PERSONER; i++)
     personer[i];
   }
}
// Destruktur
PersonLista::~PersonLista() 
{

}
// Läger till i arrayen personer efter den sista personen
void PersonLista::laggTill(Person ny_person)
{
  personer[antal_personer] = ny_person; // Sista delen av arrayen läggs nyperson in

  antal_personer++; // Addera till antalperson
}

// Skriver ut informationen om varje personobjekt i arrayen
void PersonLista::skrivUtOchFixa(ostream &os)
{
    for(int i = 0; i < antal_personer; i++)
    {
        personer[i].skrivUt(os);
    }

}

// Hämtar summan som personen är skyldig. 
double PersonLista::summaSkyldig()
{
 double skyldig = 0.0; // Nollställning av skyldig

  for (int i = 0; i < antal_personer; i++)
  {
    skyldig = skyldig + personer[i].hamtaSkyldig(); // Hämtar hur mycket en viss person är skyldig
  }
  return skyldig;
}

// Summan av allt en person har betalat
double PersonLista::summaBetalat()
{
  double betalat_andras= 0.0;

  for (int i = 0; i < antal_personer; i++ )
  {
    betalat_andras = betalat_andras + personer[i].hamtaBetalat();
  }

  return betalat_andras;
}

// Kontroll om givna namn finns
bool PersonLista:: finnsPerson(const string &namn)
{
  for(int i = 0; i < MAX_PERSONER; i++)
  {
    if (personer[i].hamtaNamn() == namn)
    { 
      return true;
    }
  }
  return false;
  
}

//  -- TransaktionsLista -- : 

// Konstuktor
TransaktionsLista::TransaktionsLista()
{
  antal_transaktioner = 0;
}
// Destruktor
TransaktionsLista::~TransaktionsLista()
{

}
// Inläsning från fil till klassen transaktion
 void TransaktionsLista::lasIn(istream & is)
 {
  // En inläsningsmetod i klassen TransaktionsLista.
  Transaktion t;
  
  // Så länge det går bra att läsa (filen ej slut)
  while (t.lasIn(is))        
   {
     laggTill( t );
   }

 }
// Skriver ut med hjälp av skrivUt från Transaktion
 void TransaktionsLista::skrivUt(ostream & os)
 {
   for(int i= 0; i < antal_transaktioner; i++)
   {
     transaktioner[i].skrivUt(os);
   }
 cout << "Antal transaktioner är: " << antal_transaktioner << endl;
 }
// Lägger till en transaktion i slutet på arrayen
 void TransaktionsLista::laggTill(Transaktion & t)
 {
  transaktioner[antal_transaktioner] = t; // tar längst bak i arrayen
  antal_transaktioner++; 
 }

// Beräknar den totala kostanden genom att returna alla utgifter
double TransaktionsLista::totalKostnad()
{
  double totalKostnad = 0.0; // Nollställning

  for(int i = 0; i < antal  _transaktioner; i++)
  {
    totalKostnad += transaktioner[i].hamtaBelopp();
  }
  return totalKostnad;
}

// Hur mycket en person har betalat (hur mycket pengar dom ligger ute med) tagen från Studium
double TransaktionsLista::liggerUteMed(const string &namnet)
{ 
 double summa = 0.0;

   for (int i = 0; i < antal_transaktioner; i++)

     if (transaktioner[i].hamtaNamn() == namnet)

       summa += transaktioner[i].hamtaBelopp() *
                (1.0 - 1.0 / (transaktioner[i].hamtaAntalKompisar() + 1));
   return summa;
 }
// Hur mycket en person är skyldig 
double TransaktionsLista::arSkyldig(const string &namnet)
{
  double skuld = 0.0;
    
    for(int i = 0; i < antal_transaktioner; i++) // for loop för varje iteration
    {
        if (transaktioner[i].finnsKompis(namnet)) // kontrollerar om namnet ingår finns mha finnsKompisar
        skuld += (transaktioner[i].hamtaBelopp()/(transaktioner[i].hamtaAntalKompisar() + 1)); 
        // Tar belopp/(antal personer + 1) på för att se hur mycket varje enskild person e skyldig
    }
    return skuld;
}

// Skapar och returnerar ett objekt, går igenom transaktionslistan, används för printen. 
PersonLista TransaktionsLista::FixaPersoner()
{
  PersonLista Personlista;
  string namn;
  
     for(int i = 0; i < MAX_TRANSAKTIONER; i++)
    {
        namn = transaktioner[i].hamtaNamn(); // hämtning av namn

        if(!Personlista.finnsPerson(namn)) // Kontroll av namn 
        {
            Person pers(namn, liggerUteMed(namn), arSkyldig(namn)); // Ankallar respektive funktiopn

            Personlista.laggTill(pers); // lägger till en ny person, börjar om iteration
        }

    }
    return Personlista;
}