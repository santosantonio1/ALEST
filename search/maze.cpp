/*
    MAZE SOLVER (bfs) IMPLEMENTATION USING OOP
    Ex:
    ..###################
    ..#.....#.#.#.#.....#
    #.#####.#.#.#.#.#####
    #.....#.....#...#...#
    #####.#.#####.###.#.#
    #.....#.#.#.#.#...#.#
    #.#.#.#.#.#.#.#.#.###
    #.#.#.....#.....#.#.#
    #.#.###.#.#.#######.#
    #.#.#...#...#.......#
    #.#.###.#####.###.###
    #.#.#...#.#.....#...#
    #.###.#.#.#####.#####
    #.#.#.#...#.#.......#
    #.#.#######.#######.#
    #.#.......#.#.....#.#
    #.#.###.###.###.#.#.#
    #...#...........#...#
    #######.#####.#######
    #.......#............
    ###################.F
    
    start(left-top)(0,0) end(F)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <sys/time.h>
#include <iomanip>
using namespace std;

class maze{
    private:
    struct point{
        char c;
        bool flag;
        int  i, j, prev_i, prev_j;
        point() : c('#'), flag(true){
            i = j = prev_i = prev_j = 0;
        }    
    };
    vector<vector<point>> m;
    
    //WIDTH, HEIGHT
    int w, h;
    
    //MOVEMENT - (N,S,E,W)
    int x[4] = {-1, 1, 0, 0}, 
        y[4] = {0, 0, 1, -1};
    
    int min;


    //OUT OF BOUNDS
    bool out(int i, int j){
        if(i<0 || j<0) return true;
        if(i>=h || j>=w) return true;
        return false;
    }

    void bfs(){
        
        queue<point> itr;
        
        itr.push(m[0][0]);

        while(itr.front().c != 'F' && !itr.empty()){
            int I = itr.front().i, 
                J = itr.front().j;

            for(int i=0;i<4;i++){

                //NEIGHBOUR : n
                point n = itr.front();
                n.i = itr.front().i + x[i];
                n.j = itr.front().j + y[i];

                if(!out(n.i,n.j) && m[n.i][n.j].flag){
                    
                    itr.push(m[n.i][n.j]);
                    
                    m[n.i][n.j].flag = false;
                    m[n.i][n.j].prev_i = I;
                    m[n.i][n.j].prev_j = J;
                }
            }
            itr.pop();
        }
        if(itr.front().c != 'F') throw "NO SOLUTION";
    }

    void draw(){
        point itr = m[h-1][w-1];
        while(itr.i || itr.j){
            m[itr.i][itr.j].c = 'X';
            min++;
            itr = m[itr.prev_i][itr.prev_j];
        }
        m[0][0].c = 'X';
        min++;
        #ifndef PRINT 
        cout << "STEPS: " << min << "\t";
        #endif
    }

    public:
    maze(vector<string> &input){
        
        int y = input.size(), x = input[0].length();
        
        for(int i=0;i<y;i++){
        
            vector<point> aux(x);
            string s = input[i];

            for(int j=0;j<x;j++){
                aux[j].c = s[j];
                if(s[j] == '#') aux[j].flag = false;
                aux[j].i = i; 
                aux[j].j = j; 
            }

            m.push_back(aux);
            aux.clear();
        }
            w = m[0].size();
            h = m.size();
            min = 0;
    }

    void print(){
        cout << endl;
        for(auto v : m){
            for(auto p : v)
            cout << p.c << " ";
            cout << endl;
        }
        cout << "\nSTEPS: " << min << "\t";
    }

    bool solve(){
        try{
            bfs();
            draw();
        }
        catch(const char *e){
            cerr << e << endl;
            return false;
        }
        return true;
    }
};

vector<string> input(){
    vector<string> i;
    string s;

    while(1){
        getline(cin, s);
        i.push_back(s);
        if(s.back() == 'F') break;
    }

    return i;
}

int main(){

    timeval start, end;
    gettimeofday(&start,nullptr);
    

    vector<string> i = input();
    maze m(i);

    #ifdef PRINT
    if(m.solve()) m.print();
    #else
    m.solve();
    #endif

    gettimeofday(&end,nullptr);

    double t = (double)(end.tv_usec - start.tv_usec)/1000;

    cout << "TIME-LAPSED: " << t << " ms " << endl;

    return 0;
}