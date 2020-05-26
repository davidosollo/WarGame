//
//  CGraph.cpp
//  WarGame
//
//  Created by David Osollo on 3/10/19.
//  Copyright © 2019 David Osollo. All rights reserved.
//

#include "CGraph.hpp"

////////////////////////////////////////////
// Constructor VGraph with Number of Vertices
CGraph::CGraph(int iNumV)
{
    this->iNumVertices = iNumV;
    adj = new list<EDGE>[iNumV];
}

////////////////////////////////////////////
// Simple Constructorx
CGraph::CGraph()
{
}

////////////////////////////////////////////
// Set The Number of Vertices
void CGraph::SetSize(int iNumV)
{
    this->iNumVertices = iNumV;
    adj = new list<EDGE>[iNumV];
}

////////////////////////////////////////////
// Add a Edge in the vertice
void CGraph::addEdge(int v, int w, int iRelation)
{
    EDGE newEdge;
    newEdge.iTypeRelation = iRelation;
    newEdge.iVNum = w;
    adj[v].push_back(newEdge); // Add w to v’s list.
}

////////////////////////////////////////////
// Get all the Vertices Depth first
void CGraph::DFSUtilAll(int v, vector <int> &vNodes, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    vNodes.push_back(v);
    
    // Recur for all the vertices adjacent
    // to this vertex
    list<EDGE>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[i->iVNum])
            DFSUtilAll(visited[i->iVNum], vNodes, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
////////////////////////////////////////////
// Find all the Vertices connected
void CGraph::DFSAll(int v,vector <int> &vNodes)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[iNumVertices];
    for (int i = 0; i < iNumVertices; i++)
        visited[i] = false;
    
    // Call the recursive helper function
    // to print DFS traversal
    DFSUtilAll(v, vNodes,visited);
}

////////////////////////////////////////////
// Find if two vertices are connected
int CGraph::DFSUtil(int v, int iAmigo, int iRelation, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    // cout << v << " ";
    
    if(v==iAmigo) return iRelation;
    
    // Recur for all the vertices adjacent
    // to this vertex
    list<EDGE>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[i->iVNum])
        {
            int iFound = DFSUtil(i->iVNum,iAmigo,iRelation * i->iTypeRelation,visited);
            if(iFound!=0)
            {
                return iFound;
            }
        }
    }
    
    return 0;
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
////////////////////////////////////////////
// Find if two vertices are connected
int CGraph::DFS(int v, int iAmigo)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[iNumVertices];
    if(v == iAmigo) return 1;
    
    for (int i = 0; i < iNumVertices; i++)
        visited[i] = false;
    
    // Call the recursive helper function
    // to print DFS traversal
    return DFSUtil(v,iAmigo,1,visited);
}
