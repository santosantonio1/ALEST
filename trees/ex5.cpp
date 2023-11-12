#include <sstream>
#include <iostream>
using namespace std;
struct node{
    char info;
    node *left,*right,*parent;
    node(char i, node *l=nullptr, node *r=nullptr){
        info = i; left = l; right = r; parent = nullptr;
        if(left) left->parent = this;
        if(right) right->parent = this;
    }
    ~node(){
        
        if(left) delete left;
        if(right) delete right;

        #ifdef DEBUG    
        cout << "> Node " << info << " deleted" << endl;
        #endif
    }
};
int degree(node *root){
        int n=0;
        if(root->left) n++;
        if(root->right) n++;
        return n;
    }

int depth(node *root){
    int d=0;
    node *itr = root->parent;
    while(itr){
        itr=itr->parent;
        d++;
    }
    return d;
}

int height(node *root){
    if(!root) return -1;
    int l = (root->left) ? (1 + height(root->left)) : 0;
    int r = (root->right) ? (1 + height(root->right)) : 0;
    return (l>r) ? l : r;
}

int size(node *root){
    if(!root) return 0;
    return 1 + size(root->left) + size(root->right);
}

string getNodes(node *root){
    if(root==nullptr) return "";
    stringstream ss;
    if(root->left!=nullptr) ss << "\t" << root->info << " -- "<< root->left->info<<endl;
    if(root->right!=nullptr) ss << "\t" << root->info << " -- "<< root->right->info<<endl;
    ss << getNodes(root->left);
    ss << getNodes(root->right);
    return ss.str();
}

string graphViz(node *root){
    stringstream ss;
    ss << "graph \"" << root->info << "\" {" << endl;
    ss << "\tnode [shape=circle]" << endl; 
    ss << getNodes(root);
    ss << "} ";
    return ss.str();
}

int main(){
        node *d = new node('D');
        node *b = new node('B', d, new node('E'));
        node *f = new node('F', new node('H'), new node('I'));
        node *c = new node('C', f ,new node('G'));
        node *root = new node('A', b, c);

        cout << graphViz(root) << endl;
        cout << " degree(root): " << degree(root) << " [2] " << endl ;
        cout << " degree(b): " << degree(b) << " [2] " << endl ;
        cout << " degree(d): " << degree (d) << " [0] " << endl ;
        cout << " depth(root): " << depth(root) << " [0] " << endl ;
        cout << " depth(b): " << depth(b) << " [1] " << endl ;
        cout << " depth(f): " << depth(f) << " [2] " << endl ;
        cout << " size(root): " << size(root) << " [9]" << endl ;
        cout << " size(b): " << size(b) << " [3] " << endl ;
        cout << " size(c): " << size(c) << " [5] " << endl ;
        cout << " height(root): " << height(root) << " [3] " << endl ;
        cout << " height(b): " << height(b) << " [1] " << endl ;
        cout << " height(c): " << height(c) << " [2] " << endl ;
        
        delete root;

    return 0;
}