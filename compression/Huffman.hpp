#ifndef _HUFFMAN_
#define _HUFFMAN_

#include<iostream>
#include "../heap/MinPQ.hpp"
using namespace std;

// Not working yet

class Huffman
{
    public:
        Huffman()
        {

        }
        void compress(string s)
        {
            vector<size_t> freq(128);
            table.resize(128);
            size_t hp_sz = 0;
            for(auto c : s)
                if(freq[c]++ == 0) hp_sz++;

            root = build(freq, hp_sz);

            encode(root, "");
            // print();
        }
        void print()
        {
            for(size_t i=0; i<table.size(); i++)
            {
                if(table[i] != "")
                    cout << (char) i << " : " << table[i] << endl;
            }
        }
    private:
        struct Node
        {
            char ch;
            size_t freq;
            Node *left, *right;
            Node(char c, size_t f, Node *l, Node *r)
            {
                ch = c;
                freq = f;
                left = l;
                right = r;
            }
            bool operator>(const Node *n) const
            {
                return this->freq > n->freq;
            }
            bool operator<(const Node *n) const
            {
                return this->freq < n->freq;
            }
            bool leaf()
            {
                return !left && !right;
            }
            friend ostream & operator<<(ostream &out, const Node *n)
            {
                out << n->ch;
                return out;
            }
        };
        Node *root;
        vector<string> table;

        Node * build(vector<size_t> freq, size_t hp_sz)
        {
            MinPQ<Node *> pq(hp_sz);
            for(size_t i=0; i<freq.size(); i++)
                if(freq[i] > 0)
                    pq.insert(new Node((char) i, freq[i], nullptr, nullptr));
            
            for(auto a: pq)
            {
                cout << a << " : " << a->freq << " | "; 
            }

            cout << endl;

            while(pq.size() > 1)
            {
                Node *left = pq.pop();
                Node *right = pq.pop();
                Node *parent = new Node('\0', left->freq + right->freq, left, right);
                pq.insert(parent);
            }

            return pq.pop();            
        }
        void encode(Node *x, string s)
        {
            if(!x->leaf())
            {
                encode(x->left, s+'0');
                encode(x->right, s+'1');
            }
            else
            {
                table[x->ch] = s;
            }
        }
};

#endif
