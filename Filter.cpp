#include "Filter.h"
#include<fstream>
#include<bits/stdc++.h> 

//constructors
Filter::Filter()
{
    low = 0;
    high=999;
    string words[high]; 
   
}

Filter::Filter(const Filter & param)
{
     words[1000] = param.words[1000];
     high = param.high;
     low = param.low;
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
 
// int Filter::FilterString(string x)

// {
//   string sl=x; 
//   transform(sl.begin(), sl.end(), sl.begin(), ::tolower); 
//   x = sl;
//   int lower = 0;
//   int upper = n - 1;
//   while (lower <= upper) {
//       int mid = lower + (upper - lower) / 2;
//       int res;
//       if (x == (words[mid]))
//          res = 0;
//       if (res == 0)
//          return mid;
//       if (x > (words[mid]))
//          lower = mid + 1;
//       else
//          upper = mid - 1;
//   }
//   return -1;
// }

int Filter::FilterString(string words[], int low, int high, string x)
{
    if (low > high) {
        return -1;
    }
    
    int mid = (low + high)/2;
    int compval = x.compare(words[mid]);

    if (compval==0) {
        return mid;
    }
    else if (compval<0) {
        return FilterString(words, low, mid - 1, x);
    }
    else {
        return FilterString(words, mid + 1, high, x);
    }
}

bool Filter::binarysearch(string x)
{
   string sl=x; 
   transform(sl.begin(), sl.end(), sl.begin(), ::tolower); 
   x = sl;
    if(FilterString(words, low, high, sl)==-1)
    {
        return false;
    }
    return true;
}

