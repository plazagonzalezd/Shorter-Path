//
//  EdgeNode.h
//  Project4
//
//  Created by Alexis Plaza González on 12/13/14.
//  Copyright (c) 2014 Alex Plaza. All rights reserved.
//

#ifndef __Project4__EdgeNode__
#define __Project4__EdgeNode__

#include <stdio.h>


struct EdgeNode{
    /*
     The constructor creates an EdgeNode taking as parameters
     the destination (dest) and weight. It restores
     the parameters in their respective fields.
     */
    
    EdgeNode(int dest, int weight);
    int weight;
    int dest;
};

#endif /* defined(__Project4__EdgeNode__) */
