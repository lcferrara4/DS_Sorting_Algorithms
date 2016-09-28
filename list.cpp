// list.cpp

#include "lsort.h"
#include <stdexcept>
#include <memory>

List::List() {

    Node * head = nullptr; 
    size_t size= 0; 
    

}

List::~List() {
    
    Node * curr = head; 
    while (head){
        head = head ->next;
        delete curr; 
        curr = head; 
    }

}

void List::push_front(const std::string &s) {

    try {
        head->next = new Node{s, stoi(s), head->next}; 
    }
    catch(const std::invalid_argument& ia){
        head->next = new Node{s, 0, head->next}; 
    }


}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
