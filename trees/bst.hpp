#ifndef _BST_HPP
#define _BST_HPP

#include "binary_tree.hpp"

template <typename T> class bst{
    private:
    binary_tree<T> *root;

    // MÉTODO PARA ACHAR A POSIÇÃO CORRETA PARA A INSERÇÃO
    // FOI NECESSÁRIO ADICIONAR OS MÉTODOS DE SET NA CLASSE
    // binary_tree PARA NÃO DAR delete nullptr 
    void find_position(binary_tree<T> *node, binary_tree<T> *newNode){
        if(newNode->getData() < node->getData()){
            if(!node->getLeft())    node->setLeft(newNode);
            else    find_position(node->getLeft(), newNode);
        }
        else{
            if(!node->getRight())   node->setRight(newNode);
            else    find_position(node->getRight(), newNode); 
        }        
    }

    bool find_element(binary_tree<T> *node, T e){
        if(e == node->getData()) return true;
        else{
            if(e < node->getData()){
                if(!node->getLeft()) return false;
                else return find_element(node->getLeft(), e);
            }
            else{
                if(!node->getRight()) return false;
                else return find_element(node->getRight(), e);
            }
        }

    }


    public:
    bst() : root(nullptr) {}
    
    ~bst() {
        if(root) delete root;
    }

    void add(T e){
        binary_tree<T> * newNode = new binary_tree<T>(e);
        if(!root) root = newNode;
        else find_position(root, newNode);
    }

    bool contains(T e){
        if(!root) return false;
        return find_element(root, e);
    }

    string graphViz(){
        if(!root) return "";
        return root->graphViz();
    }
};

#endif