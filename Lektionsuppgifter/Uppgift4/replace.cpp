// Filen replace.cpp 
 //////////////////////////////////////////////////
 // Byt alla förekomster av en sträng mot en annan.
 #include <iostream>
 #include <string>
 #include <fstream>
 using namespace std;

 //////////////////////////////////////////////////
 // Funktionen ersatt ersätter alla förekomster
 // av strängen nyckel i in_fil med strängen ny
 // och skriver resultatet i filen ut_fil

 void ersatt( string in_fil, string ut_fil, string nyckel, string ny )
 {
   ifstream fin( in_fil.c_str() );
   ofstream fout( ut_fil.c_str() );
   string rad;
   int pos;
   int lnyckel = nyckel.length();
   int lny     = ny.length();

   // Vi läser filen radvis

   while ( getline( fin, rad ) )
     {
        // för varje rad letar vi efter nyckeln
        pos = rad.find( nyckel );
        while ( pos >= 0 ) // nyckel hittad 
	{
           // byt nyckeln mot ny
	  rad.replace( pos, lnyckel, ny );

  	  // leta efter nyckel igen
  	  pos = rad.find( nyckel, pos+lny );
 	}
        // skriv ut den modifierade raden
        fout << rad << endl;
     }
 }

 int main()
 {
   string sok,  byt;
   cout << "Ange strängen du vill ersätta: ";
   getline( cin, sok );
   cout << "Ange strängen du vill byta till: ";
   getline( cin, byt );
   ersatt("GammalFil.txt","NyFil.txt",sok,byt);
   return 0;
 }