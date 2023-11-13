#include "generic_tree.hpp"
using namespace std;
int main(){
    
    node_tree<char> *b = new node_tree<char> ('B');
    b -> addSubtree ( new node_tree<char> ('E') );
    b -> addSubtree ( new node_tree<char> ('F') );
    
    node_tree<char> *c = new node_tree<char> ('C');
    c -> addSubtree ( new node_tree<char> ('G') );
    c -> addSubtree ( new node_tree<char> ('H') );
    c -> addSubtree ( new node_tree<char> ('I') );
    
    node_tree<char> * root = new node_tree<char> ('A');
    root -> addSubtree (b );
    root -> addSubtree (c );
    root -> addSubtree ( new node_tree<char> ('D') );
    
    cout << "1 : " << root->preorder() << endl;
    cout << "2 : " << root->postorder() << endl;
    cout << "3 : " << root->levelorder() << endl;

    // cout << "pre - order : " << ( root -> preorder () == "A\nB\nE\nF\nC\nG\nH\nI\nD\n" ? "OK" : " ERROR ") << endl ;
    // cout << "post - order : " << ( root -> postorder () == "E\nF\nB\nG\nH\nI\nC\nD\nA\n" ? "OK" : " ERROR ") << endl ;
    // cout << "level - order : " << ( root -> levelorder() == "A\nB\nC\nD\nE\nF\nG\nH\nI\n" ? "OK" : " ERROR ") << endl ;

    delete root ;

    return 0;
}
