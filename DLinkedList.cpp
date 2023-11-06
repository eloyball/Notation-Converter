#include "DLinkedList.hpp"

// Constructor
DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer; // have them point to each other
    trailer->prev = header;
}

// Destructor
DLinkedList::~DLinkedList() {
    while (!empty()) removeFront(); // remove all but sentinels
    delete header; // remove the sentinels
    delete trailer;
}

// Check if list is empty
bool DLinkedList::empty() const {
    return (header->next == trailer);
}

// Get the front element
const Elem& DLinkedList::front() const {
    return header->next->elem;
}

// Get the back element
const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}

// Insert new node before v
void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode;  u->elem = e; //create new node for e
    u->next = v; // link u in between v
    u->prev = v->prev; // ...and v->prev
    v->prev = u;
    v->prev->prev->next = v->prev;
}

// Add to front of list
void DLinkedList::addFront(const Elem& e) {
    add(header->next, e);
}
 
// Add to back of list
void DLinkedList::addBack(const Elem& e) {
    add(trailer, e);
}

// Remove node v
void DLinkedList::remove(DNode* v) {
    DNode* u = v->prev; // predecessor
    DNode* w = v->next; // successor
    u->next = w; // unlink v from list
    w->prev = u;
    delete v;
}

// Remove from font
void DLinkedList::removeFront() {
    remove(header->next);
}

// Remove from back
void DLinkedList::removeBack() {
    remove(trailer->prev);
}
