#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int arr[4]={4,3,2,6};//size of ropes
    int count=4;
    int cost=0;
    priority_queue<int,vector<int>,greater<int>>prq(arr,arr+4);
    while(count>1){
        int rope1 = prq.top();//O(1)
        prq.pop();//O(LogN)
        int rope2 = prq.top();
        prq.pop();
        int newrope=rope1+rope2;
        prq.push(newrope);
        cost+=newrope;
        count--;
    }
    cout<<cost<<endl;
}
