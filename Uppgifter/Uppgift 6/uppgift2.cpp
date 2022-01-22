#include <iostream>
#include <string>
using namespace std;

int main ()
{
int n;
cout << "Ge mig n antal tal";
cin >> n;
int *array = 0;

array = new int[n];

for (int i=0; i < n ; i++)
{
    cout << "Ange tal " << i+1 << ": ";
    cin >> array[i];
}

int *nyarray = 0 ;
nyarray = new int [n];
for (int i=0; i < n ; i++)
{
    nyarray[i]=array[i];
}

for (int i=0; i<n; i++)     
{    cout << nyarray[i] << "\t"; 
   if ( (i+1)%5 == 0 ) 
   {  cout<<endl;}    
   }
     cout<<endl;

delete []array;
delete []nyarray;
return 0;



}
