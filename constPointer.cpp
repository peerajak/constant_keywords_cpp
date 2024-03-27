#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstring>

using std::cout;    // preferred to: using namespace std;
using std::endl;

char suffix = 'A';

const char *GenId(const char *);  // function prototype
// Copy from ebook got some non-ASCII characters, remove them with
//LANG=C sed -i 's/[\d128-\d255]//g' MyTakeOnConst.cpp  
int main()    
{
// Define, allocate, load simple strings using strcpy()
char *regularString = new char[36]; // sized for str below
strcpy(regularString, "I am a modifiable string");
char *anotherRegularString = new char[21]; // sized for
                                           // string below
strcpy(anotherRegularString, "I am also modifiable");
// Define a const pointer to a string; must be initialized
char *const constPtrString = regularString; // Ok
// You may not modify a const pointer to point elsewhere
#if 0
 constPtrString = anotherRegularString;  // No!
#else 
// But you may change the data which you point to
strcpy(constPtrString, "I can change the value"); // Yes
#endif

char *const constPtrTryMalloc = (char *)malloc(10);
strcpy(constPtrTryMalloc,"Test1 Test2");
printf("%s",constPtrTryMalloc);
   return 0;
}

