#include <iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.top();
    cout<<endl;
    cout<<s.empty();
    stack<char> u;
    u.push('a');
    u.push('b');
    u.push('c');
    u.push('d');
    cout<<endl;
    u.pop();
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<s.empty();
    
}
