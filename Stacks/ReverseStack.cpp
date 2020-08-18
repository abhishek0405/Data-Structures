#include <iostream>
#include<stack>
using namespace std;
//O(N^2) using 2 stacks. O(N) if 3 stacks

int main() {
    stack<int> og;
    stack<int> rev;
    int i,n,x,c;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>x;
        og.push(x);
    }

    for(i=0;i<n;i++){
        //fetch top element from og stack
        x = og.top();
        og.pop();
        c=0;
        //transfer to 2nd rev stack
        while(c<(n-i-1)){
            rev.push(og.top());
            og.pop();
            c++;
        }
        //make the popped element from top at respective bottom pos
        og.push(x);
        //Re transfer values from rev stack to og stack.
        while(!rev.empty()){
            og.push(rev.top());
            rev.pop();
        }
}
    

    

    while(!og.empty()){
        cout<<og.top()<<"->";
        og.pop();

    }



}
