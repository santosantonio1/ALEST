#include <iostream>
#include <iomanip>
#include "binary_tree.hpp"

void showTree(binary_tree<char> *root) {
  string s = "XYEZDAWBC*";  char c = 'C', l = 'L';
  cout << endl << root->graphViz() << endl;
  cout << "N Pa iR iI iE dg dp hg sz fC fL" << endl;	
  for (int i=0; i<s.length(); ++i) {
      char letter = s[i];
      binary_tree<char>  *node = root->find(letter);
      if (node == nullptr) { cout << letter << "  *  *  *  *  *  *  *  *  *  *" << endl; continue; }
      binary_tree<char> *parent = node->getParent();
      char parentInfo = (node->getParent() == nullptr)?'*':parent->getData();
      cout << letter << " " << setw(2) << parentInfo << " ";
      cout << setw(2) << node->isRoot() << " " << setw(2) << node->isInternal() << " " << setw(2) << node->isExternal() << " ";
      cout << setw(2) << node->degree() << " " << setw(2) << node->depth() <<  " " << setw(2) << node->height() <<  " ";
      cout << setw(2) << node->size() << " " << setw(2) << node->contains(c) << " " << setw(2) << node->contains(l) << endl;
  }
}

int main() {
  binary_tree<char> *w    = new binary_tree<char>('W');  w->addLeft ( new binary_tree<char>('B') );  w->addRight( new binary_tree<char>('C') );
  binary_tree<char> *z    = new binary_tree<char>('Z');  z->addLeft ( new binary_tree<char>('A') );  z->addRight( w );
  binary_tree<char> *y    = new binary_tree<char>('Y');  y->addLeft ( z );                      y->addRight( new binary_tree<char>('D') );
  binary_tree<char> *root = new binary_tree<char>('X');  root->addLeft ( y );                   root->addRight( new binary_tree<char>('E') );
//   cout << "pre-order:   " << (root->preorder()   == "X\nY\nZ\nA\nW\nB\nC\nD\nE\n" ? "OK" : "ERROR") << endl;
//   cout << "post-order:  " << (root->postorder()  == "A\nB\nC\nW\nZ\nD\nY\nE\nX\n" ? "OK" : "ERROR") << endl;
//   cout << "in-order:    " << (root->inorder()    == "A\nZ\nB\nW\nC\nY\nD\nX\nE\n" ? "OK" : "ERROR") << endl;
//   cout << "level-order: " << (root->levelorder() == "X\nY\nE\nZ\nD\nA\nW\nB\nC\n" ? "OK" : "ERROR") << endl;

    cout << "1: " << root->preorder() << endl;
    cout << "2: " << root->postorder() << endl;
    cout << "3: " << root->inorder() << endl;
    cout << "4: " << root->levelorder() << endl;


  showTree( root );
  z->removeRight();    showTree( root );
  root->removeLeft();  showTree( root );
  delete root;
  return 0;
}
