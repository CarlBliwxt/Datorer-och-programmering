// *****************************************
// Uppgift 2, styrande satser
// Syfte: Att hantera data för tävlande i en idrottstävling
// Skriven av Carl Blixt


#include <iostream>
using namespace std;

int main()
{
   // Definerar variabler, nollställer antalet 
   int Startnummer, antal=0, Vinnare;
   int mintimme, minminut, minsekund; 
   int Start_timme, Start_minut, Start_sekund, Mal_timme, Mal_minut, Mal_sekund;
   int slut_sek, slut_min, slut_timme, slut_tid;

   int min=INT_MAX; // Största möjliga värde, används för att alla andra värden är större


do //it Upprepas tills rad 79 uppfylls (while (Startnummer > 0);)
{
    cout << "Startnummer? ";
    cin >> Startnummer;

    if (Startnummer > 0)  // Om uppfylls genomför do annars hoppa till while och slutför loop
    {
        {
            cout << "Starttid? ";
            cin >> Start_timme >> Start_minut >> Start_sekund;

            cout << "Måltid? ";
            cin >> Mal_timme >> Mal_minut >> Mal_sekund;
        }
    {
        if (Mal_timme == 0 && Start_timme == 0 && Start_sekund > Mal_sekund) //För att kunna hantera tider vid nollslaget och
        {
            Mal_timme= Mal_timme + 24; // Om if uppfylls lägg på 24 timmar på mål, istället för 0 får vi då 24. 
        }

        if (Start_timme > Mal_timme) // För att kunna hantera när racet håller på i mer än 24 timmar, läggs 24 timmar på måltiden
        {
            Mal_timme = Mal_timme + 24;
        }
    }

// Två if satser för att kunna hantera sluttiden så att den skrivs på rätt sätt (timmar, minuter och sekunder)
    {
        if (Start_sekund > Mal_sekund ) 
        {
            Mal_minut = Mal_minut - 1; //Tar bort en minut från Starttiden och omvandlar till sekund
            Mal_sekund= Mal_sekund + 60;   // En minut= 60 sekunder
        }

        if (Start_minut > Mal_minut)
        {
            Mal_timme = Mal_timme - 1; //Tar bort en timme från start och omvandlar till minuter
            Mal_minut = Mal_minut + 60; // En timme = 60 minuter
        }
    }
//Beräkning av differens, slut_tid i sekunder och antal person som har deltagit 
    {
        slut_min = Mal_minut - Start_minut; 
        slut_timme = Mal_timme - Start_timme; 
        slut_sek = Mal_sekund - Start_sekund;
        slut_tid = slut_timme*3600 + slut_min*60 + slut_sek;
        antal=antal+1; // lägger till person för varje iteration
    }

// If sats som uppdateras varje gång slut_tid är mindre än min 
    if (slut_tid < min) // om slut_tid är mindre än min byt värde på min och uppdatera alla tider
        {
            min = slut_tid;
            mintimme = slut_timme;
            minminut = slut_min;
            minsekund = slut_sek;
            Vinnare = Startnummer;   
        }
    }
} while (Startnummer > 0);

// En ifelse sats för att få prints beroende på vad som har hänt. 
    if (min==INT_MAX) // Om inte min har uppdateras har ingen iteration genomförts, alltså inga tävlande

        cout << "Inga tävlande" 
            << endl
            << "Programmet avslutas";
    
    else // Om en iteration har genomförts ange tim min sekund, vinnare och antalet. 
    {

        cout << "Tim: " << mintimme << " Min: " << minminut << " Sek: " << minsekund 
            << endl
            << "Vinnaren är: " << Vinnare 
            << endl
            << "Antalet tävlande är: " << antal 
            << endl
            << "Programmet avslutas";

    }

return 0;

}