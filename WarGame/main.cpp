//
//  main.cpp
//  WarGame
//
//  Created by David Osollo on 2/23/19.
//  Copyright © 2019 David Osollo. All rights reserved.
//  Tarea MCC Analisis y Diseño de algoritmos avanzados

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<list>
#include "CGraph.hpp"

using namespace std;

void replace(char *sStr, char cOld, char cNew);
int read_input(const char *sFileName,int iNumVertices);
void Rules(CGraph gAmigos,int iC,int iX,int Y);


////////////////////////////////////////////////////////
// Function to replace chars
void replace(char *sStr, char cOld, char cNew)
{
    char *str = sStr;

    str=strchr(str,cOld);
    while (str!=NULL)
    {
        *str=cNew;
        str=strchr(str+1,cOld);
    }
}

////////////////////////////////////////////////////////
// Execute Rules
void Rules(CGraph gAmigos,int iC,int iX,int iY)
{
   switch(iC)
   {
      case 0:
          return;
      case 1:
          if(gAmigos.DFS(iX, iY)!=ENEMIE)
          {
              gAmigos.addEdge(iX, iY, FRIEND);
              gAmigos.addEdge(iY, iX, FRIEND);
          }
          else cout <<"-1";
          break;
      case 2:
          if(gAmigos.DFS(iX, iY)!=FRIEND)
          {
              gAmigos.addEdge(iX, iY, ENEMIE);
              gAmigos.addEdge(iY, iX, ENEMIE);
          }else cout <<"-1";
          break;
      case 3:
          if(gAmigos.DFS(iX, iY)==FRIEND)
             cout <<"1";
          else cout <<"0";
          break;
      case 4:
          if(gAmigos.DFS(iX, iY)==ENEMIE)
              cout <<"1";
          else cout <<"0";
          break;
      default:
          exit(-1);
    }  //End Switch
}

////////////////////////////////////////////////////////
// Read the input files
int read_input(const char *sFileName,int iNumVertices)
{
    
    std::ifstream infile(sFileName);
    std::string line;
    int iNumPeople=0;
    int iC,iX,iY;
    int iMaxVer = 0;
    CGraph gAmigos;
    
    if(iNumVertices)
    {
       printf( "\nW A R   G A M E");
       printf( "\n--------    \t ------------");
       printf( "\nEntradas    \t  Resultados");
       printf( "\n--------    \t ------------");
    }
    
    while (std::getline(infile, line))
    {
        iC=0; iX=0; iY=0;
        if(!iNumPeople)
        {
            iNumPeople=std::stoi(line);
            if(iNumVertices)
               gAmigos.SetSize(iNumVertices+1);
        }
        else
        {
            char sInput[line.length()+1];
            char *sPtr;
            strcpy(sInput,line.c_str());
            replace(sInput,',',' ');
            
            sPtr = strtok( sInput, " \n\t" );
            if(sPtr) iC=atoi(sPtr);
            
            sPtr = strtok( NULL, " \n\t" );
            if(sPtr) iX=atoi(sPtr);
            
            sPtr = strtok( NULL, " \n\t" );
            if(sPtr) iY=atoi(sPtr);
            
            if(iNumVertices)
            {
                printf( "\n%d %d %d    \t :   ", iC,iX,iY );
                Rules(gAmigos,iC,iX,iY);
            }
            else
            {
                if(iMaxVer < iX) iMaxVer = iX;
                if(iMaxVer < iY) iMaxVer = iY;
            }
        }
  }//End While
  return iMaxVer;
    
}

int main(int argc, const char * argv[])
{
    int iNumVertices;
    iNumVertices=read_input(argv[1], 0);
    read_input(argv[1], iNumVertices);
    
    printf( "\n\n");
    return 0;
}

