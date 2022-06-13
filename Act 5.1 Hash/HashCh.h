#ifndef HashCh_h
#define HashCh_h

#include <vector>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

//Hashing no aplica con template pque es muy específico a cada caso
class HashCh{
private:
    vector< vector<string> > table;
    int size, qty;
    vector< vector<int> > status; //0=vacío, 1=ocupado, 2=borrado
    int hashing(string data);
    int chainTest(int index, int& cont);
    int chainFind(int index, string data);
public:
    HashCh(vector<string> list);
    void addData(string data);
    void deleteData(string data);
    int findData(string data);
    bool isFull();
    void print();
};

HashCh::HashCh(vector<string> lista){
    //size = list.size();
    size = 53;
    vector< vector<string> >  tmpTable;
    for(int i = 0; i<size; i++){
        vector<string> temp = {" "};
        tmpTable.push_back(temp);
    }
    table = tmpTable;
    vector< vector<int> > tmpStatus(size);
    status = tmpStatus;
    
    int index, newIndex;
    for(auto data:lista){
        addData(data);
    }

}

void HashCh::addData(string data){
    if(!isFull()){
        int cont=0;
        qty++;
        int index = hashing(data); //Fucnión Hashing
        int newIndex = chainTest(index, cont); //Manejo de colisiones con prueba cuadrática
        
        table[index].push_back(data);
        status[index][cont] = 1; //Actualizar estado a ocupado
    }
}

int HashCh::hashing(string data){
    int key = 0;
    for(auto c:data){
        key += (unsigned char)c;
    }
    int index = 0;
    return key%size;
}

int HashCh::chainTest(int index, int& cont){ //Prueba encadenamiento para manejo de colisiones
    if(status[index][cont]!=1){ //condiciona que no esté ocuapada, puede ser borrada o vacía
        return index;
    }
    int  newIndex = index;
    string aux = table[index].front();
    while(status[newIndex][cont]==1){
        cont++;
    }
    return newIndex;
}

int HashCh::chainFind(int index, string data){
    int cont = 0;
    if(status[index][cont]!=1){ //condiciona que no esté ocuapada, puede ser borrada o vacía
        return index;
    }
    int  newIndex = index;
    string aux = table[index].front();
    while(status[newIndex][cont]==1){
        cont++;
    }
    return newIndex;
}

int HashCh::findData(string data){
    int index = hashing(data);
    for(int i =0; i<table[index].size(); i++){
        if(table[index][i] == data){
            return index;
        }
    }
    int newIndex = chainFind(index,data);
    return newIndex;
}

bool HashCh::isFull(){
    return size == qty;
}

void HashCh::print(){
    for(auto i : table){
        for(int j = 0; j<i.size(); j++){
            cout << i[j] << ", ";
        }
    }
    cout << endl;
}

#endif