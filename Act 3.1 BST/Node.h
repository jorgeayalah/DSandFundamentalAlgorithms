//Node para Binary Search Tree
//05/10/2020
#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T data);
    Node(T data, Node<T> *left, Node<T> *right);
};

template<class T>
Node<T>::Node(T data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}
template<class T>
Node<T>::Node(T data, Node<T> *left, Node<T> *right){
    this->data = data;
    this->left = left;
    this->right = right;
}