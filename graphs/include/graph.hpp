/*
    Simple graph implementation based on Robert Sedgewick 
    material
*/

#ifndef __GRAPHS_HPP__
#define __GRAPHS_HPP__

#include<bits/stdc++.h>

class Graph
{
    public:
        Graph(size_t nv) : v(nv), e(0)
        {
            adj.resize(nv);
        }

        Graph(std::ifstream &in) : e(0)
        {
            size_t E;
            in >> v;
            in >> E;
            adj.resize(v); 
            for(size_t i=0; i<E; i++) {
                size_t u, w;
                in >> u >> w;
                addEdge(u, w);
            }   
        }

        // Number of vertices
        size_t V() const { 
            return v; 
        }

        // Number of edges
        size_t E() const {
            return e;
        }

        // O(1)
        void addEdge(const size_t u, const size_t w)
        {
            adj[u].push_front(w);
            adj[w].push_front(u);
            e++;
        }

        // Returns list of vertices adjacent to v
        std::forward_list<size_t>
            adj_to(const size_t v) const {
            return adj[v]; 
        }

        // String representation of the graph
        std::string toString() const
        {
            std::stringstream ss;
            ss << v << " vertices, " << e << " edges\n";
            for(size_t i=0; i<v; i++) {
                ss << i << ": ";
                for(auto w : adj[i])
                    ss << w << " ";
                ss << "\n";
            }
            return ss.str();
        }
  
        // Counts the number of self loops
        size_t self_loops() const
        {
            size_t count = 0;
            for(size_t i=0; i<v; i++)
            {
                for(auto w : adj[i])
                    if(i == w) count++;
            }
            return count/2; // Each edge counted twice?
                            // Maybe because of parallel edges
                            // aren't distinguished 
        }
        
    private:
        size_t v, e;

        // space: O(V + E)
        std::vector<std::forward_list<size_t>> adj;

};


#endif