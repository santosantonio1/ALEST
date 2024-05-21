#ifndef _MAX_PQ_
#define _MAX_PQ_

#include<vector>
#include<iostream>
using namespace std;

template<typename Key> class MaxPQ
{
    public:
        MaxPQ(size_t capacity = 1);
        void insert(Key v);
        Key pop();
        Key operator[](size_t i) const;
        bool empty() const;
        void print() const;
        size_t size() const;
        Key max() const;
        auto begin();
        auto cbegin();
        auto rbegin();
        auto end();
        auto cend();
        auto rend();
    private:
        // Key(pai) > Key(filhos).
        // Pai : k/2
        // Filhos: 2k e 2k + 1 (da pra generalizar...)
        vector<Key> pq;
        // Key pq[100];
        size_t N;
        bool less(size_t x, size_t y) const;
        void swap(size_t x, size_t y);
        // O(1 + log n)
        void swim(size_t k);
        // O(2 log n)
        void sink(size_t k);
};

template<typename Key> MaxPQ<Key>::MaxPQ(size_t capacity)
{
    N = 0;
    pq.resize(capacity+1);
}
template<typename Key> bool MaxPQ<Key>::less(size_t x, size_t y) const
{
    return pq[x] < pq[y];
}
template<typename Key> void MaxPQ<Key>::swap(size_t x, size_t y)
{
    Key tmp = pq[x];
         pq[x] = pq[y];
         pq[y] = tmp;
}
template<typename Key> void MaxPQ<Key>::swim(size_t k)
{
    while(k>1 && less(k/2, k))
    {
        swap(k, k/2);
        k = k/2;
    }
}
template<typename Key> void MaxPQ<Key>::insert(Key v)
{
    // pq.push(v);
    if(N == pq.size())
        pq.resize(2*pq.size());

    pq[++N] = v;
    swim(N);
}
template<typename Key> void MaxPQ<Key>::sink(size_t k)
{
    // Queremos colocar o maior número como nova raiz pra não ter erro.
    while(2*k <= N)
    {
        size_t j = 2*k;
        // Se o filho da esquerda for maior...
        if(j < N && less(j, j+1))
            j++;
        // Se o pai for maior que o maior filho => break;
        if(!less(k,j)) break;
        swap(k, j);
        k = j;
    }
}
template<typename Key> Key MaxPQ<Key>::pop()
{
    // Coloca a raiz no final (mais fácil mover só 2 doq o vetor todo).
    Key max = pq[1];
    swap(1, N--);
    sink(1);
    pq[N+1] = (Key) NULL;
    return max;
}
template<typename Key> Key MaxPQ<Key>::operator[](size_t i) const
{
    return (i<=pq.size()) ? pq[i] : pq[pq.size()];
}
template<typename Key> bool MaxPQ<Key>::empty() const
{
    return N == 0;
}
template<typename Key> void MaxPQ<Key>::print() const
{
    for(auto a : pq)
        cout << a << " ";

    cout << endl;
}
template<typename Key> size_t MaxPQ<Key>::size() const
{
    return N;
}
template<typename Key> Key MaxPQ<Key>::max() const
{
    if(N==0) throw "MaxPQ vazia...";
    return pq[1];
}
template<typename Key> auto MaxPQ<Key>::begin()
{
    return ++pq.begin();  
}
template<typename Key> auto MaxPQ<Key>::cbegin()
{
    return ++pq.cbegin();  
}
template<typename Key> auto MaxPQ<Key>::rbegin()
{
    return pq.rbegin();  
}
template<typename Key> auto MaxPQ<Key>::end()
{
    return pq.end();  
}
template<typename Key> auto MaxPQ<Key>::cend()
{
    return pq.cend();  
}
template<typename Key> auto MaxPQ<Key>::rend()
{
    return ++pq.rend();  
}


#endif