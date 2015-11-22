//
//  Graph.cpp
//  Project4
//
//  Created by Alexis Plaza González on 12/13/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#include "Graph.h"
#include <list>
#include <fstream>
#include <iterator>

using namespace std;

//Public Functions--------------------------------------------

/*
 The constructor of the graph
 pre condition: none
 post condition: 
 adjList.size() = nrVetices
 costs.size() = nrVertices
 path.size() = nrVertices
 known.size() = nrVertices
 */
Graph::Graph(int nrVertices){
    adjList.resize(nrVertices);
    for(int i = 0; i < nrVertices; i++){//input initial conditions
        costs.push_back(MAX_INT);
        path.push_back(-1);
        known.push_back(false);
    }
}

/*
 retuns costs
 */
vector<int>& Graph::getCosts() {
    return costs;
}

/*
 returns path
 */
vector<int>& Graph::getPath() {
    return path;
}

/*
 returns known
 */
vector<bool>& Graph::getKnown() {
    return known;
}

/*
 returns adjList
 */

vector<vector<EdgeNode>>& Graph::getList(){
    return adjList;
}



/*
 Adds an edge to the adjecency list
 pre condition: none
 post condition:
 adjList[start].size() increases by one
 */
void Graph::addEdge(int start, int end, int weight){
    adjList[start].push_back(EdgeNode(end, weight));
}

/*
 Prints all the paths
 pre condition: for this function to be succesful, Djikastra
 function have had to be perfomed.
 post condtion: none.
 */
void Graph::printAllPaths(int nrVertices){
    for( int i = 1; i < nrVertices; i++){
        cout<< to_string(i) + ": ";
        if(costs[i] == MAX_INT) { //if costs = infinity
            cout<< "Can't get to city " + to_string(i) + "\n";
        }
        else{
        printOnePath(i);
        cout<< " cost of " + to_string(costs[i]);
        cout<< "\n";
        }
    }
}


//Private functions-------------------------------------------
/*
 Prints all the paths
 pre condition: for this function to be succesful, Djikastra
 function have had to be perfomed.
 post condition: none
 */
void Graph::printOnePath(int i){
    if(i != 0){
        printOnePath(path[i]);
        cout << "-";
    }
    cout <<  to_string(i);
}

