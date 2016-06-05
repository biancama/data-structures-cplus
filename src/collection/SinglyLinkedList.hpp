//
// Created by Massimo Biancalani on 14/05/16.
//

#ifndef DATASTRUCTURED_SINGLY_LIST_H
#define DATASTRUCTURED_SINGLY_LIST_H

#include "SingleNode.hpp"
#include "../exception/IndexOutOfBoundsException.h"
namespace structure {
    template <class T>
    class SinglyLinkedList {

    private:
        SingleNode<T> *head;
        unsigned int sizeOfList;

        SingleNode<T> *get(int i, SingleNode<T> *nodePtr) const;

    public:
        SinglyLinkedList();

        virtual ~SinglyLinkedList() { while (!isEmpty()) {
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
unsigned int structure::SinglyLinkedList<T>::size() const {
    return sizeOfList;
}
template <class T>
structure::SinglyLinkedList<T>::SinglyLinkedList() :head(nullptr), sizeOfList(0) {
}
template <class T>
bool structure::SinglyLinkedList<T>::isEmpty() {
    return head == nullptr;
}
template <class T>
const T& structure::SinglyLinkedList<T>::get(int i) const{
    if (i < 0 || i > sizeOfList - 1 ) {
        throw new IndexOutOfBoundsException();
    }
    SingleNode<T>* pointer = get(i, head);
    return pointer->getElem();
}
template <class T>
structure::SingleNode<T>* structure::SinglyLinkedList<T>::get(int position, structure::SingleNode<T> *nodePtr) const{
    for (int i = 0; i < position; ++i) {
        nodePtr = nodePtr->getNext();
    }
    return nodePtr;
}
template <class T>
const T& structure::SinglyLinkedList<T>::first() const{
    return get(0);
}
template <class T>
void structure::SinglyLinkedList<T>::addFirst(const T &e) {
    add(0, e);
}
template <class T>
const T &structure::SinglyLinkedList<T>::last() const {
    return get(sizeOfList - 1);
}
template <class T>
void structure::SinglyLinkedList<T>::set(int i, const T & e)  {
    if (i < 0 || i > sizeOfList - 1 ) {
        throw new IndexOutOfBoundsException();
    }
    SingleNode<T>* pointer = get(i, head);
    pointer->setElem(e);
}
template <class T>
void structure::SinglyLinkedList<T>::add(int i, const T &e) {
    if (i < 0 || i > sizeOfList ) {
        throw new IndexOutOfBoundsException();
    }
    sizeOfList++;
    SingleNode<T>* v = new SingleNode<T>(e);
    if (i == 0) {
        v->setNext(head);
        head = v;
    } else {
        SingleNode<T>* pointer = get(i - 1, head);
        v->setNext(pointer->getNext());
        pointer->setNext(v);
    }
}

template <class T>
void structure::SinglyLinkedList<T>::remove(int i) {
    if (i < 0 || i > sizeOfList ) {
        throw new IndexOutOfBoundsException();
    }
    sizeOfList--;
    SingleNode<T>* v = head;
    if (i == 0) {
        head = v->getNext();
    } else {
        SingleNode<T>* v_app = get(i - 1, head);
        v =  v_app->getNext();
        v_app->setNext(v_app->getNext()->getNext());
    }
    delete v;

}
template <class T>
void structure::SinglyLinkedList<T>::addLast(const T &e) {
    add(sizeOfList, e);
}

template <class T>
void structure::SinglyLinkedList<T>::removeFirst() {
    remove(0);
}


#endif //DATASTRUCTURED_SINGLY_LIST_H
