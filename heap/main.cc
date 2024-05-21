#include "MaxPQ.hpp"
#include "MinPQ.hpp"
#include<bits/stdc++.h>
using namespace std;

// template<typename T> void heap_sort(vector<T> &v)
// {
//     MaxPQ<T> pq(v.size());
//     for(auto a : v)
//         pq.insert(a);

//     for(int i=v.size()-1; i>=0; i--)
//         v[i] = pq.pop();
// }

namespace heapsort
{
    template<typename T> bool less(size_t x, size_t y, vector<T> &v)
    {
        return v[x-1] < v[y-1];
    }
    template<typename T> void swap(size_t x, size_t y, vector<T> &v)
    {
        T tmp = v[x-1];
        v[x-1] = v[y-1];
        v[y-1] = tmp;
    }
    template<typename T> void sink(size_t k, size_t N, vector<T> &v)
    {
        while(2*k <= N)
        {
            size_t j = 2*k;
            if(j < N && heapsort::less(j, j+1, v))
                j++;
            if(!heapsort::less(k, j, v)) break;
            heapsort::swap(k, j, v);
            k = j;
        }
    }
    template<typename T> void sort(vector<T> &v)
    {
        int N = v.size();
        for(int k = N/2; k >= 1; k--)
            heapsort::sink(k, N, v);
        while(N > 1)
        {
            heapsort::swap(1, N--, v);
            heapsort::sink(1, N, v);
        }
    }
};

template<typename T> void print(T &v)
{
    for(auto a : v)
        cout << a << " ";

        cout << endl;
}

int main()
{
    // Geração de números aleatórios
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uid(1,100);


    // Testes heapsort
    // vector<int> v;
    // for(size_t i=0; i<5; i++)
    //     v.push_back(uid(rng));

    // print(v);
    // // heap_sort(v);
    // heapsort::sort(v);
    // print(v);

    // return 0;

    // cout << "-----------------------" << endl;

    MaxPQ<int> pq(5);
    // MinPQ<int> pq(5);

    for(int i=1; i<21; i++)
    {
        if(pq.size() == 5)
            pq.pop();

        // Número aleatório...
        int x = uid(rng);
        cout << x << " ";
        pq.insert(x);
    }

    cout << endl;
    cout << pq.max() << endl;
    // cout << pq.min() << endl;
    cout << pq[1] << endl;

    // Não funciona pois a sobrecarga foi declarada como const...
    // pq[1] = 31;
    // cout << pq.max() << endl;

    // Função que usa foreach pra imprimir os dados
    print(pq);

    return 0;
}