#include "Huffman.hpp"
using namespace std;
int main()
{   
    try
    {
        string input = "ABRACADABRA!";
        // string input = "MASBAH!";
        Huffman h;
        h.compress(input);
        h.print();
    }
    catch(const exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}