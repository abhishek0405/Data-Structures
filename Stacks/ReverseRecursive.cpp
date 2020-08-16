#include<iostream>
#include<stack>
using namespace std;

void pushbottom(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int d = s.top();
    s.pop();
    pushbottom(s,x);
    s.push(d);

}

void reverse(stack<int>&s){
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    reverse(s);
    pushbottom(s,x);

}
int main(){
    int n,i,x;
    stack<int> s;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        s.push(x);
    }
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<"->";
        s.pop();
    }
    
}
