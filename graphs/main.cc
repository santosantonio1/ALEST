#include<print>
#include<ranges>
#include "include\graph.hpp"
#include "include\symbol_graph.hpp"
#include "include\bfs_path.hpp"

// diw e diW :OOOOOOOOOO

int main(int argc, char *argv[])
{
    SymbolGraph sg(argv[1], argv[2]);

    Graph g = sg.G();

    std::string source = argv[3];

    if(!sg.contains(source)) {
        std::println("{} not in database.", source);
        return 0;
    }

    size_t s = sg.index(source);
    BFS_PATHS bfs(g, s);

    std::string line;

    while(getline(std::cin, line))
    {
        if(sg.contains(line))
        {
            size_t t = sg.index(line);
            if(bfs.hasPathTo(t)) {
                for(const auto v : bfs.pathTo(t)
                                 | std::ranges::views::reverse)
                    std::println("      {}", sg.name(v));
            } else {
                std::println("Not connected.");
            }   
        }
        else std::println("Not in database.");
    }

    return 0;
}