#include<print>
#include<ranges>
#include "include\graph.hpp"
#include "include\cc.hpp"

// diw e diW :OOOOOOOOOO

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    Graph g(in);

    std::println("{}", g.toString());

    CC cc(g);
    const size_t M = cc.count();
    std::println("{} components", M);

    std::vector<std::forward_list<size_t>> components(M);

    for(size_t v=0; v<g.V(); v++)
        components[cc.id(v)].push_front(v);

    for(size_t i=0; i<M; i++)
    {
        for(const auto v : components[i])
            std::print("{} ", v);
        
        std::println();
    }

    in.close();

    return 0;
}