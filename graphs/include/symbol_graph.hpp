#ifndef __SYMBOL_GRAPH_HPP__
#define __SYMBOL_GRAPH_HPP__

#include "graph.hpp"

class SymbolGraph
{
    public:
        SymbolGraph(const std::string filename, 
                    const std::string delimiter)
        {
            std::ifstream in(filename);
            std::string line;
            
            while(std::getline(in, line))
            {
                auto split = std::views::split(line, delimiter);
                for(const auto &s : split)
                {
                    const std::string tmp{s.begin(), s.end()};
                    if(!idx.contains(tmp)) {
                        idx.insert(std::pair{tmp, idx.size()});
                    }
                }
            }

            keys.resize(idx.size());
            for(const auto &p : idx) {
                keys[idx.at(p.first)] = p.first;
            }
            
            in.close();
            g = new Graph(idx.size());

            in.open(filename);

            bool title;
            size_t tidx;

            while(std::getline(in, line))
            {
                title = true;
                auto split = std::views::split(line, delimiter);

                for(const auto &s : split)
                {
                    if(title) {
                        tidx = idx.at(std::string{s.begin(), s.end()});
                        title = false;
                    } else {
                        g->addEdge(tidx,
                                   idx.at(std::string{s.begin(), s.end()}));
                    }
                }
            } 
  
            std::println("SG built");

            in.close();
        }
        ~SymbolGraph()
        {
            delete g;
        }
        bool contains(const std::string s) const {
            return idx.contains(s);
        }

        size_t index(const std:: string s) const {
            return idx.at(s);
        }

        std::string name(size_t v) const {
            return keys[v];
        }   

        Graph G() {
            return *g;
        }     
    private:
        std::unordered_map<std::string, size_t> idx;
        // std::map<std::string, size_t> idx;
        std::vector<std::string> keys;
        Graph *g;

};

#endif
