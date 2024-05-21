#ifndef _BTREE_HPP
#define _BTREE_HPP

#include<iostream>
#include<queue>
using namespace std;

template<typename T> class binary_tree{
    public:

    binary_tree(T d);
    ~binary_tree();

    T data();

    binary_tree<T> * parent();
    binary_tree<T> * left();
    binary_tree<T> * right();
    binary_tree<T> * find(T d);
    
    int degree();
    int depth();
    int height();
    int size();
    int bf();
    
    bool internal();
    bool external();
    bool contains(T d);

    void set_data(T d);
    void set_left(binary_tree<T> *node);
    void set_right(binary_tree<T> *node);
    void set_parent(binary_tree<T> *node);
    void add_left(binary_tree<T> *node);
    void add_right(binary_tree<T> *node);
    void add_left(T data);
    void add_right(T data);
    void remove_left();
    void remove_right();

    string preorder();
    string inorder();
    string postorder();
    string levelorder();
    string graphViz();

    private:
    T d;
    int f;
    binary_tree<T> *p, *l, *r;

    void set_bf(int f);
    string getNodes(binary_tree<T> *node);
};

// Public Methods...

template<typename T> binary_tree<T>::binary_tree(T d){
    data = d;
    bf = 0;
    p = l = r = nullptr;
}
template<typename T> binary_tree<T>::~binary_tree(){
    delete l;
    delete r;
    #ifdef DEBUG
    cout << "Node " << this.data() << " deleted..." <<< endl;
    #endif
}
template<typename T> T binary_tree<T>::data(){
    return d;
}
template<typename T> binary_tree<T> * binary_tree<T>::parent(){
    return p;
}
template<typename T> binary_tree<T> * binary_tree<T>::left(){
    return l;
}
template<typename T> binary_tree<T> * binary_tree<T>::right(){
    return r;  
}
template<typename T> binary_tree<T> * binary_tree<T>::find(T d){
    if(this->data() == d) return this;
    if(this->left()){
        binary_tree<T> *itr = this->left()->find(d);
        if(itr) return itr;
    }
    if(this->right()){
        binary_tree<T> *itr = this->right()->find(d);
        if(itr) return itr;
    }
    return nullptr;
}

template<typename T> int binary_tree<T>::degree(){
    int deg = 0;
    if(this->left()) deg++;
    if(this->right()) deg++;
    return deg;
}
template<typename T> int binary_tree<T>::depth(){
    int dep = 0;
    binary_tree<T> *itr = this->parent();
    while(itr){
        itr=itr->parent();
        dep++;
    }
    return dep;
}
template<typename T> int binary_tree<T>::height(){
    int lft = l ? (1+l->height()) : 0;
    int rgt = r ? (1+r->height()) : 0;
    return (lft>rgt) ? lft : rgt;
}
template<typename T> int binary_tree<T>::size(){
    int s = 0, deg = this->degree();
    s += deg;
    if(l) s += l->size();
    if(r) s += r->size();
    return s;
}
template<typename T> int binary_tree<T>::bf(){
    return f;
}

template<typename T> bool binary_tree<T>::internal(){
    return r || l;
}
template<typename T> bool binary_tree<T>::external(){
    return !this->internal(); 
}
template<typename T> bool binary_tree<T>::contains(T d){
    if(this->d == d) return true;
    if(l && l->contains(d)) return true;
    if(r && r->contains(d)) return true;
    return false;   
}

template<typename T> void binary_tree<T>::set_data(T d){
    this->d = d;
}
template<typename T> void binary_tree<T>::set_left(binary_tree<T> *node){
    l = node;
    if(node) node->set_parent(this);
}
template<typename T> void binary_tree<T>::set_right(binary_tree<T> *node){
    r = node;
    if(node) node->set_parent(this);
}
template<typename T> void binary_tree<T>::set_parent(binary_tree<T> *node){
    p = node;
}
template<typename T> void binary_tree<T>::add_left(binary_tree<T> *node){
    if(!l) l = node;
    if(node) node->set_parent(this);
}
template<typename T> void binary_tree<T>::add_right(binary_tree<T> *node){
    if(!r) r = node;
    if(node) node->set_parent(this);
}
template<typename T> void binary_tree<T>::add_left(T data){
    if(!l) l = new binary_tree<T>(data); 
}
template<typename T> void binary_tree<T>::add_right(T data){
    if(!r) r = new binary_tree<T>(data);
}
template<typename T> void binary_tree<T>::remove_left(){
    
}
template<typename T> void binary_tree<T>::remove_right(){
    
}

template<typename T> string binary_tree<T>::preorder(){
    stringstream ss;
    ss << d;
    if(l) ss << l->postorder();
    if(r) ss << l->postorder();
    return ss.str();
}
template<typename T> string binary_tree<T>::inorder(){
    stringstream ss;
    if(l) ss << l->inorder();
    ss << d;
    if(r) ss << r->inorder();
    return ss.str();
}
template<typename T> string binary_tree<T>::postorder(){
    if(l) ss << l->postorder();
    if(r) ss << r->postorder();
    ss << d;
    return ss.str();
}
template<typename T> string binary_tree<T>::levelorder(){
    queue<binary_tree<T> *> q;
    q.push(this);
    stringstream ss;
    while(!q.empty()){
        binary_tree<T> *itr = q.front();
        #ifdef DEBUG
        cout << " node: " << itr->getData();
            cout << " - parent: ";
            if(itr->getParent()) cout << itr->getParent()->getData();
            else cout << "nullptr"; 
            cout << " - childs: ";
            if(itr->getLeft()) cout << itr->getLeft()->getData() << " e ";
            else cout << "nullptr e ";
            if(itr->getRight()) cout << itr->getRight()->getData() << endl << endl;
            else cout << "nullptr" << endl << endl;
        #endif
        ss << itr->data();
        q.pop();
        if(itr->left()) q.push(itr->left());
        if(itr->right()) q.push(itr->right());
    }
    return ss.str();
}
template<typename T> string binary_tree<T>::graphViz(){
    
}

// Private Methods...

template<typename T> void binary_tree<T>::set_bf(int f){

}

template<typename T> string binary_tree<T>::getNodes(binary_tree<T> *node){

}
#endif

