//
//  Heap.h
//  Project4
//
//  Created by Alexis Plaza González on 12/13/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#ifndef __Project4__Heap__
#define __Project4__Heap__

#include <stdio.h>
#include <vector>
#include <iostream>
#include "EdgeNode.h"
using namespace std;

class Heap{
public:
    
    /*
     The constuctor increases the size of myVector by 10.
     and sets the field size equal to 0.
     */
    Heap();
    
    /*
     Insert inserts an element into the heap. It Takes a 
     EdgeNode as a parameter and it is perlocated up
     to it's correct position.
     */
    void insert(EdgeNode*);
    
    /* deleteMin() returns the smallest element in the heap 
     by calling findMin(). It also deletes the number at myVector[1] 
     and reorganizes the vector calling perlocateDown().
     */
    EdgeNode* deleteMin();
    
    /* 
     returns true if size = 0 or false otherwise.
     */
    bool isEmpty();
    
private:
     /*
     organizes the inputed node to its appropiate position. 
     It "lowers the position of the node" (i.e. from Vector[10] 
     to Vector[8]). It compares the weight of the parent of the node
     and moves the node up if the parent's weight is lower.
     */
    void percolateUp(EdgeNode* node);
    
     /* Takes an integer as a parameter, creates a new node equal to myVector[hole]. 
      Then it organizes this new node down the array. It compares the children of 
      the node, and exchange them if the child is of lower priority than the new node.
     */
    void percolateDown(int hole);
    
    /*finMin() returns the node at position myVector[0] or
     prints a message if the size is 0
     */
    EdgeNode* findMin();
    
    vector<EdgeNode*> myVector;  //the vector in which the heap is stored
    int size; // the number of elements in the heap.
    
    
};

#endif /* defined(__Project4__Heap__) */
