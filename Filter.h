#include <iostream>
using namespace std;

class Filter
{
 public:
   // Constructors
   Filter();
   Filter(const Filter & param);
   ~Filter();

   // Methods
   int FilterString(string x);
   bool binarysearch(string y);
   void readtop1000();
   //bool properword

 private:
    string words[1000];
    int n;
};