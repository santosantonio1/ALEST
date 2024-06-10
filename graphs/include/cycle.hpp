#ifndef __CYCLE_HPP__
#define __CYCLE_HPP__

#include "graph.hpp"

class Cycle
{
    public:
        Cycle(const Graph& g)
        {
            marked.resize(g.V());
            for(size_t s=0; s<g.V(); s++)
                if(!marked[s])
                    dfs(g, s, s);
        }   

        bool hasCycle() const {
            return hc;
        }
    private:
        std::vector<bool> marked;
        bool hc = false;

        void dfs(const Graph& g, const size_t v, const size_t u)
        {
            marked[v] = true;
            for(const size_t w : g.adj_to(v))
            {
                if(!marked[w]) dfs(g, w, v);
                else if(w != u) hc = true; // Ignores self-loops.
            }
        }        
};

#endif