#ifndef _GENERIC_TREE_HPP
#define _GENERIC_TREE_HPP
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

template <typename T> class tree{
    private:

    tree *parent;
    vector<tree *> childs;
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
    
    tree(T d){
        data = d; parent = nullptr;
    }

    ~tree(){
        for(int i=0;i<childs.size();i++) delete childs[i];
        #ifdef DEBUG
        cout << "> Node " << data << " deleted..." << endl;
        #endif
    }
    
    T getData(){ return data; }
    
    void setData(T d){ data = d; }
    
    tree * getParent(){ return parent; }
    
    tree * child(int i){ return (i<0 || i<childs.size()) ? childs[i] : nullptr; }
    
    int degree(){ return childs.size(); }
    
    int depth(){
        int d=0;
        tree *itr = parent;
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
    
    void addSubtree(tree *n){
        if(!n) return;
        n->parent = this;        
        childs.push_back(n);
    }

    bool removeSubtree(tree *n){ 
        tree *itr;
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
    
    tree * find(T d){
        if(data == d) return this;
        for(int i=0;i<childs.size();i++){
            tree *itr = childs[i]->find(d);
            if(itr != nullptr) return itr; 
        }
        return nullptr;
    }
    
    string graphViz(){
        stringstream ss;
        ss << "graph tree {" << endl;
        ss << "\tnode [shape=circle]" << endl;
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
        queue<tree *> q;
        stringstream ss;
        q.push(this);
        while(q.size()){
            tree *itr = q.front();
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