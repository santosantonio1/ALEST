#include <iostream>
#include <vector>

using namespace std;

class Node {
    private:
        int elem;
        Node *next;

    public:

        Node(int n) {
            elem = n;
            next = NULL;
        }

        Node() {
            elem = 0;
            next = NULL;
        }

        Node(int n, Node *p) {
            elem = n;
            next = p;
        }

        void setElem(int e) {
            elem = e;
        }

        void setNext(Node*p) {
            next = p;
        }

        int Elem() {
            return elem;
        }

        Node * Next() {
            return next;
        }
};

class ListItr {
    private:
        Node *current;

    public:
        ListItr() {
            current = NULL;
        }

        bool Fim() {
            if(current == NULL) 
                return true;

                return false;
        }

        void setPos(Node *p) {
            current = p;
        }

        int Elem() {
            return current->Elem();
        }

        void Advance() {
            current = current->Next();
        } 

        Node * Pos() {
            return current;
        }

};

class List{

    private:
        Node *first;

    public:
        List() {
            first = NULL;
        }

        List(Node *n) {
            first = n;
        }

        void setFirst(Node *p) {
            first = p;
        }

        Node * First() {
            return first;
        }

        void Insert(Node *n, int pos) {
            ListItr *i = new ListItr();
            int k = 0;
            bool trocou = false;
            for(i->setPos(first); !i->Fim(); i->Advance()) {
                
                if(first == NULL) {
                    setFirst(n);
                    trocou = true;
                    break;
                }

                else {

                if(pos==0) {
                    n->setNext(first);
                    setFirst(n);
                    trocou = true;
                    break;
                }

                if(k == pos-1 && k>0) {
                    n->setNext(i->Pos()->Next());
                    i->Pos()->setNext(n);
                    trocou = true;
                    break;
                    }
                }
                k++;
            }

            if(!trocou) {
                n->setNext(NULL);
                i->setPos(n);
            }

            delete i;

        }//OBS se pos>n° de nodos, coloca n no final

        void RemoveNode(int pos) {
            ListItr *i = new ListItr();
            int k=0;

            for(i->setPos(first); !i->Fim(); i->Advance()) {
                if(first == NULL) {
                    break;
                }
                else {

                    if(pos == 0) {
                        Node *auxiliar = i->Pos()->Next();
                        delete i->Pos();
                        setFirst(auxiliar);
                        delete auxiliar;
                        break;
                    }

                    if(k==pos-1 && k>0) {
                        Node *auxiliar = i->Pos()->Next();
                        delete i->Pos()->Next();
                        i->Pos()->setNext(auxiliar->Next());
                        delete auxiliar;
                        break;
                    }
                }
                k++;
            }
        }        

        void printList() {
            ListItr *i = new ListItr();
            i->setPos(first);
            while(!i->Fim()) {
                cout << "Elem: " << i->Elem() << endl;
                i->Advance();
            }
        }
};

int main() { 
    //Criar destrutor e trocar o delete pelo construtor!
    // Criar método para ordenar a lista
    // Jeito melhor para receber o input (vector com os nomes em n°s ???)

    Node *n10 = new Node(117);
    Node *n9  = new Node(233, n10);
    Node *n8  = new Node(2138, n9);
    Node *n7  = new Node(128, n8);
    Node *n6  = new Node(1234, n7);
    Node *n5  = new Node(102, n6);
    Node *n4  = new Node(3902, n5);
    Node *n3  = new Node(639, n4);
    Node *n2  = new Node(419, n3);
    Node *n1  = new Node(829, n2);

    List L(n1);

    L.printList();
        
} 
    
    