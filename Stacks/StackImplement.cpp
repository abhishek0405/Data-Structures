#include <iostream>
#include<vector>
using namespace std;
template<typename T>// For templating now data will be of type T
class stack{
    private:
    vector<T> v;
    public:

    void push(T d){
        v.push_back(d);
    }

    void pop(){
        if(v.size()>0){
            v.pop_back();
        }
        else{
            cout<<"Empty"<<endl;
        }
    }

    T top(){
        return v[v.size()-1];
    }

    void print(){
        for(T i=v.size()-1;i>=0;i--){
            cout<<v[i]<<"->";
        }
    }


};
int main() {
    stack<int> s; // Specify here which type of stack
    s.push(5);
    s.push(10);
    s.push(20);
    s.print();
    cout<<endl;
    stack<char> u;
    u.push('a');
    u.push('b');
    u.push('c');
    u.push('d');
    u.print();
    cout<<endl;
    u.pop();
    u.print();

}
