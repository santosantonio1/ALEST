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
        if(head != nullptr){
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        else head = new_node;
        n_elements++;
    }
    bool pop(){
        node *del = head;
        if(head != nullptr){
            head=head->next;
            if(head != nullptr) head->prev = nullptr;
            delete del;
            n_elements--;
            return true;
        }
        return false;
    }
    bool top(T &e){
        if(head != nullptr){
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
        n_elements = 0;
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
    l.top(x);
    while(l.pop()){
        cout << x << " ";
        l.top(x);
    }
    cout << endl;
    return 0;
}
