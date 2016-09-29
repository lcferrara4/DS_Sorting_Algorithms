// merge.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, CompareFunction compare);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, CompareFunction compare);

// Implementations

void merge_sort(List &l, bool numeric) {

    if(numeric){
        l.head = msort(l.head, node_number_compare); 
    }
    else{
        l.head = msort(l.head, node_string_compare); 
    }

}

Node *msort(Node *head, CompareFunction compare) {

    Node * left; 
    Node * right; 

    //handle base case
    if(head == nullptr){// || head -> next == nullptr){
        return head; 
    }

    //divide into left and right 
    split(head, left, right);  
    
    //conquer left and right sublists
    right = msort(right, compare); 
    left = msort(left, compare); 

    //combine left and right sublists
    return merge(left, right, compare); 

}

void split(Node *head, Node *&left, Node *&right) {

    Node *slow_ptr, *fast_ptr; 
    while(!slow_ptr && !fast_ptr && fast_ptr->next != nullptr){
        slow_ptr = slow_ptr->next; 
        fast_ptr = fast_ptr->next->next; 
    }
    left = head;     
    right = slow_ptr;  


}

Node *merge(Node *left, Node *right, CompareFunction compare) {
    
    Node *head;

    if (compare(left,right)){
        head = left;
        left = left->next;
    }
    else{
        head = right;        
        right = right->next;
    }

    Node * curr = head;

    while(left->next || right -> next){
        
        if(right == nullptr || compare(left, right)){
            curr->next = left; 
            left = left->next;
            
        } 
        else if(left == nullptr || !compare(left, right)){
            curr->next = right; 
            right = right->next; 
        }
        curr= curr->next; 
    }
    return head; 
    
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
