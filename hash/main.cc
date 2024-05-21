#include<functional>
#include<iostream>
#include "ChainingHash.hpp"
#include "LinearHash.hpp"
using namespace std;

namespace _hash
{
    size_t string_hash(string &s)
    {
        size_t hsh = 0;
        for(size_t i=0; i<s.length(); i++)
            hsh = s[i] + 31*hsh;
    
        return hsh;
    }
};

int main()
{
    ChainingHash<char, int> ch(2);

    string input = "SEARCHEXAMPLE";
    // string input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    for(auto c : input)
        ch.push(c, i++);

    ch.print();
    
    cout << "------------------------" << endl;

    for(auto c : input)
        cout << c << " " << ch.get(c) << endl;

    ch.remove('V');
    ch.print();

    // for(auto c : input)
    //     cout << c << ": " << ch.get(c) << endl;

    return 0;
}