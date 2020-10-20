#include <iostream>
#include<vector>
using namespace std;

class heap{
    vector<int>v;
    bool isminheap;
    public:
     heap(bool type=true){
        isminheap=type;
        v.push_back(-1);
    }


    bool compare(int a,int b){
        //a->index b->pindex
        if(isminheap){
            return a<b; //if current index val smaller than parent index val then should swap
        }
        else{
            return a>b; //if max heap swap if current index greater than parent index
        }
    }

    void heapify(int idx){
        int lind=2*idx;
        int rind=lind+1;
        int lastind = v.size()-1;
        int min_index = idx;
        if(lind<=lastind && compare(v[lind],v[idx])){
            min_index=lind;
        }
        if(rind<=lastind && compare(v[rind],v[min_index])){
            min_index=rind;
        }
        if(min_index!=idx){
            swap(v[min_index],v[idx]);
            heapify(min_index);
        }
    }

   

    void push(int d){
        //Add element at end
        v.push_back(d);
        //Check index and parent index
        int index = v.size()-1;//as one extra due to -1 at 0 index.
        int pindex = index/2;
        //If position not correct ie heap order property not satisfied,swap with parent till correct.
        while(compare(v[index],v[pindex]) && index>1){
            //If heap order not satisfied then swap
            swap(v[index],v[pindex]);
            //change the current index and pindex
            index/=2;
            pindex/=2;


        }

    }

    int get(){
       return  v[1];
    }

    void pop(){
        int s = v.size()-1;//current last index
        swap(v[1],v[s]);
        v.pop_back();//deleted the first ie min/max ele
        heapify(1);//heapify the tree form first index
    }

    void print(){
        for(int i=1;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }

};


int main() {
    heap h(false);
    h.push(5);
    h.push(2);
    h.push(-1);
    h.push(12);
    h.print();
    h.pop();
    cout<<endl;
    h.print();
}
