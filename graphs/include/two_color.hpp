#ifndef __TWO_COLOR_HPP__
#define __TWO_COLOR_HPP__

#include "graph.hpp"

class TwoColor
{
    public:
        TwoColor(const Graph& g)
        {
            marked.resize(g.V());
            color.resize(g.V());

            for(size_t s=0; s<g.V(); s++)
                if(!marked[s]) dfs(g, s);
        }

        bool isBipartite() const {
            return m_isTwoColor;
        }

    private:
        std::vector<bool> marked, color;
        bool m_isTwoColor = true;

        void dfs(const Graph& g, const size_t v)
        {
            marked[v] = true;
            for(const auto w : g.adj_to(v))
            {
                if(!marked[v]) {
                    color[w] = !color[v];
                    dfs(g, w);
                } else {
                    if(color[w] == color[v]) 
                        m_isTwoColor = false;
                }
            }
        }
};

#endif