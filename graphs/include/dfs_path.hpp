#ifndef __DFS_PATH_HPP__
#define __DFS_PATH_HPP__

#include "graph.hpp"

class DFS_PATHS
{
    public:
        DFS_PATHS(const Graph& g, const size_t s)
        {
            this->s = s;
            marks.resize(g.V());
            edgeTo.resize(g.V());
            
            dfs(g, s);
        }

        bool hasPathTo(const size_t v) const {
            return marks[v];
        }

        // std::stack is not iterable -> use vector and i
        // iterate reversewise
        std::vector<size_t> pathTo(const size_t v) const
        {
            if(!hasPathTo(v)) return std::vector<size_t>{};
            
            std::vector<size_t> path;

            // Walk backwards until reach start node
            for(size_t i=v; i != s; i=edgeTo[i])
                    path.push_back(i);

            path.push_back(s);
            return path;
        }

    private:
        // Marked nodes
        std::vector<bool> marks;

        // Stores the origin before moving to the next node
        // "I came from here then move" ahh vector
        std::vector<size_t> edgeTo;

        // Start node
        size_t s;

        void dfs(const Graph& g, const size_t v)
        {
            marks[v] = true;
            for(const auto w : g.adj_to(v))
            {
                if(!marks[w]) {
                    edgeTo[w] = v;
                    dfs(g, w);
                }
            }
        }
};

#endif