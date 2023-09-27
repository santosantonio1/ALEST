/*
    linkedlist.cpp (duplamente)
    >Metodos:
        * push_back
        * push_front
        * insert
        * pop_front
        * pop_back
        * remove
        * size
        * empty
        * top
        * bottom
        * print
        * print_rev
        * clear
*/
#include <iostream>
using namespace std;
template <typename T>

class linked_list{
    private:
    struct node{
        T data;
        node *next, *prev;
        node(T d){
            data = d;
            next = prev = nullptr;
        }
        ~node(){
        }
    };
    node *head, *tail;
    int n_elements;
    public:
     linked_list(){
        n_elements=0;
        head = tail = nullptr;
     }
    ~linked_list(){

    }
    void push_front(T d){
        node *n = new node(d);
        if(head==nullptr) head=tail=n;
        else {
            head->prev = n;
            n->next = head;
            head = n;
        }
        n_elements++;
    }
    void push_back(T d){
        node *n = new node(d);
        if(head==nullptr) head = tail = n;
        else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
        n_elements++;
    }    
    void insert(T d, int pos){
        if(pos<=0) push_front(d);
        else 
        if(pos>=n_elements) push_back(d);
        else {
        node *itr = head, *new_node = new node(d);
        int i=0;
        while(itr != tail){
            if(i==pos-1) {
                new_node->next = itr->next;
                itr->next = new_node;
                new_node->prev = itr;
                new_node->next->prev = new_node;
                n_elements++;
                break;
            }
            itr = itr->next;
            i++;
        }
        }
    }
    void pop_front(){
        if(head != nullptr) {
            node *aux = head;
            head = head->next;
            if(head==nullptr) tail = nullptr;
            else head->prev = nullptr;
            delete aux;
            n_elements--;
        }
    }
    void pop_back(){
        if(head == nullptr) return;
        node *aux = tail;
        tail = tail->prev;
        if(tail==nullptr) head = nullptr;
        else tail->next = nullptr;
        delete aux;
        n_elements--;
    }
    void remove(int pos){
        if(pos<=0) pop_front();
        else
        if(pos>=n_elements-1) pop_back();
        else {
        int i=0;
        node *itr = head, *del;
        while(itr != tail){
            if(i==pos-1){
                del = itr->next;
                itr->next = del->next;
                del->next->prev = itr;
                n_elements--;
                delete del;
                break;
            }
            i++;
            itr = itr->next;
            }
        }
    }
    void print(){
        node *aux = head;
        while(aux != nullptr){
            cout<<aux->data<< "|";
            aux = aux->next;
        }
    }
    void print_rev(){
        node *aux = tail;
        while(aux != nullptr){
            cout << aux->data << "|";
            aux = aux->prev;
        }
    }
    void top(){
        return head->data;
    }
    void bottom(){
        return tail->data;
    }
    int size(){
        return n_elements;
    }
    bool empty(){
        return n_elements == 0;
    }
    void clear(){
        node *itr = head;
        while(itr!=nullptr){
            itr = itr->next;
            delete head;
            head = itr;
        }
    }
};

int main() {
    linked_list<char> l;
    char option, letra;
    int index;
    bool fim = false;
    while(!fim) {
        cout << "|"; 
        if(!l.empty()) l.print();
        cout << endl;
        cin >> ws >> option;
        switch(option){
            case '<':
                cin >> ws >> letra;
                l.push_front(letra);
                break;
            case '>':
                cin >> ws >> letra;
                l.push_back(letra);
                break;
            case '+':
                cin >> ws >> letra >> ws >> index;
                l.insert(letra, index);
                break;
            case '{':
                if(l.empty()) cout << "ERRO" << endl;
                else l.pop_front();
                break;
            case '}':
                if(l.empty()) cout << "ERRO" << endl;
                else l.pop_back();
                break;
            case '-':
                cin >> ws >> index;
                if(index >= l.size() || index<0) 
                    cout << "ERRO" << endl;
                else 
                    l.remove(index);
                    
                break;
            case '.':
                cout << "|";
                l.print_rev();
                cout << endl;
                l.clear();
                fim = true;
                break;
          }
      }
    return 0;
}
