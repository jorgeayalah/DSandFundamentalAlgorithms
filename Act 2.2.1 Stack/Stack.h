/// Jorge Ayala
/// Creado el 01/10/2020
/// Editdo el 23/10/2020
#ifndef Stack_h
#define Stack_h

#include "Nodo.h"
using namespace std;


template<class T>
class Stack{
private:
    Nodo<T> *top;
    int size;
public:
    Stack();
    T pop();
    void push(T data);
    T getTop();
    int getSize(){return size;};
    void clear();
    bool isEmpty();
    void print();
};

template<class T>
Stack<T>::Stack(){
    top = NULL;
    size = 0;
}

template<class T>
T Stack<T>::pop(){
    if(!isEmpty()){
        T data;
        Nodo<T>* aux = top;
        data = aux->data;
        top = top->next;
        delete aux;
        size--;
        return data;
    }
    throw out_of_range("Empty stack");
}

template<class T>
void Stack<T>::push(T data){
    top = new Nodo<T>(data, top);
    size++;
}

template<class T>
T Stack<T>::getTop(){
    if(!isEmpty()){
        return top->data;
    }
    throw out_of_range("Empty stack");
}

template<class T>
bool Stack<T>::isEmpty(){
    return size == 0;
}

template<class T>
void Stack<T>::clear(){
    if(!isEmpty()){
        while(top != NULL){
        Nodo<T>* aux = top;
        top = top->next;
        delete aux;
        }
        size = 0;
    }
}

template<class T>
void Stack<T>::print(){
    Nodo<T>* aux = top;
    for(int i=0; i<size; i++){
        cout << aux->data << endl;
        aux = aux->next;
    }
}

#endif