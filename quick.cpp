// quick.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {

    if(numeric){
        l.head = qsort(l.head, node_number_compare); 
    }
    else{
        l.head = qsort(l.head, node_string_compare); 
    }
}

Node *qsort(Node *head, CompareFunction compare) {
    Node * pivot = head; 
    Node * left = nullptr;  
    Node * right = nullptr; 
    
    //base case 
    if (head == nullptr || head ->next == nullptr){
        return head; 
    }

    //divide
    partition(head, pivot, left, right, compare); 

    //conquer
    left = qsort(left, compare);
    std::cout << "in between" << "\n";
    right = qsort(right, compare); 
 
    dump_node(left);   
    return concatenate(left, right); 
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
    
    Node * curr = head; 
    while(curr != nullptr && curr->next != nullptr){
        curr = curr->next; 
        
        std::cout << curr->string << "\n";   
        if (compare(curr, pivot)){
            curr->next = left;
            left = curr; 
        }
        else{
            curr->next = right;
            right = curr;
        }
    }

    pivot->next = right;
    right = pivot;
}

Node *concatenate(Node *left, Node *right) {
    dump_node(left);
    dump_node(right);
    std::cout<<"concat\n"; 
    Node * curr = left;
    while(curr!=nullptr && curr->next != nullptr){
        curr = curr->next; 
    }
    curr->next = right; 
    return left; 
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
