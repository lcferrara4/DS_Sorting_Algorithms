// quick.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {

    dump_node(l.head); 
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
    
    if(head != nullptr){
        std::cout<<head->string<<"\n"; 
    }
    //base case 
    if (head == nullptr || head ->next == nullptr){
        std::cout<<"Base case\n"; 
        return head; 
    }

    //divide
    dump_node(head) ;
    partition(head, pivot, left, right, compare); 

    //conquer
    left = qsort(left, compare);
    std::cout<<"after right\n"; 
    right = qsort(right, compare); 

    return concatenate(left, right); 
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
    
    Node * curr = head; 
    Node * iterator = head;
    int count =0; 
    int count2 = 0;
    std::cout<<"partition\n"; 
    while(iterator != nullptr && iterator->next !=nullptr){
        curr = iterator; 
        iterator = iterator->next; 
        std::cout<<"stuck while\n"; 
        std::cout<<curr->string<<"\n"; 
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
            //pivot->next = iterator;
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
    //iterator = nullptr;
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
