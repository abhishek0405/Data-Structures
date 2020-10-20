#include <iostream>
#include<vector>
using namespace std;

void makemaxheap(vector<int>&v){
    for(int i=2;i<v.size();i++){
        //in max heap : parent > child
        int ind =i;
        int pind=i/2;
        while(ind>1 && v[pind]<v[ind]){
            swap(v[ind],v[pind]);
            ind/=2;
            pind/=2;

        }
    }
}




int main() {
    vector<int> v{-1,2,3,5,0,12,4,8};
    makemaxheap(v);
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}
