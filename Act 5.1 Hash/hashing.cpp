#include <iostream>
#include <vector>

#include "HashQ.h"
#include "HashL.h"
#include "HashCh.h"

using namespace std;

int main(){
    vector<string> list = {"hola", "chor", "sapo", "alla", "otro", "foca"};

    HashQ hashTable(list);
    HashL hashTableL(list);
    //HashCh hashTableCh(list);

    //Quadratic
    hashTable.print();
    cout << "El índice es: " << hashTable.findData("chor") << endl;

    //Linear
    hashTableL.print();
    cout << "El índice es: " << hashTableL.findData("foca") << endl;
    /*
    //Chain
    hashTableCh.print();
    cout << "El índice es: " << hashTableCh.findData("sapo") << endl;
    */
    return 0;
};