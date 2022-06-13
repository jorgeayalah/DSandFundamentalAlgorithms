/// Jorge Ayala
/// Creado el 01/10/2020
/// Editdo el 23/10/2020
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <exception>

using namespace std;
#include "Stack.h"

int main(){
    Stack<int> stack;
    //Llena Stack de valores
    stack.push(123);
    stack.push(321);
    stack.push(65);
    stack.push(11);
    stack.push(13);
    stack.push(15);
    stack.push(17);
    stack.push(3);

    stack.print();
    //stack.clear();
    
    try{
        cout << stack.pop() << endl;    //Borra top y lo imprime
    }
    catch(out_of_range& e){
        cout << e.what() <<  endl;
    }
    try{
        cout << stack.getTop() << endl; //Da el valor de top
    }
    catch(out_of_range& e){
        cout << e.what() <<  endl;
    }

    //Obtiene tamaño, luego lo vacía y lo comprueba imprimiéndolo
    cout << stack.getSize();
    stack.clear();
    stack.print();
};