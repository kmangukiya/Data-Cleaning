#include "binarySearch.h"
#include<fstream>
//constructors
binarySearch::binarySearch()
{
    string words[1000]; 
    n=999;
}

binarySearch::binarySearch(const binarySearch & param)
{
     words[1000] = param.words[1000];
     n = param.n;
}

binarySearch:: ~binarySearch()
{
    
}
 // Methods
 
void binarySearch::read()

{
    
    ifstream infile("top1000.txt");
    int rank=0;
    string word="";
    
    int index = 0; 
    while (infile >> rank >> word)
    {
     words[index++]=word;
    }
  
}
 
int binarySearch::binarySearchString(string x)

{
   int lower = 0;
   int upper = n - 1;
   while (lower <= upper) {
      int mid = lower + (upper - lower) / 2;
      int res;
      if (x == (words[mid]))
         res = 0;
      if (res == 0)
         return mid;
      if (x > (words[mid]))
         lower = mid + 1;
      else
         upper = mid - 1;
   }
   return -1;
}

bool binarySearch::found(string x)
{
    if(binarySearchString(x)==-1)
    {
        return false;
    }
    return true;
}

