#ifndef HashQ_h
#define HashQ_h

#include <vector>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

//Hashing no aplica con template pque es muy específico a cada caso
class HashQ{
private:
    vector<string> table;
    int size, qty;
    vector<int> status; //0=vacío, 1=ocupado, 2=borrado
    int hashing(string data);
    int quadTest(int index);
    int quadProbe(int index, int cont);
    int quadFind(int index, string data);
public:
    HashQ(vector<string> list);
    void addData(string data);
    void deleteData(string data);
    int findData(string data);
    bool isFull();
    void print();
};

HashQ::HashQ(vector<string> list){
    //size = list.size();
    size = 53;
    vector<string> tmpTable(size);
    table = tmpTable;
    vector<int> tmpStatus(size);
    status = tmpStatus;
    
    int index, newIndex;
    for(auto data:list){
        addData(data);
    }

}

void HashQ::addData(string data){
    if(!isFull()){
        qty++;
        int index = hashing(data); //Fucnión Hashing
        int newIndex = quadTest(index); //Manejo de colisiones con prueba cuadrática
        table[newIndex] = data;
        status[newIndex] = 1; //Actualizar estado a ocupado
    }
}

int HashQ::hashing(string data){
    int key = 0;
    for(auto c:data){
        key += (unsigned char)c;
    }
    int index = 0;
    return key%size;
}

int HashQ::quadTest(int index){ //Prueba cuadrática para manejo de colisiones
    if(status[index]!=1){ //condiciona que no esté ocuapada, puede ser borrada o vacía
        return index;
    }
    int cont = 1;
    int  newIndex = index;
    while(status[newIndex]==1 || newIndex<0){
        //Falta validar que no se puedan agregar repetidos
        //newIndex = (newIndex + cont*cont)%size; //funcion abierta de manejo de excepciones
        newIndex = fmod((index + pow(-1, cont-1)*pow((cont+1)/2,2)),size);
        cont++;
    }
    return newIndex;
}

int HashQ::quadFind(int index,string data){
    int cont = 1;
    int newIndex=index;
    while(table[newIndex]!=data){
        newIndex = fmod((index + pow(-1, cont-1)*pow((cont+1)/2,2)),size);
        cont++;
    }
    return newIndex;
}

int HashQ::findData(string data){
    int index = hashing(data);
    if(table[index] == data){
        return index;
    }
    int newIndex = quadFind(index,data);
    return newIndex;
}

bool HashQ::isFull(){
    return size == qty;
}

void HashQ::print(){
    for(auto i : table){
        cout << i << ", ";
    }
    cout << endl;
}

#endif