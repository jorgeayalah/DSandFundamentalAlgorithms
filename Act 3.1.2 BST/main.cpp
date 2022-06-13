#include <iostream>

using namespace std;
#include "BinaryST.h"


int main(){
    BinaryST<int> arbolbin;
    int opc, vopc, data;
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

    while(opc!='z'){
        cout << "\t" << "M E N Ú" << endl;
        cout << "Ingrese un comando de los siguientes para usar determinado método: " << endl;
        cout << "\t" << "a) visit " << endl;
        cout << "\t" << "b) height" << endl;
        cout << "\t" << "c) ancestors" << endl;
        cout << "\t" << "d) whatLevelAmI" << endl;
        cout << "\t" << "e) insert" << endl;
        cout << "\t" << "f) delete" << endl;
        cout << "\t" << "g) find" << endl;
        cout << "\t" << "p) print" << endl;

        cout << "\t" << "z) Salir" << endl;
        cin >> opc;
        switch (opc){
        case 'a': //visit
            cout << "Ingrese el comando de según desee: " << endl;
            cout << "a. Preorder" << endl;
            cout << "b. Inorder" << endl;
            cout << "c. Postorder" << endl;
            cout << "d. Level by level" << endl;
            cin >> vopc;
            switch(vopc){
                case 'a':
                    arbolbin.visit(1);
                    break;
                case 'b':
                    arbolbin.visit(2);
                    break;
                case 'c':
                    arbolbin.visit(3);
                    break;
                case 'd':
                    arbolbin.visit(4);
                    break;
                default:
                    break;
            }
            break;
        case 'b': //height
            cout << "La altura del BST es: " << arbolbin.height() << endl;
            break;
        case 'c': //ancestors
            cout << "Ingrese el valor del cual buscar sus ancestros: " << endl;
            cin >> data;
            arbolbin.ancestors(data);
            break;
        case 'd': //whatLevelAmI
            cout << "Ingrese valor a ubicar su nivel: "<< endl;
            cin >> data;
            arbolbin.whatLevelAmI(data);
            break;
        case 'e': //insert
            cout << "Ingrese valor a ingresar: " << endl;
            cin >> data;
            arbolbin.insert(data);
            break;
        case 'f': //delete
            cout << "Ingrese valor a eliminar: " << endl;
            cin >> data;
            arbolbin.deleteNode(data);
            break;
        case 'g': //find
            cout << "Ingrese valor a encontrar: " << endl;
            cin >> data;
            arbolbin.find(data);
            break;
        case 'p':
            arbolbin.print();
            break;
        default:
            break;
        }
    }
    
}