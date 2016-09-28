// node.cpp

#include "lsort.h"
#include <string.h> 
#include <iostream>

bool node_number_compare(const Node *a, const Node *b) {

    return (a->number > b->number); 

}

bool node_string_compare(const Node *a, const Node *b) {

    return (strcmp(a->string, b->string)); 
}

int void_number_compare(const void *a, const void *b) {
    
    int result = ((struct Node *)a)->number; 
    int result2 = ((struct Node *)b)->number; 
    return (result > result2); 

}

int void_string_compare(const void *a, const void *b) {
    
    string result = ((struct Node *)a)->string; 
    string result2 = ((struct Node *)b)->string; 
    return (strcmp(result, result2)); 

}

//helper function outputs contents of each node from n to nullptr
void dump_node(Node *n) {

    for(Node * curr = n; curr != nullptr; curr = curr->next){
        std::cout<<"Number: "<<curr->number<<" String: "<<curr->string<<std::endl; 
    }

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
