#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <sstream>
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
    
    node_tree(T d) {
        data = d; parent = nullptr;
    }

    ~node_tree(){
        for(int i=0;i<childs.size();i++) delete childs[i];
        #ifdef DEBUG
        cout << "> Node " << data << " deleted..." << endl;
        #endif
    }
    
    T getData() { return data; }
    
    void setData(T d) { data = d; }
    
    node_tree * getParent() { return parent; }
    
    node_tree * child(int i) { return (i<0 || i<childs.size()) ? childs[i] : nullptr; }
    
    int degree() { return childs.size(); }
    
    int depth() {
        int d=0;
        node_tree *itr = parent;
        while(itr){
            itr=itr->parent;
            d++;
        }
        return d;
    }    
    
    int height() {
        int h=0;
        for(int i=0;i<childs.size();i++){
            int  height = 1 + childs[i]->height();
            if(height>h) h = height;
        }
        return h;
    }
    
    int size() {
        int s=1;
        for(int i=0;i<childs.size();i++){
             s += childs[i]->size();
        }
        return s;
    }
    
    void addSubtree(node_tree *n) {
        if(!n) return;
        n->parent = this;        
        childs.push_back(n);
    }

    bool removeSubtree(node_tree *n) { 
        node_tree *itr;
        for(int i=0;i<childs.size();i++){
            itr=childs[i];
            if(itr==n){ childs.erase(childs.begin() + i); delete itr; return true; }
        }

        return false;
    }   
    
    bool contains(T d) {
        
        if(data==d) return true;

        for(int i=0;i<childs.size();i++)
            if(childs[i]->contains(d)) return true;

        return false;
    }
    
    bool isRoot() { return parent==nullptr; }
    
    bool isInternal() { return parent!=nullptr && childs.size()!=0; }
    
    bool isExternal() { return childs.size() == 0; }
    
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
};

void showTree(node_tree<char> *root) {
  cout << endl <<  root->graphViz() << endl;
  cout << "N Pa iR iI iE dg dp hg sz fJ fL" << endl;	
  for (char letter='A'; letter<='L'; ++letter) {
      node_tree<char>  *node = root->find(letter);
      if (node == nullptr) { cout << letter << "  *  *  *  *  *  *  *  *  *  *" << endl; continue; }
      node_tree<char> *parent = node->getParent();
      char parentInfo = (node->getParent() == nullptr)?'*':parent->getData();
      cout << letter << " " << setw(2) << parentInfo << " ";
      cout << setw(2) << node->isRoot() << " " << setw(2) << node->isInternal() << " " << setw(2) << node->isExternal() << " ";
      cout << setw(2) << node->degree() << " " << setw(2) << node->depth() <<  " " << setw(2) << node->height() <<  " ";
      cout << setw(2) << node->size() << " " << setw(2) << node->contains('J') << " " << setw(2) << node->contains('L') << endl;
  }
}

int main() {
  
  node_tree<char> *d = new node_tree<char>('D');        d->addSubtree( new node_tree<char>('I') );
                                                        d->addSubtree( new node_tree<char>('J') );
  
  node_tree<char> *b = new node_tree<char>('B');        b->addSubtree( d );
                                                        b->addSubtree( new node_tree<char>('E') );
                                                        b->addSubtree( new node_tree<char>('F') );	
  
  node_tree<char> *h = new node_tree<char>('H');        h->addSubtree( new node_tree<char>('K') );
  
  node_tree<char> *c = new node_tree<char>('C');        c->addSubtree( new node_tree<char>('G') );
                                                        c->addSubtree( h );
  
  node_tree<char> *root = new node_tree<char>('A');     root->addSubtree( b );
                                                        root->addSubtree( c );
  
  showTree( root );
  b->removeSubtree( d );
  
  showTree( root );
  root->removeSubtree( b );
  
  showTree( root );
  
  delete root;
  
  return 0;
}
