//#ifndef LinkedList_h
#define LinkedList_h
#include "Nodo.h"


template<class T>
class LinkedList{
private:
    Nodo<T> *head; 
    int size;
public:
    LinkedList();
    void addFirst(T data);
    void addLast(T data);
    bool isEmpty();
    bool deleteData(T data);
    bool deleteAt(int index);
    T getData(T index);
    bool updateAt(T valor, int index);
    bool updateData(T valor, T replace);
    int findData(T data);

/*
    bool insertAt(T data, int index);
    void clear();
    void sort();
    void duplicate();
    void reverse();
    */

    void print();
};

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
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
        while(aux->next == NULL){
            aux = aux->next;
        }
        aux->next = new Nodo<T>(data);
    }
    else{
        head = head = new Nodo<T>(data);
    }

}

template<class T>
bool LinkedList<T>::isEmpty(){
    return size==0;
}


template<class T>
bool LinkedList<T>::deleteData(T data){
    if(!isEmpty()){
        Nodo<T> *aux = head;
        if(aux->data==data){
            head = aux->next;
            size--;
            delete aux;
            return true;
        }
        else{
            if(aux->data != NULL){
                Nodo<T>* prev = aux;
                aux = aux->next;
                while(aux->data != NULL){
                    if(aux->data == data){
                        prev->next = aux->next;
                        size--;
                        delete aux;
                        return true;
                    }
                    aux = aux->next;
                }
                if(aux->data == data){
                    prev->next = aux->next;
                    size--;
                    delete aux;
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    else 
        return false;
}

template<class T>
bool LinkedList<T>::deleteAt(int index){
    if (index >= 1 && index <= size){
        if(index == 1){
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
                int i = 2;
                while(aux!= NULL){
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


template<class T>
T LinkedList<T>::getData(T index){
    if(index >= 1 && index <= size){
        Nodo<T>* aux = head;
        int i = 1;
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
bool LinkedList<T>::updateAt(T valor, int index){
    if(!isEmpty()){
        if(index >= 1 && index <= size){
            if(index == 1){
                head->data = valor;
                return true;
            }
            else{   
                if(head->next !=NULL){
                    Nodo<T>* aux = head->next;
                    int i = 2;
                    while(aux != NULL){
                        if(i == index){
                        aux->data = valor;
                        return true;
                        }
                        else{
                            aux = aux->next;
                        }
                        i++;
                    }   
                }
            }
        }
    }
    return false;
}

template<class T>
bool LinkedList<T>::updateData(T valor, T replace){
    if(!isEmpty()){
        if(head->data == valor)
        {
            Nodo<T>* aux = head;
            head = aux->next;
            aux->data = replace;
            return true;
        } 
        else {
            if(head->next != NULL)
            {
                Nodo<T>* aux = head->next;
                while(aux != NULL)
                {
                    if(aux->data == valor)
                    {
                        aux->data = replace;
                        return true;
                    }
                    else{
                        aux = aux->next;
                    }
                }
            }
        }
    }
    return true;
}

template<class T>
int LinkedList<T> ::findData(T data){
    int cont = 0;
    if(!isEmpty()){
        Nodo<T>* aux = head;
        cont++;
        if(aux->data == data){
            return cont;
        }
        else{
            cont++;
            if(aux->next == NULL){
                aux = aux->next;
                while(aux->next != NULL){
                    if(aux->data == data){
                        return cont;
                    }
                    cont++;
                    aux = aux->next;
                }
                if(aux->data == data){
                    return cont;
                }
            }
            else{
                throw out_of_range("El dato no existe en la lista");
            }

        }
    }
    else{
        throw out_of_range("El dato no existe en la lista");
    }
    throw out_of_range("El dato no existe en la lista");
}
/*
//Terminar metodo
template<class T>
void LinkedList<T>::reverse(){
    LinkedList<T> listAux;
    Node<T>* aux = head;
    while
}
*/
template<class T>
void LinkedList<T>::print(){
    Nodo<T>* aux = head;
    for(int i=0; i<size; i++){
        cout << aux->data << endl;
        aux = aux->next;
    }
}
//#endif                