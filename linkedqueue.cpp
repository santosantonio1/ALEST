/*
    linkedqueue.cpp (duplamente)
    >FIFO
    >METODOS:
        * size
        * empty
        * push
        * pop
        * front
        * back
        * clear
        * print (retirar)
*/
#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class linked_queue{
    private:
    int n_elements;
    struct node {
        T data;
        node *next, *prev;
        node(T d) {
            data = d;
            next = prev = nullptr;
        }
    };
    node *head, *tail;
    public:
     linked_queue(){
        n_elements=0;
        head=tail=nullptr;
    }
    ~linked_queue(){

    }
    int size(){
        return n_elements;
    }
    bool empty(){
        return n_elements==0;
    }
    void push(T e){
        node * aux = new node(e);
        if(head == nullptr) head = tail = aux;
        else {
            tail->next = aux;
            aux->prev = tail;
            tail = aux;
            n_elements++;   
        }
    }
    bool pop(){
        if(empty()) return false;
        head = head->next;
        head->prev = nullptr;
        n_elements--;
        return true;
    }
    T front(){
        return head->data;
    }
    T back(){
        return tail->data;
    }
    void clear(){
            node *aux;
        while(n_elements){
            aux = head;
            head=head->next;
            delete aux;
            n_elements--;
        }
        head = tail = nullptr;
        n_elements = 0;
    }
    void print(){
        node *aux;
        aux = head;
        while(aux != nullptr){
            cout << aux->data << " ";
            aux = aux->next;
        }
        cout << endl;
    }
};
int main(){
    linked_queue<int> q;
    for(int i=1;i<7;i++){
        int n = i + 1;
        q.push(n); 
        q.print();
    }
    cout << endl;
    q.pop();
    q.print();
    return 0;
}