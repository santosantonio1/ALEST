#ifndef _GENERIC_TREE_HPP
#define _GENERIC_TREE_HPP
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

template <typename T> class node_tree{
    private:
    
    node_tree *parent;
    vector<node_tree *> childs;
    T data;
    string getNodes(){
        stringstream ss;
        for(int i=0;i<childs.size();i++){
            ss << "\t" << data << " -- " << childs[i]->data << endl;
        }
        for(int i=0;i<childs.size();i++){
            ss << childs[i]->getNodes();
        }
        return ss.str();
    }

    public:
    
    node_tree(T d){
        data = d; parent = nullptr;
    }

    ~node_tree(){
        for(int i=0;i<childs.size();i++) delete childs[i];
        #ifdef DEBUG
        cout << "> Node " << data << " deleted..." << endl;
        #endif
    }
    
    T getData(){ return data; }
    
    void setData(T d){ data = d; }
    
    node_tree * getParent(){ return parent; }
    
    node_tree * child(int i){ return (i<0 || i<childs.size()) ? childs[i] : nullptr; }
    
    int degree(){ return childs.size(); }
    
    int depth(){
        int d=0;
        node_tree *itr = parent;
        while(itr){
            itr=itr->parent;
            d++;
        }
        return d;
    }    
    
    int height(){
        int h=0;
        for(int i=0;i<childs.size();i++){
            int  height = 1 + childs[i]->height();
            if(height>h) h = height;
        }
        return h;
    }
    
    int size(){
        int s=1;
        for(int i=0;i<childs.size();i++){
             s += childs[i]->size();
        }
        return s;
    }
    
    void addSubtree(node_tree *n){
        if(!n) return;
        n->parent = this;        
        childs.push_back(n);
    }

    bool removeSubtree(node_tree *n){ 
        node_tree *itr;
        for(int i=0;i<childs.size();i++){
            itr=childs[i];
            if(itr==n){ childs.erase(childs.begin() + i); delete itr; return true; }
        }

        return false;
    }   
    
    bool contains(T d){
        
        if(data==d) return true;

        for(int i=0;i<childs.size();i++)
            if(childs[i]->contains(d)) return true;

        return false;
    }
    
    bool isRoot(){ return parent==nullptr; }
    
    bool isInternal(){ return parent!=nullptr && childs.size()!=0; }
    
    bool isExternal(){ return childs.size() == 0; }
    
    node_tree * find(T d){
        if(data == d) return this;
        for(int i=0;i<childs.size();i++){
            node_tree *itr = childs[i]->find(d);
            if(itr != nullptr) return itr; 
        }
        return nullptr;
    }
    
    string graphViz(){
        stringstream ss;
        ss << "graph node_tree {" << endl;
        ss << "\tnode[shape=circle]" << endl;
        ss << getNodes();
        ss << "}" << endl;
        return ss.str();
    }

    string preorder(){
        stringstream ss;
        ss << data;
        for(int i=0;i<childs.size();i++)
            ss << childs[i]->preorder();
        return ss.str();
    }

    string postorder(){
        stringstream ss;
        for(int i=0;i<childs.size();i++)
            ss <<  childs[i]->postorder();
        ss << data;
        return ss.str();
    }

    // IMPLEMENTAR DFS
    string levelorder(){
        queue<node_tree *> q;
        stringstream ss;
        q.push(this);
        while(q.size()){
            node_tree *itr = q.front();
            ss << itr->data;
            q.pop();
            for(int i=0;i<itr->degree();i++){
                q.push(itr->child(i));
            }
        }
        return ss.str();
    }

};
#endif