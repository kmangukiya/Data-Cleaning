/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include "binarySearch.h"
using namespace std;
int main()
{
   binarySearch search;
   search.read();
   string test1 = "kinal";
   string test2 = "able";
   cout<<"\n\n";
   
   cout<<"\n  Binary Search test on top1000.txt file\n\n\n";
   
   if(search.found(test1)==true)
   {
       cout<<"  Key '"<<test1<<"' Found in top1000 words"<<endl;
   }
   else
   {
       cout<<"  Key '"<<test1<<"' Not Found in top1000 words"<<endl;
   }
   cout<<"\n";
   
   if(search.found(test2)==true)
   {
       cout<<"  Key '"<<test2<<"' Found in top1000 words"<<endl;
   }
   else
   {
       cout<<"  Key '"<<test2<<"' Not Found in top1000 words"<<endl;
   }
   
    cout<<"\n\n";

   
}