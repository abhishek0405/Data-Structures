#include <iostream>
#include<stack>

using namespace std;
int main() {
    int n,i,k;
    k=0;
    cin>>n;
    int arr[n];
    int ans[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<pair<int,int>> st;
    i=0;
    while(i<n){
        if(st.empty()){
            st.push(make_pair(i,arr[i]));
            ans[k++]=i+1;
            i++;
        }
        else if(arr[i]>=st.top().second){
            st.pop();
        }
        else{
            ans[k++] = i-(st.top().first);
            st.push(make_pair(i,arr[i]));
            i++;
        }

    }

    for(i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"END"<<endl;

}
