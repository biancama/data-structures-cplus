//
// Created by Massimo Biancalani on 14/05/16.
//

#ifndef DATASTRUCTURED_DOUBLY_LIST_H
#define DATASTRUCTURED_DOUBLY_LIST_H

#include "DoubleNode.hpp"
#include "../exception/IndexOutOfBoundsException.h"
namespace structure {
    template <class T>
    class DoublyLinkedList {

    private:
        DoubleNode<T> *head;
        DoubleNode<T> *tail;
        unsigned int sizeOfList;

        DoubleNode<T> *getForward(int i, DoubleNode<T> *nodePtr) const;
        DoubleNode<T> *getBackward(int i, DoubleNode<T> *nodePtr) const;
        DoubleNode<T> *getNode(int i) const;
        DoubleNode<T> *add(DoubleNode<T> *v , const T& elem) const;
        void remove(DoubleNode<T> *v );
    public:
        DoublyLinkedList();

        virtual ~DoublyLinkedList() { while (!isEmpty()) {
                removeFirst();
            } }

        unsigned int size() const;

        bool isEmpty();

       const T& get(int i) const;

        void set(int i, const T& e);

        void add(int i, const T& e);

        void remove(int i) ;

        const T& first() const;

        const T& last() const;

        void addLast(const T& e);

        void addFirst(const T& e);

        void removeFirst();
    };
}
template <class T>
unsigned int structure::DoublyLinkedList<T>::size() const {
    return sizeOfList;
}
template <class T>
structure::DoublyLinkedList<T>::DoublyLinkedList() :head(nullptr), tail(nullptr), sizeOfList(0) {
}
template <class T>
bool structure::DoublyLinkedList<T>::isEmpty() {
    return head == nullptr;
}
template <class T>
const T& structure::DoublyLinkedList<T>::get(int i) const{
    if (i < 0 || i > sizeOfList - 1 ) {
        throw new IndexOutOfBoundsException();
    }
    DoubleNode<T>* pointer = getNode(i);
    return pointer->getElem();
}
template <class T>
structure::DoubleNode<T>* structure::DoublyLinkedList<T>::getForward(int position, structure::DoubleNode<T> *nodePtr) const{
    for (int i = 0; i < position; ++i) {
        nodePtr = (DoubleNode<T>*)nodePtr->getNext();
    }
    return nodePtr;
}
template <class T>
structure::DoubleNode<T>* structure::DoublyLinkedList<T>::getBackward(int position, structure::DoubleNode<T> *nodePtr) const{
    for (int i = 0; i < position; ++i) {
        nodePtr = nodePtr->getPrev();
    }
    return nodePtr;
}
template <class T>
structure::DoubleNode<T>* structure::DoublyLinkedList<T>::getNode(int position) const{
    if (position <= sizeOfList/2) {
        return getForward(position, this->head);
    } else {
        return getBackward(sizeOfList - position - 1, this->tail);
    }
}
template <class T>
const T& structure::DoublyLinkedList<T>::first() const{
    return get(0);
}
template <class T>
void structure::DoublyLinkedList<T>::addFirst(const T &e) {
    add(0, e);
}
template <class T>
const T &structure::DoublyLinkedList<T>::last() const {
    return get(sizeOfList - 1);
}
template <class T>
void structure::DoublyLinkedList<T>::set(int i, const T & e)  {
    if (i < 0 || i > sizeOfList - 1 ) {
        throw new IndexOutOfBoundsException();
    }
    DoubleNode<T>* pointer = getNode(i);
    pointer->setElem(e);
}
template <class T>
void structure::DoublyLinkedList<T>::add(int i, const T &e) {
    if (i < 0 || i > sizeOfList ) {
        throw new IndexOutOfBoundsException();
    }
    DoubleNode<T>* pointer = getNode(i);
    DoubleNode<T>* newNode = add(pointer, e);
    if (i == 0) {
        head = newNode;
    }
    if (i == sizeOfList) {
        tail = newNode;
    }
    sizeOfList++;
}

template <class T>
void structure::DoublyLinkedList<T>::remove(int i) {
    if (i < 0 || i > sizeOfList ) {
        throw new IndexOutOfBoundsException();
    }
    DoubleNode<T>* pointer = getNode(i);
    if (i == 0) {
        head = pointer->getNext();
    }
    if (i == sizeOfList - 1) {
        tail = pointer->getPrev();
    }
    remove(pointer);
    sizeOfList--;
}
template <class T>
void structure::DoublyLinkedList<T>::addLast(const T &e) {
    add(sizeOfList, e);
}

template <class T>
void structure::DoublyLinkedList<T>::removeFirst() {
    remove(0);
}
template <class T>
structure::DoubleNode<T> *  structure::DoublyLinkedList<T>::add(DoubleNode<T>* v, const T &elem) const{
    DoubleNode<T>* node = new DoubleNode<T>(elem);
    node->setNext(v);
    if (v != nullptr) {
        DoubleNode<T>* p = v->getPrev();
        v->setPrev(node);
        node->setPrev(p);
        if (p != nullptr) {
            p->setNext(node);
        }
    }
    return node;
}
template <class T>
void structure::DoublyLinkedList<T>::remove(DoubleNode<T> *v) {
    DoubleNode<T> *p = v->getPrev();
    DoubleNode<T> *n = v->getNext();
    if(p != nullptr) {
        p->setNext(n);
    }
    if (n != nullptr) {
        n->setPrev(p);
    }
    delete v;
}


#endif //DATASTRUCTURED_DOUBLY_LIST_H
