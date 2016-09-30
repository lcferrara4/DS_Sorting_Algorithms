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
    Node * left = head;  
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

    return concatenate(left, right); 
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
    
    Node * curr = head->next; 
    Node * iterator = head->next;
    //Node * end = nullptr;

    int count =0; 
    int count2 = 0;
    
    while(curr != nullptr && curr->next != nullptr){//iterator != nullptr && iterator->next !=nullptr){
        curr = iterator; 
        iterator = iterator->next; 
        
        if (compare(curr, pivot)){
            if (count == 0 ){
                curr->next = nullptr; 
                count++; 
            }
            else{
                curr->next = head;
                count++; 
            }
            head = curr; 
        }
        else{
            if (count2 == 0){
                curr->next = nullptr;
                count2++;
            }
            else{
                curr->next = pivot->next;
                count2++;
            }
            pivot->next = curr;
        }
    }
    left = head; 
    right = pivot; 
    //end->next = nullptr; 
   // std::cout << end->string << " is end\n";
}

Node *concatenate(Node *left, Node *right) {

    std::cout<<"concat\n"; 
    Node * curr = left;
    std::cout<<curr->string<<" is the curr node value in concat\n"; 
    while(curr!=nullptr && curr->next != nullptr){
        curr = curr->next; 
    }
    curr = right; 
    std::cout<<curr->string<<" is right\n";
    return left; 
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
