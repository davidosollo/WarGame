//
//  main.cpp
//  WarGame
//
//  Created by David Osollo on 2/23/19.
//  Copyright © 2019 David Osollo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void read_input(const char *sFileName);


/*int setFriends(int x,int y); // shows that x and y are from the same country
int setEnemies(int x,int y); // shows that x and y are from different countries
int areFriends(int x,int y); // returns true if you are sure that x and y are friends
int areEnemies(int x,int y); // returns true if you are sure that x and y are enemies*/

void read_input(const char *sFileName)
{
    
    std::ifstream infile(sFileName);
    std::string line;
    int iNumInputs=0;

    
    while (std::getline(infile, line))
    {
        //std::cout << line << "\n";
        if(!iNumInputs)
        {
            iNumInputs=std::stoi(line);
            printf("\nNumero de inputs %d\n", iNumInputs);
        }
        else
        {
         //   char *sInput[line.length()+1];
            char *sInput[100];
            strncpy(sInput,"hsh",2);
            strncpy(sInput,"",2);
            
        }
        
        
    }
}

int main(int argc, const char * argv[])
{
    
    read_input(argv[1]);
    return 0;
    
}
