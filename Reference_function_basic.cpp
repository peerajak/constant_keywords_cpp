// (c) Dorothy R. Kirk. All Rights Reserved
// Purpose:  Illustrates the difference between function arguments 
//           which are pointers and those which are references

#include <iostream>
#include <string>

using std::cout;    // preferred to: using namespace std;
using std::flush;
using std::string;
using std::endl;

void AddOne(int &);
void AddOne(int *);
void Display(string header,int &);

int main()
{
   int x = 10, *y = nullptr;
   y = new int;
   *y = 15;
   Display("x",x);
   Display("*y",*y);

   AddOne(x);   // calls reference version
   AddOne(*y);
   Display("x",x);
   Display("*y",*y);

   AddOne(&x);  // calls pointer version
   AddOne(y);
   Display("x",x);
   Display("*y",*y);

   delete y;

   return 0;
}

void AddOne(int &arg)
{
   cout<<"Reference AddOne"<<endl;
   arg++;
}

void AddOne(int *arg)
{
   cout<<"Pointer AddOne"<<endl;
   (*arg)++;
}

void Display(string header, int &arg)
{
   cout << header<<arg << " " << flush;
}
