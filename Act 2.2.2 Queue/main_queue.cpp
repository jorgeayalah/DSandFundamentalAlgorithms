//#include <stdexcept>
#include <iostream>
#include <exception>
#include "Queue.h"
//#include "DLL.h"
#include "Node.h"


using namespace std;

int main(){
    //DLL<int> doublylist;
    Queue<int> queueList;
    try{
        queueList.dequeue();
    }
    catch(out_of_range& e){
        cout << e.what() <<  endl;
    }
    queueList.enqueue(10);
    queueList.enqueue(11);
    queueList.enqueue(15);
    queueList.enqueue(19);
    queueList.enqueue(23);
    try{
        cout << queueList.dequeue() << endl;
    }
    catch(out_of_range& e){
        cout << e.what() <<  endl;
    }
    queueList.print();
    queueList.clear();
    queueList.print();
    cout << queueList[0] << endl;
    
};