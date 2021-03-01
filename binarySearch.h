#include <iostream>
using namespace std;

class binarySearch
{
 public:
   // Constructors
   binarySearch();
   binarySearch(const binarySearch & param);
   ~binarySearch();

   // Methods
   int binarySearchString(string x);
   bool found(string y);
   void read();

 private:
    string words[1000];
    int n;
};