//
//  Graph.h
//  Project4
//
//  Created by Alexis Plaza González on 12/13/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//
/*
 The graph is implemented unsing a Adjecency List, which is a 
 vector of a vector of EdgeNodes. The other fields: costs, paths, 
 and known, are utilize to keep track of the shortest cost, the path,
 and wether or that node had been visited, respectively.
 */
#ifndef __Project4__Graph__
#define __Project4__Graph__

#include <stdio.h>
#include <vector>
#include "EdgeNode.h"
#include "Heap.h"
#include <list>
using namespace std;
const int MAX_INT = 2000000; // Represents infinity

class Graph{
public:
    /*
     The constructor of the Graph. It takes the 
     number of vertices as an argument 
     (nrVetices). It resizes the adjecency list to
     nrVetices, and pushes nrVertices times
     MAX_INT, -1, and false, into costs, path, and
     known, respectively
     */
    Graph(int nrVertices);
    
    /*
     addEdge adds an EdgeNode to the adjList. It
     takes as a parameter, start, end and weight.
     The node's fields dest and weight are given
     end and weight and it is inserted in 
     adjList[start].
     */
    void addEdge(int start, int end, int weight);
    
    /*
     Prints the shortest paths to all the vertices to the 
     initial vertice, and the lowest cost to each of the
     vertices. It recursively calls printOnePath nrVertices
     times.
     */
    void printAllPaths(int nrVertices);
    
    /*
     Accesor method that returns costs.
     */
    vector<int>& getCosts();
    
    /*
     Accesor method that returns path.
     */
    
    vector<int>& getPath();
    
    /*
     Accesor method that returns known.
     */
    vector<bool>& getKnown();
    
    /*
     Accesor method that returns adjList.
     */
    vector<vector<EdgeNode>>& getList();

private:
    /*
     adjList is an adjencency list made of a vector of a 
     vector of edgeNodes. Each entry in the vector 
     represents a vertices, and each of the edgeNodes 
     represent the edges that are connected to each vertice.
     If the cost of vertice i is MAX_INT, "Can't get to city
     i" is printed.
    */
    vector<vector<EdgeNode>> adjList;
    
    /*
     costs is used to keep track of the lowest cost to get
     to each of the vertices from the initial vertice.
     */
    vector<int> costs;
    
    /*
    path is a vector of integers that keeps track of the
     shortest path to get to each of the vertices.
     */
    vector<int> path;
    
    /*
     known is used to indicate whether a vertice in the 
     graph has been visited or not. If known is true, it 
     means that the shortest cost and the appropiate path
     of that vertice is known.
     */
    vector<bool> known;
    
    /*
     Recursively prints the shortest path of vertice i, until
     i = 0.
     */
    void printOnePath(int i);
};

#endif /* defined(__Project4__Graph__) */
