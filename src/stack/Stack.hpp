//
// Created by Massimo Biancalani on 17/09/16.
//

#ifndef DATASTRUCTURED_STACK_HPP
#define DATASTRUCTURED_STACK_HPP
#include <stdexcept>
#include <string>
using namespace std;
namespace structure {

    class StackEmpty : public runtime_error {
    public:
        StackEmpty(const string& str) : runtime_error(str) {};
    };

    template<class E>
    class Stack {
    private:
        static const int DEF_CAPACITY = 100;
        E * root;
        int capacity;
        int topIndex;
    public:
        Stack();

        Stack (int _capacity);

        virtual ~Stack();

        int size() const;

        bool empty() const;

        void push(const E &e);

        void pop() throw(StackEmpty);

        const E &top() const throw(StackEmpty);
    };

    template <class E>
    structure::Stack<E>::Stack(int _capacity):capacity(_capacity),root(new E[_capacity]), topIndex(-1) {
    }
    template <class E>
    Stack<E>::Stack():Stack(DEF_CAPACITY) {
    }
    template <class E>
    bool Stack<E>::empty() const {
        return topIndex < 0;
    };

    template <class E>
    int Stack<E>::size() const {
        return topIndex + 1;
    }
    template <class E>
    void Stack<E>::push(const E &e) {
        if (topIndex >= capacity - 1 ) {
            E* pointer = new E[2*capacity];
            memcpy(pointer, root, capacity * sizeof(E));
            delete[] root;
            root = pointer;
            capacity = 2*capacity;
        }

        root[++topIndex] = e;

    }
    template <class E>
    const E &Stack<E>::top() const throw(StackEmpty) {
        if (this->empty()) {
            throw StackEmpty("The stack is empty");
        }
        return root[topIndex];
    }
    template <class E>
    void Stack<E>::pop() throw(StackEmpty) {
        if (this->empty()) {
            throw StackEmpty("The stack is empty");
        }
        topIndex--;
    }

    template <class E>
    Stack<E>::~Stack() {
        delete[] root;
    };



}

#endif //DATASTRUCTURED_STACK_HPP
