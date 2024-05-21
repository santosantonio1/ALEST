#ifndef _TST_
#define _TST_

#include<iostream>
using namespace std;

/*
    ARRUMAR O REMOVE... ASSIM TA BAGACEIRO
*/

class TST
{
    public:
        TST()
        {
            root = nullptr;
            n = 0;
        }

        ~TST()
        {
            delete root;
        }
        
        void insert(string key, int val)
        {
            root = insert(root, key, val, 0);
        }

        void remove(string key)
        {
            insert(root, key, -1, 0);
        }

        int operator[](string key)
        {
           return get(root, key, 0);
        }

        bool contains(string key)
        {
            return get(root, key, 0) != -1;
        }

        bool empty()
        {
            return n == 0;
        }

        size_t size()
        {
            return n;
        }

    private:
        struct Node
        {
            char ch;
            int value;
            Node *left, *mid, *right;
            Node()
            {
                value = -1;
                left = mid = right = nullptr;
            }
            ~Node()
            {
                delete left;
                delete mid;
                delete right;
            }
        };

        Node *root;
        size_t n;

        Node * insert(Node *x, string key, int val, size_t d)
        {
            if(!x)
            {
                x = new Node();
                x->ch = key[d];
            }
            // if(!root) cout << "ROOT nullptr" << endl;
            
            if(key[d] < x->ch) x->left = insert(x->left, key, val, d);
            else if(key[d] > x->ch) x->right = insert(x->right, key, val, d);
            else if(d < key.length()) x->mid = insert(x->mid, key, val, d+1);
            else 
            {
                if(val == -1) n = (n>0) ? n - 1 : 0;
                else if(x->value == -1) n++;
                x->value = val;
                // n++;
            }
            return x;
        }

        int get(Node *x, string key, size_t d)
        {
            if(x == nullptr) return -1;
            if(key[d] < x->ch) return get(x->left, key, d);
            else if(key[d] > x->ch) return get(x->right, key, d);
            else if(d < key.length()) return get(x->mid, key, d+1);
            else return x->value;
        }
};

#endif