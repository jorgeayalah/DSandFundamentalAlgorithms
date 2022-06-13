//Jorge Ayala
//Creado el 06/10/2020
//Editado el 07/10/2020
#include "Nodo.h"

template<class T>
struct Queue{
//private:
    Nodo<T>* head;
    Nodo<T>* tail;
    int size;
//public:
    Queue();
    T dequeue();
    void enqueue(T data);
    T front(){return head->data();};
    T back(){return tail->data();};
    //int getSize(){return size;};
    void clear();
    bool isEmpty(){return size==0;}
    T& operator[](int index);
    void print();
};

template<class T>
Queue<T>::Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
T Queue<T>::dequeue(){
    if(!isEmpty()){
        Nodo<T>* aux = head;
        head = head->next;
        size--;
        return aux->data;
    }
    throw out_of_range("Lista vacía");
}

template<class T>
void Queue<T>::enqueue(T data){
    Nodo<T>* aux = new Nodo<T>(data);
    if(!isEmpty()){
        tail->next = aux;
        tail = tail->next;
    } else{
        head = aux;
        tail = head;
        //tail = aux;
    }
    size++;
}

template<class T>
void Queue<T>::clear(){
    if(!isEmpty()){
        for(int i = 0; i<size; i++){
            Nodo<T>* aux = head;
            head = head->next;
            delete aux;
        }
        tail = head;
        size = 0;
    }
}

template<class T>
T& Queue<T>::operator[](int index){
    if(index>=0 && index<size){
        Nodo<T>* aux = head;
        int i = 0;
        while(aux!= NULL){
            if(i==index){
                return aux->data;
            }
            aux = aux->next;
            i++;
        }
    }
    throw out_of_range("Posición invalida");
}

template<class T>
void Queue<T>::print(){
    if(!isEmpty()){
        Nodo<T>* aux = head;
        for(int i = 0; i<size; i++){
            cout << aux->data << " ";
            aux = aux->next;
        }
        cout << endl;
    }
    else{
        cout << "Lista sin datos" << endl;
    }
}
