#include <iostream>

using std::cout;   // preferred to: using namespace std;
using std::cin;
using std::endl;


struct collection
{
   int x;       // don't worry, we'll soon see (Chp 5) how to initialize struct or class members easily
   float y;
};

void passByRef(int &changing);
void passByConstRef(const int &cannotChange);
void Update(collection &);
void Print(const collection &);

int main()
{
   collection collect1, *collect2 = nullptr; 

   // allocate memory for collect2 from the heap
   collect2 = new collection;  

   Update(collect1);   // a reference to the object is passes
   Update(*collect2);  // same here because *collect2 is also an object

   Print(collect1);  
   Print(*collect2);

   // delete collection pointed to by collect2
   delete collect2;  

   int a=3;
   cout<<"a is "<<a;
   passByRef(a);
   cout<<" passByRef, now a is "<<a<<endl;
   cout<<"a is "<<a;
   passByConstRef(a);
   cout<<" passByConstRef, now a is "<<a<<endl;
   return 0;
}

void Update(collection &c)
{
   cout << "Enter <int> and <float> members: ";
   cin >> c.x >> c.y;
}
    
void Print(const collection &c)
{
   cout << "x member: " << c.x << "   y member: " << c.y << endl;
}
void passByRef(int &changing){
    changing+=1;
}
void passByConstRef(const int &cannotChange){
    #if 0
     cannotChange+=1;//compile error here
    #endif
     cannotChange;//compile ok
}
