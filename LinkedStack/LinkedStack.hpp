#ifndef __LINKEDSTACK_H
#define __LINKEDSTACK_H

#include <iostream>
#include "Chain.hpp"
#include "Stack.hpp"

template <class T>
class LinkedStack : public Stack<T>{
    template <class Y>
    friend std::ostream& operator<<(std::ostream&, const LinkedStack<Y>&);
private:
    chainNode<T> *stackTop;
    size_t stackSize;
public:
    LinkedStack();
    LinkedStack(const LinkedStack<T>&);

    ~LinkedStack();
    bool empty() const {return stackSize == 0;}
    size_t size() const {return stackSize;}
    T& top() const;
    void pop();
    void push(const T&);

    void pushNode(const chainNode<T>&);
    chainNode<T> popNode();
};

template <class T>
LinkedStack<T>::LinkedStack():
stackTop(nullptr),
stackSize(0) 
{}

template <class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& Stack) {
    chainNode<T> *p = this->stackTop,
                 *t = Stack.stackTop;
    for(size_t i = 0; i < Stack.stackSize; ++i, p=p->next, t=t->next) {
        p->element = t->element;
    }
}

template <class T>
LinkedStack<T>::~LinkedStack() {
    chainNode<T> *p = stackTop;
    for(size_t i = 0; i < stackSize; ++i) {
        p = p->next;
        std::cout << "[~LinkedStack] Destroy " << stackTop->element << std::endl;
        delete stackTop;
        stackTop = p;
    }
}

template <class T>
T& LinkedStack<T>::top() const {
    if(stackTop == nullptr) {
        throw "The Stack is empty!";
    }
    return stackTop->element;
}

template <class T>
void LinkedStack<T>::push(const T& element) {
    stackTop = new chainNode<T>(element, stackTop);
    stackSize++;
}

template <class T>
void LinkedStack<T>::pop() {
    if(stackTop == nullptr) {
        throw "The Stack is empty!";
    }
    chainNode<T> *deleteNode = stackTop;
    stackTop = stackTop->next;
    delete deleteNode;
    stackSize--;
}

template <class T>
void LinkedStack<T>::pushNode(const chainNode<T>& node) {    
    stackTop = new chainNode<T>(node.element, stackTop);
    stackSize++;
}

template <class T>
chainNode<T> LinkedStack<T>::popNode() {
    if(stackTop == nullptr) {
        throw "The Stack is empty!";
    }
    chainNode<T> *p = stackTop;
    chainNode<T> NODE(p->element);
    stackTop = stackTop->next;
    delete p;
    stackSize--;
    return NODE;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& Stack) {
    chainNode<T> *p = Stack.stackTop;
    for(size_t i = 0; i < Stack.stackSize; ++i, p=p->next) {
        out << p->element << " ";
    }
    return out;
}

#endif // __LINKEDSTACK_H
