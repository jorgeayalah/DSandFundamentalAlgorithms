#ifndef HashL_h
#define HashL_h

#include <vector>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

//Hashing no aplica con template pque es muy específico a cada caso
class HashL{
private:
    vector<string> table;
    int size, qty;
    vector<int> status; //0=vacío, 1=ocupado, 2=borrado
    int hashing(string data);
    int linearTest(int index);
    int linearFind(int index, string data);
public:
    HashL(vector<string> list);
    void addData(string data);
    void deleteData(string data);
    int findData(string data);
    bool isFull();
    void print();
};

HashL::HashL(vector<string> list){
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

void HashL::addData(string data){
    if(!isFull()){
        qty++;
        int index = hashing(data); //Fucnión Hashing
        int newIndex = linearTest(index); //Manejo de colisiones con prueba cuadrática
        table[newIndex] = data;
        status[newIndex] = 1; //Actualizar estado a ocupado
    }
}

int HashL::hashing(string data){
    int key = 0;
    for(auto c:data){
        key += (unsigned char)c;
    }
    int index = 0;
    return key%size;
}


int HashL::linearTest(int index){ //Prueba cuadrática para manejo de colisiones
    if(status[index]!=1){ //condiciona que no esté ocuapada, puede ser borrada o vacía
        return index;
    }
    int cont = 1;
    int  newIndex = index;
    while(status[newIndex]==1 || newIndex<0){
        newIndex = fmod((newIndex+1),size);
        cont++;
    }
    return newIndex;
}

int HashL::linearFind(int index,string data){
    int cont = 1;
    int newIndex=index;
    while(table[newIndex]!=data){
        newIndex = fmod((newIndex+1),size);
        cont++;
    }
    return newIndex;
}

int HashL::findData(string data){
    int index = hashing(data);
    if(table[index] == data){
        return index;
    }
    int newIndex = linearFind(index,data);
    return newIndex;
}

bool HashL::isFull(){
    return size == qty;
}

void HashL::print(){
    for(auto i : table){
        cout << i << ", ";
    }
    cout << endl;
}

#endif