#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
class graph{
    map<int,list<int>> mp;
    int * visited;
    public:
    graph(int nodes){
        for(int i=0;i<nodes;i++){
            visited[i] = 0;
        }
    }

    void add_edge(int x,int y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    int diffconnectedcompBFS(int n){
        queue<int> q;
        int ans,count;
        ans=0;

            int node=0;
            count=0;
            while(count!=n){
                for(int j=0;j<n;j++){
                    if(visited[j]==0){
                        node=j;
                        break;
                    }
                }
            visited[node]=1;
            count++;
            q.push(node);
            while(!q.empty()){
                int t = q.front();
                q.pop();
                for(auto nbr:mp[t]){
                    if(visited[nbr]==0){
                        q.push(nbr);
                        visited[nbr]=1;
                        count++;
                    }
                }
            }
            ans++;
            
        }
        
        
        return ans;
    }
};

int main(){
    graph g(11);
    g.add_edge(0,1);
    g.add_edge(0,3);
    g.add_edge(1,2);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(2,10);
    g.add_edge(6,7);
    g.add_edge(8,9);
   cout<<g.diffconnectedcompBFS(11);


}


