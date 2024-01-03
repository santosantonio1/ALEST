/*
    maze.cpp
    @Antonio dos Santos
    Maze solver
    OBS: The path found is the shortest
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct point{
    char c;
    bool flag;
    int i,j,prev_i, prev_j;
    point(){
        c = '#';
        flag = true;
        prev_i = prev_j = i = j = 0;
    }
};
//check if position is out of bound
bool out(int m, int n, int x, int y){
    if(x<0 || y<0) return true;
    if(x>=m || y>=n) return true;
    return false;
}
int main(){
    int m = 0, n = 0;
    string s;
    queue<string> store;
    //create maze from input
    while(1){
        getline(cin, s);
        store.push(s);
        n = s.length();
        m++;
        if(s.back() == 'F') break;
    }
    point maze[m][n];
    for(int i=0; i<m; i++){
        s = store.front();
        for(int j=0; j<n; j++){
            maze[i][j].c = s[j];
            if(maze[i][j].c == '#') maze[i][j].flag = false;
            maze[i][j].i = i;
            maze[i][j].j = j;
        }
        store.pop();
    }

    queue<point> itr;
    stack<point> path;
    //movement (N-S-E-W)
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    itr.push(maze[0][0]);
    bool walk = true;
    //create possible paths
    while(walk){
            int I, J;
            I = itr.front().i;
            J = itr.front().j;
            //push neighbours into stack path
        for(int i=0; i<4; i++){
            point neighbour = itr.front();
            neighbour.i = itr.front().i + x[i];
            neighbour.j = itr.front().j + y[i];
            if(!out(m,n,neighbour.i,neighbour.j) && maze[neighbour.i][neighbour.j].flag) {
                maze[neighbour.i][neighbour.j].flag = false;
                maze[neighbour.i][neighbour.j].prev_i = I;
                maze[neighbour.i][neighbour.j].prev_j = J;
                itr.push(maze[neighbour.i][neighbour.j]);
                path.push(maze[neighbour.i][neighbour.j]);
                if(maze[neighbour.i][neighbour.j].c == 'F') {
                    walk = false;
                    break;
                }
            }
        }
        itr.pop();
        if(itr.empty()) {
            cout << "IMPOSSIBLE" << endl;
            return 1;
        }
    }
    int I, J;
    //walk back
    walk = true;
    maze[path.top().i][path.top().j].c = 'X';
    while(walk){
        I = path.top().prev_i;
        J = path.top().prev_j;
        maze[I][J].c = 'X';
        while(path.top().i != I || path.top().j != J){
            path.pop();
        }
        if(path.top().prev_i == 0 && path.top().prev_j == 0) walk = false;
    }
    //print maze
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
        cout << maze[i][j].c << " ";
        cout << endl;
    }
    return 0; 
}