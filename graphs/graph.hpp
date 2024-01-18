#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

template<typename T> class graph{
    private:
    size_t max;
    vector<T> nodes;
    vector<vector<bool>> adjMatrix;
    vector<bool> marks;

    public:
    graph(ifstream &in);
    graph(size_t n);
    ~graph();
    
    vector<T> getNodes() const;
    bool contains(T d) const;
    vector<T> reach(T v);

    void mark(size_t i);
    void unmark(size_t i);
    bool ismarked(size_t i) const;
    int degree(T d) const;
    
    int size() const;
    void addEdge(size_t i, size_t j);
    void removeEdge(size_t i, size_t j);
    bool isEdge(size_t i, size_t j) const;
    
    void reset();
    
    void print() const;
    string graphViz() const;
};



template<typename T> graph<T>::graph(size_t n){
    max = n;
    adjMatrix.resize(n);
    marks.resize(n);
    nodes.resize(n);
    for(size_t i=0;i<max;i++) adjMatrix[i].resize(n);
}
template<typename T> graph<T>::graph(ifstream &in){
    T a,b;
    size_t sz = 0;
    adjMatrix.resize(10);
    for(size_t i=0;i<10;i++)
        adjMatrix[i].resize(10);
    while(in >> a && in >> b){
        if(!contains(a)){
            sz++; 
            nodes.push_back(a);
        }
        if(!contains(b)){
            sz++; nodes.push_back(b);
        }
        size_t i,j;
        for(i=0;i<nodes.size();i++) if(nodes[i] == a) break;
        for(j=0;j<nodes.size();j++) if(nodes[j] == b) break;
        if(i>=adjMatrix.size() || j>=adjMatrix.size()){
            adjMatrix.resize(adjMatrix.size()*2);
            for(size_t k=0;k<adjMatrix.size();k++)
                adjMatrix[k].resize(adjMatrix.size());
        }
        adjMatrix[i][j] = true;
    }
    adjMatrix.resize(sz);
    for(size_t i=0;i<sz;i++) adjMatrix[i].resize(sz);
    marks.resize(sz);
    max = sz;
}
template<typename T> graph<T>::~graph(){

}
template<typename T> vector<T> graph<T>::getNodes() const{
    return nodes;
}
template<typename T> void graph<T>::mark(size_t i){
    if(i>=0 && i<max) marks[i] = true;
    else throw "ERROR : mark()";
}
template<typename T> void graph<T>::unmark(size_t i){
    if(i>=0 && i<max) marks[i] = false;
    else throw "ERROR : ummark()";
}
template<typename T> bool graph<T>::ismarked(size_t i) const{
    if(i>=0 && i<max) return marks[i];
    else throw "ERROR : ismarked()";
}
template<typename T> int graph<T>::size() const{
    return max;
}
template<typename T> void graph<T>::addEdge(size_t i, size_t j){
    if(i>=0 && i<max){
        if(j>=0 && j<max)
        adjMatrix[i][j] = true;
        return;
    }
        throw "ERROR : addEdge()";
}
template<typename T> void graph<T>::removeEdge(size_t i, size_t j){
if(i>=0 && i<max){
    if(j>=0 && j<max)
    adjMatrix[i][j] = false;
    return;
}
    throw "ERROR : removeEdge()";
}
template<typename T> bool graph<T>::isEdge(size_t i, size_t j) const{
if(i>=0 && i<max)
    if(j>=0 && j<max) return adjMatrix[i][j];
    
return false;
}
template<typename T> void graph<T>::reset(){
    for(size_t i=0;i<max;i++) marks[i] = false;
}
template<typename T> int graph<T>::degree(T d) const{
    if(contains(d)){
        size_t x = 0;
        size_t i;
        for(i = 0;i<max;i++) if(nodes[i] == d) break;
        for(auto e : adjMatrix[i]) if(e) x++;
        
        return x; 
    }
    throw "ERROR : degree()";
}
template<typename T> void graph<T>::print() const{
    cout << "    ";
    for(auto a : nodes) cout << a << " ";
    cout << endl;

    for(size_t i=0;i<max;i++){
        cout << nodes[i] << " | ";
        for(size_t j=0;j<max;j++)   cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}
template<typename T> string graph<T>::graphViz() const{
    stringstream ss;
    ss << "digraph G{" << endl;
    ss << "\trankdir = LR;" << endl;
    ss << "\tnode[shape = circle];" << endl;
    for(size_t i=0;i<max;i++){
        for(size_t j=0;j<max;j++){
            if(isEdge(i,j)) ss << "\t" << nodes[i] << " -> " << nodes[j] << endl; 
        }
    }
    ss << "}" << endl;
    return ss.str();
}
template<typename T> bool graph<T>::contains(T d) const{
    if (nodes.empty()) return false;
    for(auto a : nodes) if(a == d) return true;
    return false;
}
template<typename T> vector<T> graph<T>::reach(T v){
    if(!contains(v)) throw "ERROR : reach()";
    vector<T> n;
    queue<size_t> q;
    for(size_t i=0;i<max;i++)
        if(nodes[i]==v){
            q.push(i);
            mark(i);
            break;
        }
    int i;
    while(!q.empty()){
        i=q.front();
        mark(i);
        n.push_back(nodes[i]);
        for(size_t j=0;j<max;j++){
            if(isEdge(i,j) && !ismarked(j)){
                q.push(j);
            }
        }
        q.pop();
    }    
    reset();
    return n;
}
#endif
