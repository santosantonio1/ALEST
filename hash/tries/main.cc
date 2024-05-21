#include "Trie.hpp"
#include "TST.hpp"
#include<iostream>
#include<vector>
using namespace std;
void trie_main()
{
    Trie t;

    vector<string> v = 
    {
        "she",
        "sells",
        "shells",
        "by",
        "the",
        "sea",
        "shore"
    };

    for(size_t i=0; i<v.size(); i++)
    {
        t.insert(v[i], i);
    }

    cout << t["abcdef"] << endl;
    cout << t.contains("abcdef") << endl;
    t.insert("abcdef", 31);

    cout << t["abcdef"] << endl;
    cout << t.contains("abcdef") << endl;

    t.remove("abcdef");
    cout << t["abcdef"] << endl;
    cout << t.contains("abcdef") << endl;

    t.insert("abcdefg", 31);

    cout << t["abcdef"] << endl;
    cout << t.contains("abcdef") << endl;
    
    cout << t["abcdefg"] << endl;
    cout << t.contains("abcdefg") << endl;

}

void tst_main()
{
    TST t;

    vector<string> v = 
    {
        "she",
        "sells",
        "shells",
        "by",
        "the",
        "sea",
        "shore"
    };

    for(size_t i=0; i<v.size(); i++)
    {
        t.insert(v[i], i);
    }

    cout << t["abcdef"] << endl;
    cout << t.contains("abcdef") << endl;
    t.insert("abcdef", 31);

    cout << t["abcdef"] << endl;
    cout << t.contains("abcdef") << endl;

    t.remove("abcdef");
    cout << t["abcdef"] << endl;
    cout << t.contains("abcdef") << endl;

    t.insert("abcdefg", 31);

    cout << t["abcdef"] << endl;
    cout << t.contains("abcdef") << endl;
    
    cout << t["abcdefg"] << endl;
    cout << t.contains("abcdefg") << endl;
    

    cout << "-------" << endl;

    for(auto s : v)
        cout << t[s] << endl;
}

int main()
{
    trie_main();

    cout << "*********************************" << endl;

    tst_main();

    return 0;
}