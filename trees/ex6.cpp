#include <iostream>
#include "generic_tree.hpp"
#include <iomanip>
using namespace std;

void showTree(tree<char> *root) {
  cout << endl <<  root->graphViz() << endl;
  cout << "N Pa iR iI iE dg dp hg sz fJ fL" << endl;	
  for (char letter='A'; letter<='L'; ++letter) {
      tree<char>  *node = root->find(letter);
      if (node == nullptr) { cout << letter << "  *  *  *  *  *  *  *  *  *  *" << endl; continue; }
      tree<char> *parent = node->getParent();
      char parentInfo = (node->getParent() == nullptr)?'*':parent->getData();
      cout << letter << " " << setw(2) << parentInfo << " ";
      cout << setw(2) << node->isRoot() << " " << setw(2) << node->isInternal() << " " << setw(2) << node->isExternal() << " ";
      cout << setw(2) << node->degree() << " " << setw(2) << node->depth() <<  " " << setw(2) << node->height() <<  " ";
      cout << setw(2) << node->size() << " " << setw(2) << node->contains('J') << " " << setw(2) << node->contains('L') << endl;
  }
}

int main() {
  
  tree<char> *d = new tree<char>('D');        d->addSubtree( new tree<char>('I') );
                                                        d->addSubtree( new tree<char>('J') );
  
  tree<char> *b = new tree<char>('B');        b->addSubtree( d );
                                                        b->addSubtree( new tree<char>('E') );
                                                        b->addSubtree( new tree<char>('F') );	
  
  tree<char> *h = new tree<char>('H');        h->addSubtree( new tree<char>('K') );
  
  tree<char> *c = new tree<char>('C');        c->addSubtree( new tree<char>('G') );
                                                        c->addSubtree( h );
  
  tree<char> *root = new tree<char>('A');     root->addSubtree( b );
                                                        root->addSubtree( c );
  
  showTree(root);
  b->removeSubtree(d);
  
  showTree(root);
  root->removeSubtree(b);
  
  showTree( root );
  
  delete root;
  
  return 0;
}
