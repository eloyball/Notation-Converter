#include "Deque.hpp"

// Parent exception class
class Exception { 
    public:
        Exception(const std::string& err) : errMsg(err) { } 
        std::string getError() { return errMsg; } // access error message
    private:
        std::string errMsg; // error message
};

// Deque is empty exception
class DequeEmpty : public Exception {
    public:
        DequeEmpty(const std::string& err) : Exception(err) { }
};

// Constructor
Deque::Deque() : D(), n(0) { }

// Get number of items in the queue
int Deque::size() const {
    return n;
}

// Check if qeue is empty
bool Deque::empty() const {
    return n == 0;
}

// Get the front element
const Elem& Deque::front() const {
    if (empty()) {
        throw DequeEmpty("front of empty queue");
    }
    return D.front();
}

// Get the back element
const Elem& Deque::back() const {
    if (empty()) {
        throw DequeEmpty("back of empty queue");
    }
    return D.back();
}


// Insert new first element
void Deque::insertFront(const Elem& e) {
    D.addFront(e);
    n++;
}

// Insert new last element
void Deque::insertBack(const Elem& e) {
    D.addBack(e);
    n++;
}

// Remove first element
void Deque::removeFront() {
    if (empty()) { throw DequeEmpty("empty deque"); }
    D.removeFront();
    n--;
}

// Remove last element
void Deque::removeBack() {
    if (empty()) { throw DequeEmpty("empty deque"); }
    D.removeBack();
    n--;
}
