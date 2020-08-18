#include <iostream>
#include<stack>
#include<string>
using namespace std;

bool check(string s){
    
    int i,x,l;
    l = s.length();
    stack<char> st;
    for(i=0;i<l;i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }

        if(st.empty()){
            return false;
        }

        if(s[i]==')'){
            if(st.top()!='('){
                return false;
            }
            else{
                st.pop();
            }
        }
        else if(s[i]=='}'){
            if(st.top()!='{'){
                return false;
            }
            else{
                st.pop();
            }
        }
        else if(s[i]==']'){
            if(st.top()!=']'){
                return false;
            }
            else{
                st.pop();
            }
        }
        
    }

    if(st.empty())
        return true;
    else{
        return false;
    }

}
int main() {
    string s;
    cin>>s;
    if(check(s)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    
}
