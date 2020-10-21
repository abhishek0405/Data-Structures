#include <iostream>
#include<vector>
using namespace std;
void heapify(int ind,vector<int>&v,int size){
    int lind = 2*ind;
    int rind = lind+1;
    int maxind=ind;
    size-=1;
    if(lind<=size && v[lind]>v[ind]){
        maxind=lind;
    }
    if(rind<=size && v[rind]>v[maxind]){
        maxind=rind;
    }
    if(maxind!=ind){
        swap(v[ind],v[maxind]);
        heapify(maxind,v,size);
    }

}

void build_heap(vector<int>&v){
    int st = (v.size()-1)/2;
    for(int i=st;i>=1;i--){
        heapify(i,v,v.size());
    }
}
void heap_sort(vector<int>&v){
    build_heap(v);
    int n=v.size();
    while(n>1){
        //swap first last element
        swap(v[1],v[n-1]);
        //now max element at end so reduce size
        n--;
        //again build heap from first element
        heapify(1,v,n);
    }


}

int main() {
    vector<int>v{-1,4,1,3,8,0,2};
    heap_sort(v);
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}
