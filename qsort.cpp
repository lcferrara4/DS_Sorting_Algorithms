// qsort.cpp

#include "lsort.h"

#include <cstdlib>
#include <array>
#include <iostream>
#include <vector>
#include <algorithm>

void qsort_sort(List &l, bool numeric) {
   
    int i = 0; 

    /*std::vector<Node *> v;
    
    for(Node * curr = l.head->next; curr != NULL; curr = curr->next){

        v.push_back(curr);

    }

    Node **nodeArray = new Node*[v.size()];
    nodeArray = &v[0];
    */
    Node **nodeArray = new Node*[l.size];  
    for(Node * curr = l.head->next; curr !=nullptr; curr = curr->next){
        
        nodeArray[i] = curr; 
        i++; 

    }



    if(numeric){
        qsort(nodeArray, l.size, sizeof(Node), void_number_compare);
    }
    else{
        qsort(nodeArray, l.size,  sizeof(Node), void_string_compare);
    }

    l.head = nodeArray[0]; 
    
    for(size_t i = 0; i< l.size - 1; i++){
        nodeArray[i]->next = nodeArray[i+1]; 
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
