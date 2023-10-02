template <typename T>
void bubble_sort(T *v, int t){
    int flag;
    do{
        flag = 0;
        t--;
        for(int i=0; i<t;i++)
        if(v[i]<v[i+1]){
            T aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
            flag = 1;
        }
    }while (flag);
}
template <typename T>
void selection_sort(T*v, int t){
    for(int i=0; i<t-1;i++){
        int min = i;
        for(int j=0;j<t;j++)
            if(v[j]<v[min])
                min = j;
            if(min!=i) {
                T aux = v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
    }
}
template <typename T>
void insertion_sort(T *v, int t){
    for(int i=1; i<t; i++){
        T base = v[i];
        int j = i-1;
        while(j>=0 && base<v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = base;
    }
}
template <typename T>
void merge(T *v, int low, int mid, int high){
    int left_it = low, right_it = mid + 1, aux_it = 0;
    T *aux = new T[high-end+1];
    for(int i=0; i<high + 1; i++){
        if(left_it > mid)             aux[aux_it++] = v[right_it++];
        else 
        if (right_it > high)          aux[aux_it++] = v[left_it++];
        else 
        if (v[left_it] < v[right_it]) aux[aux_it++] = v[left_it++];
        else        
                                      aux[aux_it++] = v[right_it++];
    }
    for(int i=0; i<right_it; i++) v[low++] = aux[i];
    delete[] aux;
}
template <typename T>
void merge_sort(T *v, int low, int high){
    if(low>=high) return;
    int mid = (high+low)/2;
    merge_sort(v, low, mid);
    merge_sort(v, mid+1, high);
    merge(v, low, mid, high);
}
