#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class linked_queue{
    private:
    int n_elements;
    struct node {
        T data;
        node *next;
        node(T d) {
            data = d;
            next = nullptr;
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
            tail = aux;
            n_elements++;   
        }
    }
    bool pop(){
        if(empty()) return false;
        head = head->next;
        n_elements--;
        return true;
    }
    T front(){
        return head->data;
    }
    void clear(){
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
