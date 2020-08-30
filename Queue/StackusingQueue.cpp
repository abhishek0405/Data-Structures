#include <iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
//This stack does push in O(1),pop,top in O(N)
class stack{
    queue<int> q1,q2;
    public:

    void push(int x){
        if((q1.empty() && q2.empty()) ||(q2.empty())){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }

    void pop(){
        if(!q1.empty()){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
;            }
             q1.pop();
        }
        else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
;            }
             q2.pop();

        }
    }

    void top(){
        if(!q1.empty()){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
           }
            cout<<q1.front();
            q2.push(q1.front());
            q1.pop();
        }

        else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
           }
            cout<<q2.front();
             q1.push(q2.front());
             q2.pop();
        }
    }

};
int main() {
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    st.push(5);
    st.pop();
    st.top();
}
