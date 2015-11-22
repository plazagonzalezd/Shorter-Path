//
//  Heap.cpp
//  Project4
//
//  Created by Alexis Plaza González on 12/13/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#include "Heap.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//Public Functions---------------------------------

/*
 The constructor of the HEAP.
 pre condition: none
 post condition: size = 0
 */

Heap::Heap(){
    myVector.resize(10);
    size = 0;
}


/*
 Insert inserts a new node into the heap
 pre condition: none
 post condition: size = size + 1;
 */

void Heap::insert(EdgeNode* node){
    if(size == myVector.size()-1) myVector.resize(size*2); //doubles the size of the vector.
    if(size == 0){ //if myVector is empty
        myVector[1] = node;
        size++;
        return;
    }
    size++;
    myVector[size] = node;
    percolateUp(node);
}

/*
 deleteMin deletes the node at myVector[1] and 
 reorganizes the heap.
 precondition: none
 postcondition: size = 0 if size = 1; or size = size - 1.
 */
EdgeNode* Heap::deleteMin(){
    if(size == 0){
        cout << "heap is empty\n";
        return NULL;
    }
    EdgeNode* returnValue = findMin();
    
    if(size == 1){
        myVector[1] = NULL;
        size--;
        return returnValue;
    }
    myVector[1] = move(myVector[size]);
    myVector[size] = NULL;
    size--;
    percolateDown(1);
    return returnValue;
}

bool Heap::isEmpty(){
    return (size == 0);
}

/*percolateUp changes the position of the last 
 element to it's appropiate position.
 precondition: none
 postcondition: changes the order of the elements in myVector.
 */

//PRIVATE FUNCTIONS-----------------------------

/*
 findMin prints and return the node with the
 smallest value myVector[1]
 precondition: none
 postcondition: none
 */
EdgeNode* Heap::findMin(){
    if(size == 0){
        cout<< "the heap is empty \n";
        return 0;
    }
    return myVector[1];
}

void Heap::percolateUp(EdgeNode* node){
    for(int hole = size; floor(hole/2) != 0 && node->weight < myVector[floor(hole / 2)]-> weight; hole = (floor(hole/2)))
    {
        myVector[hole] = move(myVector[floor(hole/2)]);
        myVector[floor(hole/2)] = node;
    }
}

/* percolateDown changes the position of the inputed node 
 to a "greater" position.
 precondition: none
 postcondition: changes the order of the elements in myVector.
 */
void Heap::percolateDown(int hole){
    int child;
    EdgeNode* compare = myVector[hole];
    for(; hole*2 <= size; hole = child){
        child = hole*2;
        if((child != size) && (myVector[child] -> weight > (myVector[child + 1])->weight)) child++;
        if( myVector[child] -> weight < compare -> weight) myVector[hole] = move(myVector[child]);
        else break;
    }
    myVector[hole] = move(compare);
}