#ifndef _AVL_HPP
#define _AVL_HPP

#include "binary_tree.hpp"
using namespace std;

template<typename T> class avl{
    private:
    binary_tree<T> *root;
    
    int FB(binary_tree<T> *node);

    binary_tree<T> * rotateLeft(binary_tree<T> * node);
    binary_tree<T> * rotateRight(binary_tree<T> * node);
    binary_tree<T> * rotateLeftRight(binary_tree<T> * node);
    binary_tree<T> * rotateRightLeft(binary_tree<T> * node);
    binary_tree<T> * rotate(binary_tree<T> *node);


    void add(binary_tree<T> * node, T e);
    void remove(binary_tree<T> * node);
    binary_tree<T> * find(binary_tree<T> * node, T e);
    bool contains(binary_tree<T> * node, T e);

    
    void balance(binary_tree<T> * node);

    public:
    avl();
    ~avl();

    void add(T e);
    void remove(T e);
    binary_tree<T> * find(T e);
    bool contains(T e);

    string graphViz();
    
    string levelorder();
    string preorder();
    string inorder();
    string postorder();

};

template<typename T> avl<T>::avl(){
    root = nullptr;
}

template<typename T> avl<T>::~avl(){
    delete root;
}

template<typename T> int avl<T>::FB(binary_tree<T> * node){
    if(!node) return 0;
    binary_tree<T> * l = node->getLeft(), * r = node->getRight();
    if(l && r) return r->height() - l->height();
    if(!l && r) return r->height() + 1;
    if(l && !r) return 0 - l->height() - 1;
    return 0;
}

template<typename T> binary_tree<T> * avl<T>::rotateLeft(binary_tree<T> * node){
    
    binary_tree<T> * newRoot = node->getRight(), 
                   * newChild = node->getRight()->getLeft();


    node->setRight(newChild);
    newRoot->setLeft(node);

    return newRoot;
}

template<typename T> binary_tree<T> * avl<T>::rotateRight(binary_tree<T> * node){

    binary_tree<T> * newRoot = node->getLeft(), 
                   * newChild = node->getLeft()->getRight();

    node->setLeft(newChild);
    newRoot->setRight(node);
    
    return newRoot;
}

template<typename T> binary_tree<T> * avl<T>::rotateLeftRight(binary_tree<T> * node){
    node->setLeft(rotateLeft(node->getLeft()));
    return rotateRight(node);
}

template<typename T> binary_tree<T> * avl<T>::rotateRightLeft(binary_tree<T> * node){
    node->setRight(rotateRight(node->getRight()));
    return rotateLeft(node);
}

template<typename T> binary_tree<T> * avl<T>::rotate(binary_tree<T> * node){
    int fb = FB(node);

    if(fb == 2){
        int child_fb = FB(node->getRight());
        if(child_fb>=0) node = rotateLeft(node);
        else node = rotateRightLeft(node);
    }
    else if(fb == -2){
        int child_fb = FB(node->getLeft());
        if(child_fb<=0) node = rotateRight(node);
        else node = rotateLeftRight(node);
    }
    return node;
}








template<typename T> void avl<T>::balance(binary_tree<T> * node){

    binary_tree<T> *parent = node->getParent();

    if(!parent){
        root = rotate(node);
        root->setParent(nullptr);
    }
    else{
        if(node->getData() < parent->getData()) parent->setLeft(rotate(node));
        else parent->setRight(rotate(node));
    }
}

template<typename T> void avl<T>::add(binary_tree<T> * node, T e){

        if(e < node->getData()){
            if(!node->getLeft())
                node->addLeft(new binary_tree<T>(e));
            
            else add(node->getLeft(), e);
        }
        else{
            if(!node->getRight())
                node->addRight(new binary_tree<T>(e));
            
            else add(node->getRight(), e);
        }
                balance(node);
}

template<typename T> void avl<T>::add(T e){

    if(!root) root = new binary_tree<T>(e);
    else add(root, e);

}

template<typename T> binary_tree<T> * avl<T>::find(binary_tree<T> * node, T e){
    
    T d = node->getData();
    if(d == e) return node;
    if(e < d){
        if(node->getLeft()){
            binary_tree<T>  * itr = find(node->getLeft(), e);
            if(itr) return itr;
        }
    }
    else{
        if(node->getRight()){
            binary_tree<T> * itr = find(node->getRight(), e);
            if(itr) return itr;
        }
    }
    return nullptr;
}

template<typename T> binary_tree<T> * avl<T>::find(T e){
    return find(root, e);
}

template<typename T> bool avl<T>::contains(binary_tree<T> * node, T e){
    if(node->getData() == e) return true;
    if(e < node->getData()){
        if(node->getLeft()) return contains(node->getLeft(), e);
    }
    else{
        if(node->getRight()) return contains(node->getRight(), e);
    }
    return false;
}

template<typename T> bool avl<T>::contains(T e){
    return find(root, e);
}

template<typename T> void avl<T>::remove(binary_tree<T> * node){


    /* * * * * * * * * * * * * * * * * * * * * *
     *                                         *
     *      > > >   IMPLEMENTAR   < < <        *
     *                                         *
     * * * * * * * * * * * * * * * * * * * * * */

}

template<typename T> void avl<T>::remove(T e){


    /* * * * * * * * * * * * * * * * * * * * * *
     *                                         *
     *      > > >   IMPLEMENTAR   < < <        *
     *                                         *
     * * * * * * * * * * * * * * * * * * * * * */

} 






template<typename T> string avl<T>::levelorder(){
    return root->levelorder();
}

template<typename T> string avl<T>::preorder(){
    return root->preorder();
}

template<typename T> string avl<T>::inorder(){
    return root->inorder();
}

template<typename T> string avl<T>::postorder(){
    return root->postorder();
}

template<typename T> string avl<T>::graphViz(){
    return root->graphViz();
}

#endif