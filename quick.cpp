// quick.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {

    std::cout<<"anyone home"; 

    if(numeric){
        l.head = qsort(l.head, node_number_compare); 
    }
    else{
        l.head = qsort(l.head, node_string_compare); 
    }

}

Node *qsort(Node *head, CompareFunction compare) {
    std::cout<<"hi";  
    Node * pivot = head; 
    Node * left = nullptr;  
    Node * right = nullptr; 

    //base case 
    if (head == nullptr || head ->next == nullptr){
        return head; 
    }

    //divide
    std::cout<<"before partition"; 

    partition(head, pivot, left, right, compare); 

    std::cout<<"after partition";  
    //conquer
    left = qsort(left, compare); 
    right = qsort(right, compare); 

    return concatenate(left, right); 
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
    
    Node * curr = head; 
    Node * iterator = head; 

    std::cout<<"stuck partition"; 

    while(iterator != nullptr && iterator->next !=nullptr){
        curr = iterator; 
        if (compare(curr, pivot)){
            iterator = iterator->next;  
            curr->next = head; 
            head = curr; 
        }
        else{
            iterator = iterator ->next;  
            //curr->next = pivot->next; 
            //pivot->next = curr; 
        }

    }
    left = head; 
    right = pivot; 
    

}

Node *concatenate(Node *left, Node *right) {

    std::cout<<"concat"; 
    Node * curr = left; 
    while(curr->next != nullptr){
        dump_node(curr); 
        curr = curr->next; 
    }
    curr->next = right; 
    
    return left; 
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
