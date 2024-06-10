#ifndef __CONNECTED_COMPONENTS__
#define __CONNECTED_COMPONENTS__

#include "graph.hpp"

class CC 
{
    public:

        CC(const Graph& g)
        {
            idx.resize(g.V());
            marked.resize(g.V());

            // DFS will walk trough all paths entirely.
            // When it finishes walking, move on trying to 
            // find another component.
            for(size_t s = 0; s<g.V(); s++)
            {
                if(!marked[s])
                {
                    dfs(g,s);
                    c++;
                }
            }

        }

        // Two vertices are connected if and only if they belong
        // to the same component.
        bool connected(const size_t v, const size_t w) const {
            return idx[v] == idx[w];
        }

        // Return which component the given vertex belongs.
        size_t id(const size_t v) const {
            return idx[v];
        }

        // Number of components inside the graph.
        size_t count() const {
            return c;
        }
    private:

        // Separates the nodes into groups (components), giving
        // each node a component number.
        std::vector<size_t> idx;

        // Marked nodes
        std::vector<bool> marked;

        // Count
        size_t c = 0;

        // DFS uses a time and space complexity of O(V+E) to support
        // O(1) performance for connectivity queries in a graph.
        void dfs(const Graph& g, const size_t v)
        {
            idx[v] = c;
            marked[v] = true;
            for(const auto w : g.adj_to(v))
                if(!marked[w]) dfs(g, w);
        }

};


#endif