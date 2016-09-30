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
    right = qsort(right, compare); 

    head = concatenate(left, right); 
    return head;
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
   
    left = nullptr;
    right = nullptr;
 
    Node * curr = head; 
    Node * temp = curr;

    while(curr != nullptr){// && curr->next != nullptr){
        temp = temp->next;
        
        if (compare(curr, pivot)){
            curr->next = left;
            left = curr; 
        }
        else{
            curr->next = right;
            right = curr;
        }
        curr = temp; 
    }

    //pivot->next = right;
    //right = pivot;
}

Node *concatenate(Node *left, Node *right) {
    Node * curr = left;
    while(curr!=nullptr){// && curr->next != nullptr){
        std::cout << curr->string << " curr string\n";
        curr = curr->next; 
    }
    if( right != nullptr ){
        curr = right; //or right 
    }
    dump_node(left);
    return left; 
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
