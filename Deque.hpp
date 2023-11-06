#ifndef __DEQUE_
#define __DEQUE_

#include "DLinkedList.hpp"

class Deque {
    public:
        Deque();

        int size() const;
        bool empty() const;
        const Elem& front() const;
        const Elem& back() const;

        void insertFront(const Elem& e);
        void insertBack(const Elem& e);
        void removeFront();
        void removeBack();

    private:
        DLinkedList D;
        int n;
};

#endif