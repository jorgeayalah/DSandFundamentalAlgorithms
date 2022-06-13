#pragma once
#include <iostream>
//checar ppt de memoria dinámica
using namespace std;

template <class T>
struct Nodo{
    T data;
    Nodo<T> *next;
    Nodo(T data);
    Nodo(T data, Nodo<T> *next);
};

template<class T>
Nodo<T>::Nodo(T data){
    this->data = data;
    this->next = NULL;
}
template<class T>
Nodo<T>::Nodo(T data, Nodo<T> *next){
    this->data = data;
    this->next = next;
}
