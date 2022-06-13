#pragma once

#include "DoublyLinkedList.h"
#include "NodeD.h"

template<class t>
class Heap{
private:
    DoublyLinkedList<T> heap;
    void downSort(int index);
    int size;

public:
    Heap();
    Heap(DoublyLinkedList<T> list);
    bool isEmpty();
    void print();
};

template<class T>
Heap<T>::Heap(){
    size = 0;
}

template<class T>
Heap<T>::Heap(DoublyLinkedList<T> list){
    if(!isEmpty()){
        heap = list;
        size = heap.getSize();
        int index = size/2;
                      
    }
}

template<class T>
bool Heap<T>::isEmpty() {
    return size == 0;
}

template<class T>
void Heap<T>::downSort(int index) {
    while(index >= 1){

    }
}
