#include "generic_tree.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

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
