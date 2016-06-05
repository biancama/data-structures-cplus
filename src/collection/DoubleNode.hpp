//
// Created by Massimo Biancalani on 04/06/16.
//

#ifndef DATASTRUCTURED_DOUBLENODE_HPP
#define DATASTRUCTURED_DOUBLENODE_HPP

#include "SingleNode.hpp"
namespace structure {

    template <class T>
    class DoubleNode  {
    private:
        DoubleNode* prev;
        T elem;
        DoubleNode * next;
    public:
        DoubleNode(T elem): elem(elem) { prev = nullptr; next= nullptr;}

        DoubleNode* getPrev() const {
            return prev;
        }
        void setPrev(DoubleNode* prev){
            this->prev = prev;
        }
        const T& getElem() const {
            return elem;
        }

        DoubleNode *getNext() const {
            return next;
        }

        void setNext(DoubleNode *next) {
            DoubleNode::next = next;
        }

        void setElem(const T& elem) {
            DoubleNode::elem = elem;
        }
    };
};

#endif //DATASTRUCTURED_DOUBLENODE_HPP
