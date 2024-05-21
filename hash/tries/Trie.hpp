#ifndef _TRIE_
#define _TRIE_

#include<iostream>
#include<vector>
using namespace std;
class Trie
{
    public:
        Trie()
        {
            root = new Node();
            n = 0;
        }
        ~Trie()
        {
            delete root;
        }
        void insert(string key, int val)
        {
            insert(root, key, val, 0);
        }
        void remove(string key)
        {
            insert(root, key, -1, 0);
        }
        size_t size()
        {
            return n;
        }
        bool contains(string key)
        {
            if(this->empty()) return false;
            return get(root, key, 0) != -1;
        }
        bool empty()
        {
            return n == 0;
        }
        int operator[](string key)
        {
            return get(root, key, 0);
        }
    private:
        struct Node
        {
            int value;
            vector<Node *> next;
            Node()
            {
                next.resize(128);
                value = -1;
            }
            ~Node()
            {
                for(size_t i=0; i<next.size(); i++)
                delete next[i];
            }
        };
        Node *root;
        size_t n;
        // Node * insert(Node *x, string key, size_t val, size_t d)
        void insert(Node *x, string key, int val, size_t d)
        {
            if(x->next[key[d]] == nullptr)
            {
                x->next[key[d]] = new Node();
                // insert(x->next[key[d]], key, val, d+1);
            }
            // if(x == nullptr) x = new Node();
            if(d == key.length())
            {
                if(x->value == -1 && val != -1) n++;
                if(val == -1) n = (n>0) ? (n-1) : 0;
                x->value = val;
                // return x;
                return;
            }
            insert(x->next[key[d]], key, val, d+1);
        }
        int get(Node *x, string key, size_t d)
        {
            if(x == nullptr) return -1;
            if(d == key.length()) return x->value;
            return get(x->next[key[d]], key, d+1);  
        }
};

#endif