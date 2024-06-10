#include<print>
#include<ranges>
#include "include\graph.hpp"
#include "include\bfs_path.hpp"

// diw e diW :OOOOOOOOOO

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    Graph g(in);
    size_t s = std::stoi(argv[2]);

    BFS_PATHS search(g, s);

    for(size_t v=0; v<g.V(); v++)
    {
        std::print("{} to {}:", s, v);
        if(search.hasPathTo(v))
        {
            for(const auto x : search.pathTo(v) 
                             | std::ranges::views::reverse) {
                if(x == s) std::print("{}", x);
                else std::print("-{}", x);
            }
            std::println();
        }
    }


    in.close();

    return 0;
}