// qsort.cpp

#include "lsort.h"

#include <cstdlib>
#include <array>
#include <iostream>
#include <vector>
#include <algorithm>

void qsort_sort(List &l, bool numeric) {
   
    std::vector<Node *> v;

    for(Node * curr = l.head->next; curr != NULL; curr = curr->next){

        v.push_back(curr);

    }

    Node **nodeArray = new Node*[v.size()];
    nodeArray = &v[0];
    if(numeric){
        qsort(nodeArray, v.size(), sizeof(Node), void_number_compare);
    }
    else{
        qsort(nodeArray, v.size(),  sizeof(Node), void_string_compare);
    }

    l.head = v[0];
    Node * curr = l.head;
    for(size_t i = 1; i< v.size(); i++){
        curr->next = v[i];
        curr = curr->next;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
