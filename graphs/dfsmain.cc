#include<print>
#include<ranges>
#include "include\graph.hpp"
#include "include\dfs.hpp"
#include "include\dfs_path.hpp"

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    Graph g(in);
    size_t s = std::stoi(argv[2]);
    DFS_PATHS search(g, s);

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

    // dfs.hpp test
    // DFS search(g, std::stoi(argv[2]));
    
    // for(size_t i=0; i<g.V(); i++)
    //     if(search.marked(i))
    //         std::print("{} ", i);
    
    // std::println();

    // if(search.count() != g.V())
    //     std::print("NOT ");

    // std::println("connected");

    // graph.hpp test
    // std::println("{}", g.toString());
    // std::println("{}", g.self_loops());
    
    in.close();

    return 0;
}