#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = 60;
    int *b = &a;
  
    
cout << "\n b = " << b <<   endl;
cout << "\n *b = " << *b <<endl;
cout << "\n a = " << a << endl; 
 int c = 5; 
 b = &c;
    
cout << "\n b =" << b << endl;
cout << "\n *b =" << *b << endl;

*b=100;
cout << c << endl;
}