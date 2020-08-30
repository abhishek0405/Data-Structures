#include <iostream>
#include<algorithm>
#include<deque>
using namespace std;
int main() {
    long long int n,k,i,j,x;
    deque<int>q;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    for(i=0;i<k;i++){
        while(!q.empty()&&arr[i]>arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    for(;i<n;i++){
        cout<<arr[q.front()]<<" ";
        //i->end of window.Hence if ndex <=i-k, it is out of window and pop it out.
        while(!q.empty()&&q.front()<=i-k){
            q.pop_front();
        }
        //Remove unnecessary elements
        while(!q.empty()&& arr[i]>arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()];
}
