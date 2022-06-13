#ifndef BinaryST_h
#define BinaryST_h
//Estructura de datos jerárquica

#include <vector>
#include "Node.h"
#include "Queue.h"

template<class T>
class BinaryST{
private: 
    Node<T>* root;
    void printTree(Node<T>* aux, int level);
    int howManyChildren(Node<T>* aux);
    void preOrder(Node<T>* aux);
    void inOrder(Node<T>* aux);
    void postOrder(Node<T>* aux);
    void levelByLevel(); //basarme en ejemplo del profe
    //void levelByLevel(Node<T>* aux, Queue& cola);

public: 
    BinaryST();
    void insert(T data);
    bool isEmpty();
    bool find(T data);
    void deleteNode(T data); //terminar
    void visit(int order);

    int height();
    int heightBST(Node<T>* node);
    void ancestors(T data);
    int whatLevelAmI(T data);
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
void BinaryST<T>::deleteNode(T data){
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
void BinaryST<T>::preOrder(Node<T>* aux){
    if(aux!=NULL){
        cout << aux->data << " ";
        preOrder(aux->left);
        preOrder(aux->right);
    }
}

template<class T>
void BinaryST<T>::inOrder(Node<T>* aux){
    if(aux!=NULL){
        inOrder(aux->left); //priemro se va al valor más pequeño del arbol
        cout << aux->data << " ";
        inOrder(aux->right);
    }
}

template<class T>
void BinaryST<T>::postOrder(Node<T>* aux){
    inOrder(aux->left); 
    inOrder(aux->right);
    cout << aux->data << " ";
}

/*
template<class T>
void BinaryST<T>::levelByLevel(Node<T>* aux, Queue& cola){
    cola.enqueue(aux);
    while(!cola.isEmpty()){
        T takenOut = cola.dequeue();
    }
}
*/

template <class T>
void BinaryST<T>::levelByLevel(){
    if (!isEmpty()) {
        Queue< Node<T>* > queue;  //No jala si está pegado                                    
        queue.enqueue(root);                                    
        while (!queue.isEmpty()) { 
            Node<T>* aux = queue.dequeue();             
            cout << aux->data << " ";
            if (aux->left != NULL){
                queue.enqueue(aux->left);
            }
            if (aux->right != NULL){                  
                queue.enqueue(aux->right);
            }
        }
    }
}

template <class T>
void BinaryST<T>::visit(int num){
	switch(num)
	{
	case 1:
		preOrder(root);
		break;
	case 2:
		inOrder(root);
		break;
	case 3:
		postOrder(root);
		break;
	case 4:
		levelByLevel();
		break;
	default:
		break;
	}
}

template<class T>
int BinaryST<T>::heightBST(Node<T>* node) {
    int height = 0;
    int l, r;                                                 
    if (node != NULL) {                                     
        height++;                                            
        l = heightBST(node->left);                         
        r = heightBST(node->right);     
        (l > r) ? height += l : height += r;
    }
    return height;
}

template<class T>
int BinaryST<T>::height() {
    return heightBST(root);
}


template<class T>
void BinaryST<T>::ancestors(T data){
    Node<T>* aux = root;
    vector< Node<T>* > fathers;
    Node<T>* father = NULL;
    while(aux!=NULL){
        father = aux;
        fathers.push_back(father);
        if(aux->data > data){
            aux = aux->left;
        }
        else{
            aux = aux->right;
        }
        if(aux->data==data){
            cout << "Ancestros: " << endl;
            for(int i=0; i<fathers.size(); i++){
                cout << fathers[i]->data;
            }
            cout << endl;
            aux = NULL;
        }
    }
}

template <class T>
int BinaryST<T>::whatLevelAmI(T data) {
    int level = 0;
    if (!isEmpty()) {
        Node<T>* aux = root;
        if (aux->data != data) {
            bool notFound = false;
            while (aux->data != data && !notFound ) {
                level++;
                if (data < aux->data) {
                    if (aux->left == NULL) {
                        notFound = true;
                    } else {                        
                        aux = aux->left;
                    }
                } else {
                    if (aux->right == NULL) {
                        notFound = true;
                    } else {
                        aux = aux->right;
                    }
                }
            }
            if (!notFound) {
                level++;
            } else {
                level = -1;
            }
        } else {
            level = 1;
        }
    } else {
        level = -1;
    }
    return level;
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