#include "bnt.hpp"
#include <iostream>
using namespace std;
int main () {
        node<char> *d = new node<char> ('D');
        node<char> *b = new node<char> ('B',d , new node<char> ('E'));
        node<char> *f = new node<char> ('F',new node<char> ('H'), new node<char> ('I'));
        node<char> *c = new node<char> ('C',f , new node<char> ('G'));
        node<char> * root = new node<char> ('A',b , c );

        cout << graphViz ( root );
        cout << " degree ( root ): " << degree ( root ) << " [2] " << endl ;
        cout << " degree (b): " << degree ( b) << " [2] " << endl ;
        cout << " degree (d): " << degree ( d) << " [0] " << endl ;
        cout << " depth ( root ): " << depth ( root ) << " [0] " << endl ;
        cout << " depth (b): " << depth (b ) << " [1] " << endl ;
        cout << " depth (f): " << depth (f ) << " [2] " << endl ;
        cout << " size ( root ): " << size ( root ) << " [9]" << endl ;
        cout << " size (b): " << size (b) << " [3] " << endl ;
        cout << " size (c): " << size (c) << " [5] " << endl ;
        cout << " height ( root ): " << height ( root ) << " [3] " << endl ;
        cout << " height (b): " << height ( b) << " [1] " << endl ;
        cout << " height (c): " << height ( c) << " [2] " << endl ;
        delete root ;
return 0;
}