/// Jorge Ayala
/// Creado el 21/09/2020
/// Editado el 23/10/2020
#ifndef LinkedList_h
#define LinkedList_h

#include <exception>
#include "Nodo.h"
#include "Queue.h"


template<class T>
class LinkedList{
private:
    Nodo<T> *head; 
    int size;
    void mergeSortIter(int ini, int med, int fin);
    void mergeSort(int ini, int fin);

public:
    LinkedList();
    void addFirst(T data);
    void addLast(T data);
    bool isEmpty();
    bool deleteData(T data);
    bool deleteAt(int index);
    T getData(int index);
    void updateAt(T valor, int index);
    void updateData(T valor, T replace);
    int findData(T data);

/*
    bool insertAt(T data, int index);
    */

    void duplicate();
    void removeDuplicates();
    void sort();
    void clear();
    void reverse();
    void operator=(initializer_list<T> list);
    T& operator[](int index);
    void print();
};

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}

template<class T>
T& LinkedList<T>::operator[](int index){
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
    cout << index << endl;
    throw out_of_range("Posición inválidaa");
}

template<class T>
void LinkedList<T>::addFirst(T data){
    head = new Nodo<T>(data, head);
    size++;
}


template<class T>
void LinkedList<T>::addLast(T data){
    if(!isEmpty()){
        Nodo<T>* aux = head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new Nodo<T>(data);
        size++;
    }
    else{
        head = new Nodo<T>(data);
    }

}

template<class T>
bool LinkedList<T>::isEmpty(){
    return size==0;
}


template<class T>
bool LinkedList<T>::deleteData(T data){
    if(!isEmpty()){
        if(head->data == data){
            Nodo<T>* aux = head;
            head = aux->next;
            delete aux;
            size--;
            return true;
        }
        else{
            if(head->next != NULL){
                Nodo<T>* aux = head;
                Nodo<T>* prev = head;
                while(aux != NULL){ //Hace el intercambio de apuntadores previo a eliminar valor
                    if(aux->data == data){
                        prev->next = aux->next;
                        size--;
                        delete aux;
                        return true;
                    }
                    else{
                        prev = aux;
                        aux = aux->next;
                    }
                }
            }
        }
    }
    return false;
}

template<class T>
bool LinkedList<T>::deleteAt(int index){
    if(!isEmpty()){
        if (index >= 0 && index<size){
            if(index == 0){
                Nodo<T>* aux = head->next;
                head = aux->next;
                delete aux;
                size--;
                return true;
            }
            else{
                if(head->next!= NULL){
                    Nodo<T>* aux = head->next;
                    Nodo<T>* prev = head;
                    int i = 1;
                    while(aux != NULL){
                        if(i == index){
                            prev->next = aux->next;
                            delete aux;
                            size--;
                            return true;
                        }
                        else{
                            prev = aux;
                            aux = aux->next;
                        }
                        i++;
                    }
                }
            }
        }
        return false;
    }
    return false;
}


template<class T>
T LinkedList<T>::getData(int index){
    if(index >= 0 && index<size){ //Se asegura de que sea un índice válido
        Nodo<T>* aux = head;
        int i = 0;
        while(aux!=NULL){
            if(i == index){
                return aux->data;
            }
            aux = aux->next;
            i++;
        }
    }
    throw out_of_range("Invalid position");
}

template<class T>
void LinkedList<T>::updateAt(T valor, int index){
    if(!isEmpty()){
        if(index >= 0 && index <size){
            Nodo<T>* aux = head;
            int i = 0;
            while(aux != NULL){
                if(i == index){
                    aux->data = valor;
                    return;
                }
                else{
                    aux = aux->next;
                }
                i++;
            }   
        }

        throw out_of_range("Invalid position");
    }
    throw out_of_range("List is empty");
}

template<class T>
void LinkedList<T>::updateData(T valor, T replace){
    if(!isEmpty()){
        Nodo<T>* aux = head;
        while(aux != NULL){
            if(aux->data == valor){
                aux->data = replace;
                return;
            }
            else{
                aux = aux->next;
            }
        }
        throw out_of_range("Value not found");
    }
    throw out_of_range("List is empty");
}

template<class T>
int LinkedList<T>::findData(T data){
    Nodo<T>* aux = head;
    int cont = 0;
    while(aux != NULL){
        if(aux->data == data){
            return cont;
        }
        cont++;
        aux = aux->next;
    }
    throw out_of_range("El dato no existe en la lista");
}

//nuevos

template<class T>
void LinkedList<T>::clear(){
    int i = 0;
    while(i<size){
        Nodo<T>* aux = head;
        head = aux->next;
        delete aux;
        i++;
    }
    size = 0;
}


// O(n)
template<class T>
void LinkedList<T>::mergeSortIter(int ini, int med, int fin){
    Queue<T> listaIzq; //Incorporación de Queue
    Queue<T> listaDer;
    LinkedList<T> lista = *this;
    int tamI, tamD, i, j;

    tamI = med-ini+1;
    tamD = fin-med;
    for (i=0; i<tamI; i++){ //izquierda
        listaIzq.enqueue(lista[ini+i]);
    }
    for (j=0; j<tamD; j++){ //derecha
        listaDer.enqueue(lista[med+1+j]);
    }
    i=0; j=0;
    int pos = ini;
    while(i<tamI && j<tamD){ //acomodo de menores que
        if(listaIzq[i] <=listaDer[j]){
            updateAt(listaIzq[i], pos);
            i++;
        }
        else{
            updateAt(listaDer[j], pos);
            j++;
        }
        pos++;
    }
    while(i<tamI){ //acomodo de restantes ya ordenados
        updateAt(listaIzq[i], pos);
        i++;
        pos++;
    }
    while(j<tamD){
        updateAt(listaDer[j], pos);
        j++;
        pos++;
    }
}

/*
template<class T>
void LinkedList<T>::mergeSortIter(int ini, int med, int fin) {
    LinkedList<T> listaIzq;
    LinkedList<T> listaDer;
    int pos,f1,f2,i,j;
    pos = ini;
    f1 = med - ini + 1;
    f2 = fin - med;   
    for (i=1;i<=f1;i++){
        listaIzq.addLast(getData(ini+i-1));
    }
    for (j=1;j<=f2;j++) {
        listaDer.addLast(getData(med+1+j-1));
    }
    i = 1;
    j = 1;
    cout << "iterativo" << endl;
    while (i<=f1 && j<=f2) {
        cout << "error" << endl;
        if (listaIzq[i]<=listaDer[j]) {
            updateAt(listaIzq[i], pos);
            i++;
        } else {
            updateAt(listaDer[j], pos);
            j++;
        }
        pos++;
    }
    
    while (i<=f1) {
        updateAt(listaIzq[i], pos);
        i++;
        pos++;
    }
    
    while (j<=f2) {
        updateAt(listaDer[j], pos);
        j++;
        pos++;
    }
}
*/

// merge recursivo
// O(n log n)
template<class T>
void LinkedList<T>::mergeSort(int ini, int fin){
    int med;
    if (ini<fin){
        med = (ini + fin)/2;
        mergeSort(ini, med);
        mergeSort(med+1, fin);

        mergeSortIter(ini, med, fin);
    }
}


template<class T>
void LinkedList<T>::sort(){
    mergeSort(0, size-1);
}

template<class T>
void LinkedList<T>::duplicate(){
    Nodo<T>* aux = head;
    while(aux != NULL){
        aux->next = new Nodo<T>(aux->data, aux->next);
        aux = aux->next->next;
        size++;
    }
}

template<class T>
//Repasar funcionamiento
void LinkedList<T>::removeDuplicates(){
    Nodo<T>* aux = head;
    LinkedList<T> list = *this;
    clear();
    for (int i=0; i<list.size; i++) {
        cout << "Profe me truena por la excepción de findData" << endl;
        if (!findData(aux->data)) {
            addLast(aux->data);
        }
        aux = aux->next;
    }
}

template<class T>
void LinkedList<T>::reverse(){
    LinkedList<T> listAux;
    Nodo<T>* aux = head;
    while(aux != NULL){
        listAux.addFirst(aux->data);
        aux = aux->next;
    }
    *this = listAux;
}

template<class T>
void LinkedList<T>::operator=(initializer_list<T> list){
    if (isEmpty()) {
        for (T i : list) {
            addLast(i);
        }
    } else {
        throw runtime_error("Error: LinkedList no esta vacia");   
    }
    /*clear();
    for(int i = 0; i<list.size; i++){
        addLast(list[i]);
    }*/
}

template<class T>
void LinkedList<T>::print(){
    Nodo<T>* aux = head;
    for(int i=0; i<size; i++){
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}
#endif                