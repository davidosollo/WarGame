//
//  CGraph.hpp
//  WarGame
//
//  Created by David Osollo on 3/10/19.
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
#include<iostream>
#include<list>
#include <stdio.h>

#ifndef CGraph_hpp
#define CGraph_hpp

using namespace std;

#define ENEMIE -1
#define FRIEND  1
#define EDGE struct Edge

struct Edge
{
    int iVNum;         //Vertice Number;
    int iTypeRelation; // Fiend or Enemie
};

// Graph class represents a directed graph
// using adjacency list representation
class CGraph
{
    int iNumVertices;    // No. of vertices
    EDGE V;
    
    // Pointer to an array containing
    // adjacency lists
    list<EDGE> *adj;
    
    // A recursive function used by DFS
    int DFSUtil(int v, int iAmigo, int iRelation, bool visited[]);
    void DFSUtilAll(int v, vector <int> &vNodes, bool visited[]);
    
public:
    CGraph(int V);   // Constructor
    CGraph();
    
    // function to add an edge to graph
    
    void SetSize(int V);
    void addEdge(int v, int w, int iRelation);
    
    // DFS traversal of the vertices
    // reachable from v
    int DFS(int v, int iAmigo);
    void DFSAll(int v, vector <int> &vNodes );
    void DirectEnemyUtilAll(int v, vector <int> &vNodes);
    int DirectEnemyUtil(int v, int Enemigo);
    
};
#endif /* CGraph_hpp */
