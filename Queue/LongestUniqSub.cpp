#include <iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int main(){
    int maxi,i,j,k,x,l,c,t;
    cin>>t;
    while(t--){
    c=0;
    string s;
    cin>>s;
    l=s.length();
    queue<char>q;
    maxi=1;
    int count[26]={0};
    for(i=0;i<l;i++){
      if(count[s[i]-'a']==0){
          count[s[i]-'a']++;
          c++;
          q.push(s[i]);
      }
      else{
          while(!q.empty() && count[s[i]-'a']>0){
               count[q.front()-'a']--;
               c--;
               q.pop();
          }
          q.push(s[i]);
          c++;
          count[s[i]-'a']++;
      }
        maxi = max(c,maxi);
        
    }
    cout<<maxi<<endl;
    }


}
