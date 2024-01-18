#include "..\graph.hpp"
#include <sys/time.h>
using namespace std;

int main(){
    timeval start, end;
    gettimeofday(&start,nullptr);

    ifstream in;
    in.open("input.txt",ios::in);
    graph<char> g(in);
    in.close();

    try{
        auto v = g.getNodes();
        g.print();
        cout << endl << g.graphViz() << endl;
        
        for(auto a : v) cout << a << " degree " << g.degree(a) << endl;
        cout << endl;

        auto n = g.reach('H');
        for(char c : n) cout << c << " ";
        cout << endl; 
    }
    catch(const char *e){
        cout << e << endl;
    }

    gettimeofday(&end,nullptr);

    double t = (double)(end.tv_usec - start.tv_usec)/1000;

    cout << endl << "TIME-LAPSED: " << t << " ms" << endl;

    return 0;
}