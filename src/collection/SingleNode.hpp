//
// Created by Massimo Biancalani on 15/05/16.
//

#ifndef DATASTRUCTURED_SINGLENODE_H
#define DATASTRUCTURED_SINGLENODE_H


namespace structure {
    template <class T>
    class SingleNode {
    private:
    public:
        const T& getElem() const {
            return elem;
        }

        SingleNode *getNext() const {
            return next;
        }

        void setNext(SingleNode *next) {
            SingleNode::next = next;
        }

        void setElem(const T& elem) {
            SingleNode::elem = elem;
        }

        SingleNode(T elem) : elem(elem) { }

    private:
        T elem;
        SingleNode * next;
    };
}


#endif //DATASTRUCTURED_SINGLENODE_H
