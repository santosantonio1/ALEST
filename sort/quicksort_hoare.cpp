#include <iostream>
using namespace std;
template <typename T>
void hoare(T *v, int low, int high){
    int i = low, j = high;
    T pivot = v[(high+low)/2], aux;
    while(i<=j){
        while(v[i]<pivot){
            i++;
        }
        while(v[j]>pivot){
            j--;
        }
        if(i<=j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    if(low<j) hoare(v,low, j);
    if(i<high) hoare(v,i,high);
}
int main(){
    int v[6] = {1, 5, 6, 2 , 34 , 23};
    hoare(v,0,5);
    for(auto a: v)
    cout << a << " ";
    cout << endl;
    return 0;
}