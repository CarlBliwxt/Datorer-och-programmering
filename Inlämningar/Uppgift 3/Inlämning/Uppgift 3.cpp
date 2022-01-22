/*
Programmeringsuppgift 3: Funktioner
Ett program som utför enkla beräknare utifrån användarens inputs
Skriven av Carl Blixt. 
*/

#include <iostream>
using namespace std;
//----------------------------------
// Funktionsdeklaration
void skriv_hej(); // Beskriver vad programmet gör för användaren
int lasEttTal(); // Läser in tal, 
char lasOp(); // Läser in vilket tecken som väljs
void ordna(int &tal1, int &tal2); // Ordnar så att tal 
int berakna(int tal1, int tal2, char op); // Beräknar vald operation
void skrivResultat(int svar);

//----------------------------------

// Huvudprogram

int main ()
{

// Variabeldeklaration
  char op;
  int svar;
  int tal1, tal2;


  skriv_hej(); 
// Inläsning av två tal
  tal1 = lasEttTal();
  tal2 = lasEttTal(); 
// Inläsning av tecknet
  op =lasOp();

// Ordnar talet 
  ordna(tal1,tal2); 
// Beräknar och lägger svaret i int svar 
  svar = berakna(tal1, tal2, op);

  skrivResultat(svar); 
  return 0;
}
//----------------------------------
//----------------------------------
// Funktionsdefinitioner
//----------------------------------

void skriv_hej() // Skriver ut information om programmet, använder void eftersom vi inte vill ha någon returnerat
{
  cout << "Hej och välkommen till detta programmet!" 
        << endl 
        << "Detta program utför beräkningar utifrån användarens input."
        << endl
        << "Två heltal matas in och alla tal mellan dessa två tal summeras multipliceras eller kvadratssummeras, beroende på input" 
        << endl;

}

int lasEttTal() // Funktion som läser in ett heltal från användaren, körs två gånger. Int används för att vi vill lagra a i tal1 respektive tal2
{
    int a; 
    cout << "Ange ett heltal ";
    cin >> a; 
    return a; // Eftersom vi har int kan vi returnera tillbaka en siffra. 
    
}

char lasOp() // Funktion som läser in ett tecken från användaren, 
{
  char t1='a', t2= 'm', t3='k' , tecken;

      cout << "Ange ett tecken addition, multiplikation eller kvadratsumma " << t1 << ", " << t2
      << " eller " << t3 << ":" << endl;
      cin >> tecken;
      return tecken;

}

void ordna(int &tal1, int &tal2) // Funktion som ordnar så att talen är i rätt storleksordningen, gör att tal1 >= tal2 
{
  if (tal1 > tal2) 
  {
    int temp; //Temporär variabel som lagrar tal1 om if uppfylls

    temp=tal1; 
    tal1=tal2; // tal 1 blir tal2 
    tal2=temp; 
  }
}

int berakna(int tal1, int tal2, char op) // Funktion som använder sig av de två inmatade talen och 
{ 
  //Variabeldeklaration
  int sum = 0;
  int slut;
  int multiplikation = 1;

  switch(op)
  {
    case 'a' : // Fallet med addition
    {
      while (tal1 <= tal2) // En while loop som räknar ut summan mellan två tal genom att addera en varje iteration. 
      {  
      sum = sum+tal1;
      tal1 = tal1+1;
      }
      slut = sum;
      
    break; // Färdig med switch om case a 
    }

    case 'm' : // Fallet med multiplikation
    {
    
      for (tal1; tal1 <= tal2; ++tal1) // For loop som utförs sålänge tal1 <= tal2, efter varje iteration tal1=tal1+1 
      {
        multiplikation = tal1*multiplikation; 
      }
      slut = multiplikation;
    }
    break; // Färdig med multiplikation 
    
    case 'k' : // Fallet med kvadratsummering
    {

    while (tal1 <= tal2)  //Samma som addition 
    {
    sum = tal1*tal1+ sum;
    tal1 = tal1+1;
    }
  slut = sum;
    }
  break; // Färdig med kvadratsummering 
  }

return slut;
}

void skrivResultat(int svar) 
{
cout << "Resultatet av operationen är " << svar << endl;
}