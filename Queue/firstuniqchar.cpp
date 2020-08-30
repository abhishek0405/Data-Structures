#include <iostream>
#include<queue>
#include<string>
using namespace std;
int main() {
    string s;
    queue<char> q;
    char c;
    cin>>s;
    int i,x,n,l;
    int arr[26]={0};
    l=s.length();
    for(i=0;i<l;i++){
        c=s[i];
        arr[c-'a']++;
        q.push(c);
        while(!q.empty() && arr[q.front()-'a']>1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1";
        }
        else{
            cout<<q.front();
        }
    }
}
