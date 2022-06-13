/// Jorge Ayala
/// Creado el 21/09/2020
/// Editado el 23/10/2020
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>

using namespace std;
#include "LinkedList.h"
/*
void verifyDelete(bool check){
    if(!check)
        cout << "Elemento eliminado con éxito" << endl;
    else
    {
        cout << "El elemento no se encuentra en la lista" << endl;
        cout << check << endl;
    }
}
void verifyUpdate(bool check){
    if(check == true)
        cout << "Elemento actualizado con éxito" << endl;
    else
    {
        cout << "El elemento no se encuentra en la lista" << endl;
    }
}*/


template<class T>
void exceptionGet(int pos, T list){
    try{
        cout << list.getData(pos) << endl;
    }
    catch(out_of_range& e){
        cout << e.what() <<  endl;
    }
}

template<class T>
void verifyUpdate(bool check, LinkedList<T> list){
    if(check){
        list.print();
    } else{
        cout << "Operación no exitosa" << endl;
    }
}

int main(){
    LinkedList<int> list, caliz;
    char opc;
    int value, toFind, index;

    //Inicializa lista con ciertos valores
    list.addFirst(5);
    list.addLast(10);
    list.addLast(11);
    list.addLast(2);
    list.addLast(12);
    list.addLast(13);
    list.addLast(14);
    list.addLast(1);

    while(opc!='z'){
        cout << "\t" << "M E N Ú" << endl;
        cout << "Ingrese un comando de los siguientes para usar determinado método: " << endl;
        cout << "\t" << "a) addFirst " << endl;
        cout << "\t" << "b) addLast" << endl;
        cout << "\t" << "c) deleteData" << endl;
        cout << "\t" << "d) deleteAt" << endl;
        cout << "\t" << "e) getData" << endl;
        cout << "\t" << "f) updateAt" << endl;
        cout << "\t" << "g) updateData" << endl;
        cout << "\t" << "h) findData" << endl;
        cout << "\t" << "i) clear" << endl;
        cout << "\t" << "j) sort" << endl;
        cout << "\t" << "k) duplicate" << endl;
        cout << "\t" << "l) removeDuplicates" << endl;
        cout << "\t" << "m) operator=" << endl;
        cout << "\t" << "n) reverse" << endl;
        cout << "\t" << "p) print" << endl;

        cout << "\t" << "z) Salir" << endl;
        cin >> opc;
        switch (opc){
        case 'a': //addFirst
            cout << "Ingrese valor a insertar en la lista encadenada: " << endl;
            cin >> value;
            list.addFirst(value);
            break;
        case 'b': //addLast
            cout << "Ingrese valor a insertar al últimop de la lista encadenada: " << endl;
            cin >> value;
            list.addLast(value);
            break;
        case 'c': //deleteData
            cout << "Ingrese valor a borrar: " << endl;
            cin >> value;
            list.deleteData(value); 
            break;
        case 'd': //deleteAt
            cout << "Ingrese el índice de la casilla que deseas borrar: "<< endl;
            cin >> index;
            list.deleteAt(index);
            break;
        case 'e': //getData
            cout << "Ingrese el índice de la casilla que desea obtener el valor: " << endl;
            cin >> value;
            exceptionGet(value, list);
            break;
        case 'f': //updateAt
            cout << "Ingrese el índice de la casilla que desea actualizar: " << endl;
            cin >> index;
            cout << "Ingrese el valor actualizado: " << endl;
            cin >> value;
            try{
                list.updateAt(value, index);
            }
            catch(out_of_range& e){
                cout << e.what() <<  endl;
            }
            break; 
        case 'g': //updateData
            cout << "Ingrese el valor a encontrar para ser actualizado: " << endl;
            cin >> toFind;
            cout << "Ingrese el valor actualizado: " << endl;
            cin >> value;
            try{
                list.updateData(toFind, value);
            }
            catch(out_of_range& e){
                cout << e.what() <<  endl;
            }
            break;
        case 'h': //findData
            cout << "Ingrese el valor A encontrar: " << endl;
            cin >> value;
            try{
                cout << list.findData(value) << endl;
            }
            catch(out_of_range& e){
                cout << e.what() <<  endl;
            }
            break;
        case 'i': //clear
            list.clear();
            break;

        case 'j': //sort
            try{
                list.sort();
            }
            catch(out_of_range& e){
                cout << e.what() <<  endl;
            }
            break;

        case 'k': //duplicate
            list.duplicate();
            break;
        case 'l': //removeDuplicates
            try{
                list.removeDuplicates();
            }
            catch(out_of_range& e){
                cout << e.what() <<  endl;
            }
            break;
        case 'm': //operator=
            caliz.addFirst(1);
            caliz.addLast(2);
            caliz.addLast(3);
            caliz.addLast(4);
            caliz.addLast(5);
            caliz.addLast(6);

            try{
                list=caliz;
            }
            catch(out_of_range& e){
                cout << e.what() <<  endl;
            }
            list.print();
            break;
        case 'n': //print
            list.reverse();
            list.print();
            break;
        case 'p': //print
            list.print();
            break;
        default:
            break;
    }
    }
}



