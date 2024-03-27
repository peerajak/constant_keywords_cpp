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
    //#1. Using pointers to constant objects
    // const qualified str; the data pointed to will be const
    const char *constData = "constant"; 
     printf("%s: %p\n", constData,(void *)constData);
    const int *constIntData;
    int a = 3, b =4, *not_constIntData;    
    constIntData = &a;
    a =4;
    #if 0
    constIntData = (int *)malloc(sizeof(b));
    memcpy(constIntData, &b, sizeof(b));//compile error
    #else
    not_constIntData = (int *)malloc(sizeof(b));
    memcpy(not_constIntData, &b, sizeof(int));
    printf("not_constIntData = %d\n", *not_constIntData);
    #endif
    const char *moreConstData = nullptr;
    // regular strings, defined. One is loaded using strcpy()
    char *regularString = nullptr;
    char *anotherRegularString = new char[8];// sized to fit 
     // this string 
    strcpy(anotherRegularString, "regular");
    // Trying to modify data marked as const will not work
    #if 0
    strcpy(constData, "Can I do this? ");// NO!
     printf("%s: %p\n", constData,(void *)constData);
    #else
        constData = "updated constant";  // allow
     printf("%s: %p\n", constData,(void *)constData);
     #endif
    // Trying to circumvent by having a char * point to
    // a const char * also will not work
    // regularString = constData; // NO! 
    // But we can treat a char * more strictly by assigning to 
    // const char *. It will be const from that viewpoint only
    moreConstData = anotherRegularString; // Yes - can do this!

   return 0;
}


