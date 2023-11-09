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

template <typename T>
struct b_node{
    T info;
    node *left,*right,*parent;
    node(T i, node *l=nullptr, node *r=nullptr){
        info = i; left = l; right = r;
        if(left) left->parent = this;
        if(right) right->parent = this;
    }
    ~node(){
        // OBS: delete funciona recursivamente
        if(left) delete left;
        if(right) delete right;
        #ifdef DEBUG
        cout << "> Node " << info << " deleted" << endl;
        #endif
    }
};

template <typename T> int degree(node<T> *root){
    int n=0;
    if(root->left) n++;
    if(root->right) n++;
    return n;
}

template <typename T> int depth(node<T> *root){
    int d=0;
    node<T> *itr = root;
    while(itr){
        itr=itr->parent;
        d++;
    }
    return d;
}

template <typename T> int height(node<T> * root){
    if(!root) return -1;
    int l = (root->left) ? (1 + height(root->left)) : 0;
    int r = (root->right) ? (1+height(root->right)) : 0;
    return (l>r) ? l : r;
}

template <typename T> int size(node<T> *root){
    if(!root) return 0;
    return 1 + size(root->left) + size(root->right);
}


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

template<typename> void ex5(T type){
        b_node<T>*d = new b_node<T>('D');
        b_node<T> *b = new b_node<T>('B', d, new b_node<T>('E'));
        b_node<T> *f = new b_node<T>('F', new b_node<T>('H'), new node<T>('I'));
        b_node<T> *c = new b_node<T>('C', f ,new b_node<T>('G'));
        b_node<T> *root = new b_node<T>('A', b, c);

        cout << graphViz(root);
        cout << " degree(root): " << degree(root) << " [2] " << endl ;
        cout << " degree(b): " << degree(b) << " [2] " << endl ;
        cout << " degree(d): " << degree (d) << " [0] " << endl ;
        cout << " depth(root): " << depth (root) << " [0] " << endl ;
        cout << " depth(b): " << depth (b) << " [1] " << endl ;
        cout << " depth(f): " << depth (f) << " [2] " << endl ;
        cout << " size(root): " << size (root) << " [9]" << endl ;
        cout << " size(b): " << size (b) << " [3] " << endl ;
        cout << " size(c): " << size (c) << " [5] " << endl ;
        cout << " height(root): " << height (root) << " [3] " << endl ;
        cout << " height(b): " << height (b) << " [1] " << endl ;
        cout << " height(c): " << height (c) << " [2] " << endl ;
        delete root ;
}

int main(){
    int int_type;
    char char_type;

    ex3(char_type);
    cout << endl;
    ex4(char_type);

    return 0;
}