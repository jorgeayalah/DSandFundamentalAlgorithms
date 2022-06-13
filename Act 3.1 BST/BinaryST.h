#ifndef BinaryST_h
#define BinaryST_h
//Estructura de datos jerárquica

#include "Node.h"
#include "Queue.h"

template<class T>
class BinaryST{
private: 
    Node<T>* root;
    void printTree(Node<T>* aux, int level);
public: 
    BinaryST();
    void insert(T data);
    bool isEmpty();
    int howManyChildren(Node<T>* aux);
    bool find(T data); //terminar
    void deleteNode(T data); //terminar
    void print();
};

template<class T>
BinaryST<T>::BinaryST(){
    root = NULL;
}

template<class T>
void BinaryST<T>::insert(T data){
    if(isEmpty()){
        root = new Node<T>(data);
    }
    else{
        Node<T>* aux = root;
        while (aux != NULL){
            if(data < aux->data){
                if(aux->left== NULL){
                    aux->left = new Node<T>(data);
                    return;
                }
                else{
                    aux = aux->left;
                }
            }
            else{
                if(aux->right == NULL){
                    aux->right = new Node<T>(data);
                    return;
                }
                else{
                    aux = aux->right;
                }
            }
        }
        
    }
}


template<class T>
bool BinaryST<T>::isEmpty(){
    return root == NULL;
}

template<class T>
int BinaryST<T>::howManyChildren(Node<T>* aux){
    int cont = 0;
    aux->left != NULL ? cont++: cont = cont;
    aux->right != NULL ? cont++: cont = cont;
    return cont;
}

template<class T>
bool BinaryST<T>::find(T data){
    Node<T>* aux = root;
    bool found = false;
    while(!found && aux != NULL){
        if(aux->data == data){
            found = true;
        }
        else{
            if(data < aux->data){
                aux = aux->left;
            } else{
                aux = aux->right;
            }
        }
    }
    return found;
}

template<class T>
void BinaryST<T>::deleteNode(T data) {
    if (!isEmpty()) {
        // Buscar el dato a borrar
        Node<T>* father = root;
        Node<T>* aux = father;
        bool found = false;
        while (!found && aux!=NULL) {
            if (data == aux->data) {
                found = true;
            } else {
                father = aux;
                data < aux->data ? aux = aux->left : aux = aux->right;
            }
        }
        if (found) {
            switch (howManyChildren(aux)){
            case 0: { //Caso en el que está en el root
                if (aux == root) {  
                    delete aux;                  
                    root = NULL;
                } else { //Afecta nodo hijo izquierdo o derecho según sea
                    data < father->data ? father->left = NULL : father->right = NULL;
                    delete aux;
                }
            }
            break;
            case 1: {
                if (aux == root) { //verifica si la nueva root está a la izq o la der
                    root->left != NULL ? root = root->left : root = root->right;
                } else {
                    if (data < father->data) {
                        aux->left != NULL ? father->left = aux->left : father->left = aux->right;
                    } else {
                        aux->left != NULL ? father->right = aux->left : father->right = aux->right;
                    }
                }
                delete aux;
            }
            break;
            case 2: {
                Node<T>* father = aux;
                Node<T>* max = aux->left; 
                if (max->right == NULL) {
                    aux->data = max->data;
                    father->left = max->left;
                    delete max;
                } else {
                    bool found = false;
                    while (!found) {
                        if (max->right == NULL) {
                            found = true;
                        } else {
                            father = max; 
                            max = max->right; 
                        }
                    }
                    aux->data = max->data;
                    father->right = max->left; 
                    delete max;
                }
            }
            break;
            }
        }
    }
}

template<class T>
void BinaryST<T>::printTree(Node<T>* aux, int level){
    if(aux != NULL){
        printTree(aux->right, level+1);
        for(int i = 0; i<level; i++){
            cout << "   ";
        }
        cout << aux->data << endl;
        printTree(aux->left, level+1);
    }
}


template<class T>
void BinaryST<T>::print(){
    int level = 0;
    cout << endl;
    printTree(root, level);
    cout << endl;
}

#endif