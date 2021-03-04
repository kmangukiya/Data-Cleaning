/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include<sstream>
#include "Filter.h"
#include<bits/stdc++.h> 
#include<vector>


using namespace std;
int main()
{
    
    cout<<"\n\n";
    Filter filter;
    filter.readtop1000();
   
    bool flag = true;
   
    while(flag)
    {
        int choice = 0;
        cout<<"\nAvailable options: \n\n1. Generate abridged version of a book\n2. Exit\n\nEnter your choice: ";
        cin>>choice; 
        
        switch(choice)
        {
         case 1: 
         {

            fstream file; 
            string inputfilename="";
            cout<<"\nEnter name of the input file: ";
            std::getline(std::cin >> std::ws, inputfilename);
            file.open(inputfilename.c_str());
    
            string outputfilename="";
            cout<<"\nEnter your desired name for output file: ";
            std::getline(std::cin >> std::ws, outputfilename);
            ofstream output(outputfilename);
    
            vector<char> punctuations;
            punctuations.push_back('.');
            punctuations.push_back(',');
            punctuations.push_back(';');
            punctuations.push_back('?');
            punctuations.push_back('!');
    
            string words;
            while (std::getline(file, words))
            {
                istringstream iss(words); 
                while (iss) 
                { 
                    string word ="";
                    iss>>word;
            
                    string sl = word; 
                    sl.erase (std::remove_if (sl.begin (), sl.end (), ::ispunct), sl.end ());
           
                    char firstChar = sl[0];
                    bool properWord = (int)firstChar >64 && (int)firstChar <91;
            
                    if(filter.binarysearch(sl) || properWord)
                    {
                        string str (word);
                        for ( int i = 0 ; i < str.length(); i++)
                        {
                             if( (int)str[i]>122 || (int)str[i]<65 )
                            {
                                bool check = std::find(punctuations.begin(), punctuations.end(), str[i]) != punctuations.end();
                                if(!check)
                                {
                                    str.erase(i,i+1);
                                }

                            }
                        }
                        
                    word = str;
                    output<<word<<" ";  
                    }
                
                }
             output<<"\n"; 
            }
            
         
        cout<<"\n\n";
        output.flush();
        output.close();
        break;
        }
        
    case 2: flag = false; break;

        }
    }
}