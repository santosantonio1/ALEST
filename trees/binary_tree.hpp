#ifndef _BINARY_TREE_HPP
#define _BINARY_TREE_HPP
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

template <typename T> class binary_tree{
    private:
    T data; binary_tree *parent, *left, *right;
    string getNodes(binary_tree *node){
        stringstream ss;
        if(node->left) ss << "\t" << node->data << " -- " << node->left->data << endl;
        if(node->right) ss << "\t" << node->data << " -- " << node->right->data << endl;
        if(node->left) ss << getNodes(node->left);
        if(node->right) ss << getNodes(node->right);
        return ss.str();
    }

    public:
    binary_tree(T d){
        data = d;
        parent = left = right = nullptr;
    }

    ~binary_tree(){
        delete left;
        delete right;
        #ifdef DEBUG
        cout << "Node " << data << " deleted..." << endl;
        #endif
    }

    T getData(){
        return data;
    }
    
    void setData(T d){
        data = d;
    }

    binary_tree * getParent(){
        return parent;
    }

    binary_tree * getLeft(){
        return left;
    }

    binary_tree * getRight(){
        return right;
    }

    void addLeft(binary_tree *subtree){
        if(left) delete left;
        left = subtree;
        if(subtree) subtree->parent = this;
    }
    
    void addRight(binary_tree *subtree){
        if(right) delete right;
        right = subtree;
        if(subtree) subtree->parent = this;
    }
    
    void removeLeft(){
        addLeft(nullptr);
    }
    
    void removeRight(){
        addRight(nullptr);
    }
    
    bool isRoot(){
        return parent == nullptr;
    }
    
    bool isInternal(){
        return parent && (left || right);
    }
    
    bool isExternal(){
        return !left && !right;
    }
    
    int degree(){
        int d=0;
        if(left) d++;
        if(right) d++;
        return d;
    }
    
    int depth(){
        int d=0;
        binary_tree *itr = parent;
        while(itr){
            itr=itr->parent;
            d++;
        }
        return d;
    }

    int height(){
        int l = (left) ? (1+left->height()) : 0;
        int r = (right) ? (1+right->height()) : 0;
        return (l>r) ? l : r;
    }
    
    int size(){
        int s = 1;
        if(left) s+= left->size();
        if(right) s+= right->size();
        return s;
    }

    bool contains(T d){
        if(data == d) return true;
        if(left && left->contains(d)) return true;
        if(right && right->contains(d)) return true;
        return false;
    }
    
    binary_tree * find(T d){
        if(data == d) return this;
        if(left){
            binary_tree *itr = left->find(d);
            if(itr) return itr;
        }
        if(right){
            binary_tree *itr = right->find(d);
            if(itr) return itr;
        }
        return nullptr;
    }
    
    string graphViz(){
        stringstream ss;
        ss << "graph binary_tree {" << endl;
        ss << "\tnode [shape=circle]" << endl;
        ss << getNodes(this);
        ss << "}" << endl;
        return ss.str();
    }
    
    string preorder(){
        stringstream ss;
        ss << data;
        if(left) ss << left->preorder();
        if(right) ss << right->preorder();
        return ss.str();
    }
    
    string postorder(){
        stringstream ss;
        if(left) ss << left->postorder();
        if(right) ss << right->postorder();
        ss << data;
        return ss.str();
    }
    
    string inorder(){
        stringstream ss;
        if(left) ss << left->inorder();
        ss << data;
        if(right) ss << right->inorder();
        return ss.str();
    }
    
    string levelorder(){
        queue<binary_tree *> q;
        q.push(this);
        stringstream ss;
        while(q.size()){
            binary_tree *itr = q.front();
            ss << itr->data;
            q.pop();
            if(itr->left) q.push(itr->left);
            if(itr->right) q.push(itr->right);
        }
        return ss.str();
    }
};

#endif
