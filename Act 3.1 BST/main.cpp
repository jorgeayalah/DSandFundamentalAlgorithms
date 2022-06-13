#include <iostream>

using namespace std;
#include "BinaryST.h"

int main(){
    BinaryST<int> arbolbin;
    arbolbin.insert(7);
    arbolbin.insert(10);
    arbolbin.insert(21);
    arbolbin.insert(40);
    arbolbin.insert(6);
    arbolbin.insert(18);
    arbolbin.insert(9);
    arbolbin.insert(5);
    arbolbin.insert(2);
    arbolbin.insert(1);
    arbolbin.print();

    arbolbin.deleteNode(18);
    cout << "Estado de búsqueda: " << arbolbin.find(5) << endl;
    //Checar impresiones erroneas
    arbolbin.print();
}