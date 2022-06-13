//Andres Piñones
//A01570150
#include <queue>
#include "NodeT.h"

class BST{
	public:
		BST();
		~BST();
		void add(int data);
		bool search(int data);
		void remove(int data);
		void printPre();
		int size();
		void height();
		void visit(int num);
		void ancestors(int data);
		int whatlevelamI(int data);

	private:
		NodeT *root;
		void preOrden(NodeT *r);
		void inOrden(NodeT *r);
		void postOrden(NodeT *r);
		void levelBylevel(NodeT *r);
		void destruye(NodeT *r);
		int howManyChildren(NodeT *r);
		int succ(NodeT *r);
		int pred(NodeT *r);
		int count(NodeT *r);
		int getHeight(NodeT *r);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destruye(root);
}

void BST::destruye(NodeT *r){
	if (r != nullptr){
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}

int BST::succ(NodeT *r){
	NodeT *curr = r->getRight();
	while (curr->getLeft() != nullptr){
		curr = curr->getLeft();
	}
	return curr->getData();
}

int BST::pred(NodeT *r){
	NodeT *curr = r->getLeft();
	while (curr->getRight() != nullptr){
		curr = curr->getRight();
	}
	return curr->getData();
}


void BST::add(int data){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr){
		if (curr->getData() == data){
			return;
		}
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	if (father == nullptr){
		root = new NodeT(data);
	}
	else{
/*
		if (father->getData() > data){
			father->setLeft(new NodeT(data));
		}
		else{
			father->setRight(new NodeT(data));
		}
*/
		father->getData() > data ? father->setLeft(new NodeT(data)) : 
								father->setRight(new NodeT(data));
	}

}

int BST::howManyChildren(NodeT *r){
	int cont = 0;
	if (r->getLeft() != nullptr){
		cont++;
	}
	if (r->getRight() != nullptr){
		cont++;
	}
	return cont;
}

void BST::remove(int data){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr && curr->getData() != data){
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	if (curr == nullptr){
		return;
	}
	int cantHijos = howManyChildren(curr);
	switch (cantHijos){
		case 0: if (father == nullptr){
					root = nullptr;
				}
				else{
					if (father->getData() > data){
						father->setLeft(nullptr);
					}
					else {
						father->setRight(nullptr);
					}
				}
				delete curr;
				break;
		case 1: if (father == nullptr){
					if (curr->getLeft() != nullptr){
						root = curr->getLeft();
					}
					else{
						root = curr->getRight();
					}
				}
				else{
					if (father->getData() > data){
						// quiero borrar al hijo izq del padre
						if (curr->getLeft() != nullptr){
							// único hijo esta a la izq.
							father->setLeft(curr->getLeft());
						}
						else{
							// único hijo esta a la der.
							father->setLeft(curr->getRight());
						}
					}
					else{
						// quiero borrar al hijo der del padre
						if (curr->getLeft() != nullptr){
							// único hijo esta a la izq.
							father->setRight(curr->getLeft());
						}
						else{
							// único hijo esta a la der.
							father->setRight(curr->getRight());
						}
					}
				}
				delete curr;
				break;
		case 2: int sucesor = succ(curr);
				remove(sucesor);
				curr->setData(sucesor);
				break;
	}
}


bool BST::search(int data){
	NodeT *curr = root;
	while (curr != nullptr){
		if (curr->getData() == data){
			return true;
		}
/*
		if (curr->getData() > data){
			curr = curr->getLeft();
		}
		else{
			curr = curr->getRight();
		}
*/
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	return false;
}

// Complejidad: O(n)
void BST::preOrden(NodeT *r){
	if (r != nullptr){
		cout << r->getData() << " ";
		preOrden(r->getLeft());
		preOrden(r->getRight());
	}
}

//Complejidad: O(n)
void BST::inOrden(NodeT *r){
	if (r != nullptr){
		inOrden(r->getLeft());
		cout << r->getData()<< " ";
		inOrden(r->getRight());
	}
}

//Complejidad: O(n)
void BST::postOrden(NodeT *r){
	if (r != nullptr){
		postOrden(r->getLeft());
		postOrden(r->getRight());
		cout << r->getData()<< " ";
	}
}
//Complejidad: O(n^2)
void BST::levelBylevel(NodeT *r){
	queue<NodeT*> myqueue;
	if (r != nullptr)
		myqueue.push(root);
	
	while(!myqueue.empty()){
		NodeT *curr = myqueue.front();
		cout<<curr->getData()<<" ";
		
		if(curr->getLeft() != nullptr)
			myqueue.push(curr->getLeft());
		if(curr->getRight() != nullptr)
			myqueue.push(curr->getRight());
		myqueue.pop();
	}
	
	  
}



// Complejidad: O(n)
void BST::printPre(){
	preOrden(root);
	cout << endl;
}

//Complejidad: O(n)
int BST::count(NodeT *r){
	if (r == nullptr){
		return 0;
	}
	return 1 + count(r->getLeft()) + count(r->getRight());
}

// Complejidad: O(n)
int BST::size(){
	return count(root);
}

//Complejidad: O(n)
int BST::getHeight(NodeT *r){
	if(r==nullptr){
		return 0;
	}
	int left=getHeight(r->getLeft());
	int right=getHeight(r->getRight());
	
	if(left>right){
		return left+1;
	}else{
		return right+1;
	}
}

void BST::height(){
	cout<<"La altura del BST es: "<<getHeight(root);
	cout<<endl;
}

void BST::visit(int num){
	switch(num)
	{
	case 1:
		preOrden(root);
		break;
	case 2:
		inOrden(root);
		break;
	case 3:
		postOrden(root);
		break;
	case 4:
		levelBylevel(root);
		break;
	default:
		break;
	}
}

//complejidad:O()
void BST::ancestors(int data){
 	NodeT *curr = root;
    vector<NodeT*> fathers;
    NodeT *father =nullptr;
    while(curr!=nullptr){
        father = curr;
        fathers.push_back(father);
        if(curr->getData() > data){
            curr = curr->getLeft();
        }
        else{
            curr = curr->getRight();
        }
        if(curr->getData()==data){
        	cout<<"Los ancestros del dato son:"<<endl;
            for(int i=0; i<fathers.size(); i++){
                cout << fathers[i]->getData()<<" ";
            }
            curr = nullptr;
        }
    }
    cout<<endl;
}

int BST::whatlevelamI(int data){
		NodeT *curr = root;
		bool found=false;
		int cont=1;
		while (curr != nullptr && found==false){
			if (curr->getData() == data){
				found = true;
				return cont;
			}
			if (curr->getData() > data){
				curr = curr->getLeft();
				cont++;
			}
			else{
				curr = curr->getRight();
				cont++;
			}
		}
		return -1;
}


