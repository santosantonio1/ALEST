#ifndef __DFS_HPP__
#define __DFS_HPP__

#include "graph.hpp"

class DFS
{
    public:
        DFS(const Graph& g, const size_t s)
        {
            marks.resize(g.V());
            dfs(g, s);
        }

        bool marked(const size_t v) const {
            return marks[v];
        }

        size_t count() const {
            return c;
        }

    private:
        // Marked nodes
        std::vector<bool> marks;

        // Count
        size_t c = 0;
       
        void dfs(const Graph& g, const size_t v)
        {
            marks[v] = true;
            c++;
            for(const auto w : g.adj_to(v))
                if(!marks[w]) dfs(g, w);

        }   
};

#endif