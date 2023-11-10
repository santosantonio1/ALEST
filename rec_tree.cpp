#include <iostream>
#include <sstream>
using namespace std;
template <typename T>
struct node{
    T info;
    node *child1,*child2,*child3;
    node(T i,node*c1=nullptr,node*c2=nullptr,node*c3=nullptr){
        info = i;
        child1 = c1;
        child2 = c2;
        child3 = c3;
    }
    ~node(){
        #ifdef DEBUG
        cout << "> Nodo " << info << " desalocado..." << endl;
        #endif
    }
};

/****** GENERATE GRAPHVIZ CODE FOR VISUALIZATION ******/
template <typename T> string getNodes(node<T> *root){
    if(root==nullptr) return "";
    stringstream ss;
    if(root->child1!=nullptr) ss << "\t" << root->info << " -- "<< root->child1->info<<endl;
    if(root->child2!=nullptr) ss << "\t" << root->info << " -- "<< root->child2->info<<endl;
    if(root->child3!=nullptr) ss << "\t" << root->info << " -- "<< root->child3->info<<endl;
    ss << getNodes(root->child1);
    ss << getNodes(root->child2);
    ss << getNodes(root->child3);
    return ss.str();
}

template <typename T> string graphViz(node<T> *root){
    stringstream ss;
    ss << "graph \"" << root->info << "\" {" << endl;
    ss << "\tnode [shape=circle]" << endl; 
    ss << getNodes(root);
    ss << "} ";
    return ss.str();
}

/**** EXERCICIO 3 ****/
template <typename T> void clean (node<T> * root){
    if(root==nullptr) return;
    clean(root->child1);
    clean(root->child2);
    clean(root->child3);
    delete root;
}

template<typename T> void ex3(T type){
    node<char> *b = new node<char>('B');
    node<char> *e = new node<char>('E');
    node<char> *f = new node<char>('F');
    node<char> *g = new node<char>('G');

    node<char> *c = new node<char>('C',e,f);
    node<char> *d = new node<char>('D',g);
    node<char> *root = new node<char>('A',b,c,d);
    cout << graphViz(root);

    clean(root);
}

template <typename T> void ex4(T type){
    node<T> * k = new node<T>('K');
    
    node<T> * e = new node<T>('E'),
            * f = new node<T>('F'),
            * g = new node<T>('G'),
            * h = new node<T>('H',k),
            * i = new node<T>('I'),
            * j = new node<T>('J');
            
    node<T> *b = new node<T>('B',e,f),
            *c = new node<T>('C',g),
            *d = new node<T>('D',h,i,j);
    
    node<T> *root = new node<T>('A',b,c,d);

    cout << graphViz(root) << endl;
    clean(root);
}

int main(){
    int int_type;
    char char_type;

    ex3(char_type);
    cout << endl;
    ex4(char_type);

    return 0;
}