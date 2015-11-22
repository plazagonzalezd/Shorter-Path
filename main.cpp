//
//  main.cpp
//  Project4
//
//  Created by Alexis Plaza González on 12/12/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//
/*
 Dijkstra performs a Dijkstra-find-shortest-path
 algorithm. The startNode is passed as a parameter and it
 is inserted in a heap (h); its costs, path and known
 value are modified accordingly. It's
 adjecent nodes are analyzed, and everytime a change in
 costs is made, an edgeNode is inserted into the heap.
 The heap is used to get the node that will be analyzed
 next by using deleteMin method of the heap.
 
 pre condition:  none
 post condition: the values of costs, path and known, are
 modified to their appropiate values.
 */

#include <iostream>
#include <fstream>
#include "Graph.h"
#include "EdgeNode.h"
#include "heap.h"
using namespace std;
enum EntryCode {UNDIRECTED, DIRECTED};

int main() {
    
    int nrEdges, nrVer, nodex, nodey, weight, response, j = 2;
    Heap h;
    ifstream myInputFile;
    myInputFile.open("graph.txt");
    myInputFile >> nrVer >> nrEdges;
    Graph graph(nrVer);
    EdgeNode *votuporanga = new EdgeNode(0,0);
    cout << "\n Please input 0 for undirected graph or 1 for directed graph. \n";
    cin >> response;
        if(response == DIRECTED) j = 1; //used to calculate number of edges depending on the response.
                for (int i = 1; i <= j*nrEdges; ++i) {
                    myInputFile >> nodex >> nodey >> weight;
                    graph.addEdge(nodex, nodey, weight);
                if (response == UNDIRECTED) graph.addEdge(nodey,nodex,weight);
                    
                }
// --------------------------------Dijkstra starts here-------------------------
    graph.getCosts()[votuporanga-> dest] = 0;
    h.insert(votuporanga);
    EdgeNode* v; //verice that is being analyzed
    while(!h.isEmpty()){
        v = h.deleteMin();
        graph.getKnown()[v->dest] = true;
        
        /*
         This if is necessary because when all the vertices are 
         "known" v->weight would always be MAX_INT and the while
         */
        if (v->weight <= graph.getCosts()[v->dest]) {
            
            // it is the adjecent vertices
            for (vector<EdgeNode>::iterator it = graph.getList()[v->dest].begin(); it != graph.getList()[v->dest].end(); ++it){
                
                if(graph.getKnown()[it->dest] == false){
                    if (graph.getCosts()[it->dest] > graph. getCosts()[v->dest] + it ->weight){
                        
                        graph.getCosts()[it->dest] = graph.getCosts()[v->dest] + it->weight;
                        graph.getPath()[it->dest] = v->dest;
                        
                        EdgeNode *temp = new EdgeNode(it->dest,graph.getCosts()[it->dest]);
                        h.insert(temp);
                    }
                }
            }
        }
    }
                graph.printAllPaths(nrVer);
                myInputFile.close();
    return 0;
}
