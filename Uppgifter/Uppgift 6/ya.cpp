/*===============================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar 19
Inlämningsuppgift nr 6 A
Namn: Katarina Käll
Personummer:
Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
Jag har använt kompilator/editor (namn/version) Code Blocks 17.12
Jag har använt följande dator (t.ex. PC, Mac, Annat):        PC
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : Windows 10
Jag har arbetat ungefär  15 timmar med denna uppgift
================================================================================
*/
#include <iostream>
#include <fstream>

using namespace std;

// Globala konstanter:
const int MAX_PERSONER = 10;
const int MAX_TRANSAKTIONER = 30;

// -------------------------------------------------------
class Person
 {
 private:
   string namn;
   double betalat_andras;   // ligger ute med totalt
   double skyldig;          // skyldig totalt

 public:
   Person();
   Person( string n, double b, double s );
   string haemta_namn();
   double haemta_betalat();
   double haemta_skyldig();
   void skrivUt();
};
//-------------------------------------------------------
class PersonLista
 {
 private:
   int antal_pers;
   Person pers[MAX_PERSONER];

 public:
   PersonLista();
   ~PersonLista();
   void laggTillEn( Person pny );
   void skrivUtOchFixa();
   double summaSkyldig();
   double summaBetalat();
   bool finnsPerson(const string& namn);
 };
//--------------------------------------------------------
 class Transaktion
 {
  private:
   string datum;
   string typ;
   string namn;
   double belopp;
   int ant_kompisar;
   string kompisar[MAX_PERSONER];

  public:
   Transaktion();
   ~Transaktion();
   string haemta_namn();
   double haemta_belopp();
   int haemta_ant_kompisar();
   bool finnsKompis( string namnet );
   bool laesEnTrans( istream &is );
   void skrivEnTrans( ostream &os );
 };
 // -------------------------------------------------------
class TransaktionsLista
{
 private:
   Transaktion trans[MAX_TRANSAKTIONER];
   int antalTrans;

 public:
   TransaktionsLista();
   ~TransaktionsLista();
   void laesin( istream & is );
   void skrivut( ostream & os );
   void laggTill( Transaktion & t );
   double totalkostnad();
   double liggerUteMed( string namnet );
   double aerSkyldig( string namnet );
   PersonLista FixaPersoner();
 };
//-------------------------------------------------------
void ritaMeny();
//-------------------------------------------------------
int main()
{
    int menyVal;
    string namn;

    Transaktion trans;
    TransaktionsLista transList;
    PersonLista persList;

    ifstream fin("resa.txt");
    ofstream fout("resultat.txt");

    transList.laesin(fin); //Läs in data från infilen

    while(menyVal != 0)
        {
            ritaMeny();
            cin >> menyVal;

            switch(menyVal)
            {
                case 0:
                    transList.skrivut(fout);
                    break;
                case 1:
                    cout << "Skriv in en transaktion enligt foljande monster:" << endl;
                    cout <<  "datum(yymmdd) typ namn belopp antal lista pa kompisar";
                    trans.laesEnTrans(cin);
                    break;
                case 2:
                    transList.skrivut(cout);
                    break;
                case 3:
                    cout << "Total kostnad: " << transList.totalkostnad() << endl;
                    break;
                case 4:
                    cout << "Skriv in namn: " << endl;
                    cin >> namn;
                    cout << namn << " ar skyldig " << transList.aerSkyldig(namn) << endl;
                    break;
                case 5:
                    cout << "Skriv in namn: " << endl;
                    cin >> namn;
                    cout << namn << " ligger ute med: " << transList.liggerUteMed(namn) << endl;
                    break;
                case 6:
                    persList = transList.FixaPersoner();
                    persList.skrivUtOchFixa();
                    break;
            }
        }

    return 0;
}
// -------------------------------------------------------
// Klassimplementationen

Transaktion::Transaktion()
{
    datum = "";
    typ = "";
    namn = "";
    belopp = 0.0;
    ant_kompisar = 0;
}

Transaktion::~Transaktion()
{

}

string Transaktion::haemta_namn()
{
    return namn;
}

double Transaktion::haemta_belopp()
{
    return belopp;
}

int Transaktion::haemta_ant_kompisar()
{
    return ant_kompisar;
}

bool Transaktion::finnsKompis(string namnet)
{
    bool finns = false;

    if (namnet.at(0)>='a' && namnet.at(0)<='z') // Kontrollerar om det sökta namnet börjar på en gemen och om så är fallet ändrar den till en versal.
    {
        char ch = namnet.at(0) - 32;
        std::string s(1, ch);
        namnet.replace(0, 1, s);
    }

    for(int i = 0; i < MAX_PERSONER; i++)
    {
        int pos = kompisar[i].find(namnet);
        if(pos != string::npos)
        {
            finns = true;
        }
    }
    return finns;
}

bool Transaktion::laesEnTrans(istream &is)
{
 is >> datum >> typ >> namn >> belopp >> ant_kompisar;

 string temp; // Skapar en temporär variabel 

 for (int i=0; i < ant_kompisar; i++)
 {
   is >> temp;
   if (is.eof()) 
   return false;
   kompisar[i] = temp;
 }
 return !is.eof();

}

void Transaktion::skrivEnTrans(ostream &os)
{
    os << datum << "\t" << typ << "\t" << namn << "\t" << belopp << "\t" << ant_kompisar << "\t";
    for(int i = 0; i < MAX_PERSONER; i++)
    {
        os << kompisar[i] << "\t";
    }

}
TransaktionsLista::TransaktionsLista()
{
    antalTrans = 0;
}

TransaktionsLista::~TransaktionsLista()
{

}

void TransaktionsLista::laesin(istream &is)
{
    Transaktion t;

    while(t.laesEnTrans(is))
    {
        laggTill(t);
    }
}

void TransaktionsLista::skrivut(ostream &os)
{
    cout << "Antal trans: " << antalTrans << endl;
		for(int i = 0; i < antalTrans; i++)
		{
			trans[i].skrivEnTrans(os);
		}
}

void TransaktionsLista::laggTill(Transaktion &t)
{
    trans[antalTrans] = t;
    antalTrans++;
}

double TransaktionsLista::totalkostnad()
{
    double totalkostnad = 0.0;

    for(int i = 0; i < antalTrans; i++)
    {
        totalkostnad += trans[i].haemta_belopp();
    }

    return totalkostnad;
}

double TransaktionsLista::liggerUteMed(string namnet)
{
    double liggerUteMed = 0.0;

    for(int i = 0; i < antalTrans; i++)
    {
        if(trans[i].haemta_namn().find(namnet) != string::npos)
        {
            liggerUteMed += (trans[i].haemta_belopp()-(trans[i].haemta_belopp()/
                            (trans[i].haemta_ant_kompisar() + 1)));
        }
    }

    return liggerUteMed;
}

double TransaktionsLista::aerSkyldig(string namnet)
{
    double skuld = 0.0;

    for(int i = 0; i < antalTrans; i++)
    {
        if(trans[i].finnsKompis(namnet))
        {
            skuld += (trans[i].haemta_belopp()/(trans[i].haemta_ant_kompisar() + 1));
        }
    }
    return skuld;
}

PersonLista TransaktionsLista::FixaPersoner()
{
    PersonLista personList;
    string namn;
    double tillbaka = 0.0;
    double skuld = 0.0;

    for(int i = 0; i<MAX_TRANSAKTIONER; i++)
    {
        namn = trans[i].haemta_namn();
        if(!personList.finnsPerson(namn))
        {
            tillbaka = liggerUteMed(namn);
            skuld = aerSkyldig(namn);

            Person pers(namn, tillbaka, skuld);
            personList.laggTillEn(pers);
        }
    }

    return personList;
}
// -------------------------------------------------------
Person::Person()
{
    namn = "";
    betalat_andras = 0.0;
    skyldig = 0.0;
}

Person::Person(string n, double b, double s)
{
    namn = n;
    betalat_andras = b;
    skyldig = s;
}

string Person::haemta_namn()
{
    return namn;
}

double Person::haemta_betalat()
{
    return betalat_andras;
}

double Person::haemta_skyldig()
{
    return skyldig;
}

void Person::skrivUt()
{
    cout << namn << " ligger ute med: " << betalat_andras <<" och ar skyldig " << skyldig ;
    if(skyldig < betalat_andras)
    {
        cout << ". Ska ha " << betalat_andras - skyldig << " fran potten!" << endl;
    }
    else
    {
        cout << ". Ska lagga " << skyldig - betalat_andras << " till potten!" << endl;
    }
}
// -------------------------------------------------------
PersonLista::PersonLista()
{
    antal_pers = 0;
}

PersonLista::~PersonLista()
{

}

void PersonLista::laggTillEn(Person pny)
{
    pers[antal_pers] = pny;
    antal_pers++;
}

void PersonLista::skrivUtOchFixa()
{
    cout << "Nu skapar vi en personarray och reder ut det hela!" << endl;
    for(int i = 0; i < antal_pers; i++)
    {
        pers[i].skrivUt();
    }
    summaSkyldig() == summaBetalat();
}

double PersonLista::summaSkyldig()
{
    double skyldig = 0.0;

    for(int i = 0; i < antal_pers; i++)
    {
        skyldig += pers[i].haemta_skyldig();
    }

    return skyldig;
}

double PersonLista::summaBetalat()
{
    double betalat = 0.0;

    for(int i = 0; i < antal_pers; i++)
    {
        betalat += pers[i].haemta_betalat();
    }

    return betalat;
}

bool PersonLista::finnsPerson(const string &namn)
{
    bool finns = false;

    for(int i = 0; i < MAX_PERSONER; i++)
    {
        int pos = pers[i].haemta_namn().find(namn);
        if(pos != string::npos)
        {
            finns = true;
        }
    }
    return finns;
}
// -------------------------------------------------------
// Funktionsdefinitioner:
void ritaMeny()
{
    cout << "Valj i menyn nedan:" << endl;
    cout << "0. Avsluta. Alla transaktioner sparas pa fil." << endl;
    cout << "1. Las in en transaktion fran tangentbordet." << endl;
    cout << "2. Skriv ut information om alla transaktioner." << endl;
    cout << "3. Berakna totala kostnaden." << endl;
    cout << "4. Hur mycket ar en viss person skyldig?" << endl;
    cout << "5. Hur mycket ligger en viss person ute med?" << endl;
    cout << "6. Lista alla personer mm och FIXA!" << endl << endl;
}