//constant reference.cpp

#include <iostream>


using std::cout;   // preferred to: using namespace std;
using std::endl;

int main()    
{
   int x = 5;
   const int &refInt = x;
   cout << x << " " << refInt << endl;
   #if 0
   refInt = 6;  // illegal. We can't change value of refInt
   #endif
   x = 7;
   cout << x << " " << refInt << endl;

   return 0;
}
