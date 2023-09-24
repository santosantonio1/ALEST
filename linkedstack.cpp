/*
    linkedstack.cpp (duplamente)
    >LIFO
    >METODOS:
        * push
        * pop
        * top
        * empty
        * size
        * clear
*/
#include <iostream>
using namespace std;
template<typename T>
class linked_stack{
    private:
    struct node{
        T data;
        node *next, *prev;
        node(T data){
            this->data = data;
            next = prev = nullptr;
        }
    };
    node *head;
    int n_elements;
    public:
    linked_stack(){
        head = nullptr;
        n_elements = 0;
    }
    ~linked_stack(){

    }
    void push(T e){
        node *new_node = new node(e);
        if(n_elements!=0){
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
            head = new_node;
        n_elements++;
    }
    bool pop(){
        if(n_elements > 0){
            head=head->next;
            head->prev = nullptr;
            n_elements--;
            return true;
        }
        return false;
    }
    bool top(T &e){
        if(n_elements != 0){
            e = head->data;
            return true;
        }
        return false;
    }
    int size(){
        return n_elements;
    }
    bool empty(){
        return n_elements==0;
    }
    void clear(){
        node *aux;
        while(n_elements){
            aux = head;
            head=head->next;
            delete aux;
            n_elements--;
        }
        head = nullptr;
    }
};
int main(){
    linked_stack<int> l;
    for(int i=0; i<10; i++){
        l.push(i+1);
    }
    cout << "SIZE: " << l.size() << endl;
    int x;
    l.pop();
    l.pop();
    cout << "SIZE: " << l.size() << endl;
    int t = l.size();
    for(int i=0; i<t; i++){
        l.top(x);
        cout << x << " ";
        l.pop();
    }
    cout << endl;
}