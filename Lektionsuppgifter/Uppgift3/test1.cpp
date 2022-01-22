#include <iostream>
using namespace std;
//----------------------------------
// Funktionsdeklaration
int main()
{
    int tal1,tal2;

    
    cout<<"Please give me an integer: ";
    cin >> tal1;

    cout<<"Please give me another integer: ";
    cin >> tal2;

    int sum=0;
  while (tal1 <= tal2)
  {  
    sum=sum+tal1;
  tal1=tal1+1;

    cout << "The total of the numbers " << sum <<endl;      
}
}
