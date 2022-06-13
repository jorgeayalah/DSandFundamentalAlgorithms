/// Jorge Ayala
/// Creado el 21/09/2020
/// Editdo el 30/09/2020
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
#include "LinkedList.h"

int main(){
    LinkedList<int> list;
    list.addFirst(5);
    list.print();
    list.addLast(10);
    list.print();
}

