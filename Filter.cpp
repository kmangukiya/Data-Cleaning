#include "Filter.h"
#include<fstream>
#include<bits/stdc++.h> 

//constructors
Filter::Filter()
{
    string words[1000]; 
    n=999;
}

Filter::Filter(const Filter & param)
{
     words[1000] = param.words[1000];
     n = param.n;
}

Filter:: ~Filter()
{
    
}
 // Methods
 
void Filter::readtop1000()

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
 
int Filter::FilterString(string x)

{
   string sl=x; 
   transform(sl.begin(), sl.end(), sl.begin(), ::tolower); 
   x = sl;
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

bool Filter::binarysearch(string x)
{
    if(FilterString(x)==-1)
    {
        return false;
    }
    return true;
}

