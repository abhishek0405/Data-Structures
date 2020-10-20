#include <iostream>
#include<vector>
using namespace std;
void heapify(vector<int>&v,int ind){
    int lind=2*ind;
    int rind=lind+1;
    int maxind=ind;
    int size = v.size()-1;
    if(lind<=size && v[lind]>v[ind]){
        maxind=lind;
    }
    if(rind<=size && v[rind]>v[maxind]){
        maxind=rind;
    }
    if(ind!=maxind){
        swap(v[maxind],v[ind]);
        heapify(v,maxind);
    }
}
void makemaxheapefficient(vector<int>&v){
    int start = (v.size()-1)/2;//parent of the last leaf
    for(int i=start;i>=1;i--){
        heapify(v,i);
    }
}

int main() {
    vector<int> v{-1,2,3,5,0,12,4,8};
    makemaxheapefficient(v);
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}
