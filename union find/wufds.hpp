#ifndef _WUFDS_
#define _WUFDS_

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class WQUF
{
    public:
        WQUF(int n)
        {
            count = n;
            id.resize(n);
            sz.resize(n);
            for(int i=0; i<n; i++)
            {
                id[i] = i;
                sz[i] = 1;
            }
        }
        int size()
        {
            return count;
        }
        bool connected(int p, int q)
        {
            return find(p) == find(q);
        }
        void u(int p, int q)
        {
            int i = find(p);
            int j = find(q);

            if(i == j) return;

            if(sz[i] < sz[j])
            {
                id[i] = j;
                sz[j] += sz[i];
            }
            else
            {
                id[j] = i;
                sz[i] += sz[j];
            }
            count--;
        }
    private:
        vector<int> id;
        vector<int> sz;
        int count;

        int find(int p)
        {
            while(p != id[p]) p = id[p];
            return p;
        }
};

#endif