
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int myArr[6]; // Statisk array deklareras.
int *myptr;   // Pekare deklareras.

myptr = &myArr[0]; // Nu pekare "myptr" på
                   // första elementet i "myArr". 

myptr++; // Nu pekar "myptr" på
         // andra elementet i "myArr".
myptr++; // Nu pekar "myptr" på
         // tredje elementet i "myArr".

*myptr = 9999; // Ger det tredje elementet
               // i "myArr" värdet 9999.