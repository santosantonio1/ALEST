#include "avl.hpp"
#include <iostream>
using namespace std;

int main(){

    avl<int> *t = new avl<int>();

    // for(int i=0;i<15;i++){
    //     t->add(i+1);
    // }

    // cout << t->graphViz() << endl;

    // return 0;

    // t->add(1);
    // t->add(0);
    // t->add(2);
    // t->add(3);
    // t->add(4);
    // t->add(5);
    // t->add(6);

    t->add(8);
    t->add(2);
    t->add(10);
    t->add(6);
    t->add(5);
    t->add(15);
    t->add(7);
    t->add(3);
    t->add(20);
    t->add(11);


    cout << t->graphViz() << endl;

    delete t;

    return 0;
}