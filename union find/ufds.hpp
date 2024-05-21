#ifndef _UNION_FIND_
#define _UNION_FIND_

#include<iostream>
#include<vector>
using namespace std;

class UF
{
    public:
        UF(int n)
        {
            count = n;
            id.resize(n);
            for(int i=0;i<n;i++)
                id[i] = i;
        }
        int find(int p)
        {
            // return id[p];
            return quick_find(p);
        }
        bool connected(int p, int q)
        {
            return find(p) == find(q);
        }
        void u(int p, int q)
        {
            int pID = find(p);
            int qID = find(q);
            
            if(pID == qID) return;

            for(int i=0; i<id.size(); i++)
                if(id[i] == pID) id[i] = qID;

            count--;
        }
        void quick_u(int p, int q)
        {
            int pRoot = find(p);
            int qRoot = find(q);
            
            if(pRoot == qRoot) return;

            id[pRoot] = qRoot;
            count--;
        }
        int size()
        {
            return count;
        }
    private:
        vector<int> id;
        int count;
        int quick_find(int p)
        {
            while(p != id[p]) p = id[p];
            return p;
        }
};

#endif