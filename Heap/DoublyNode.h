//DoublyNode especial para Double Linked List
#pragma once
#include <iostream>
using namespace std;

template <class T>
struct DoublyNode{
    T data;
    DoublyNode<T> *prev;
    DoublyNode<T> *next;
    
    DoublyNode(T data);
    DoublyNode(T data, DoublyNode<T> *prev, DoublyNode<T> *next);
};

template<class T>
DoublyNode<T>::DoublyNode(T data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
}
template<class T>
DoublyNode<T>::DoublyNode(T data, DoublyNode<T> *prev, DoublyNode<T> *next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}
