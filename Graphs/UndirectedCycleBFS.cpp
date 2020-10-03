#include <iostream>
using namespace std;
#include<queue>
#include<map>
#include<list>

class graph{
    public:
    map<int,list<int>>mp;
    int *visited;
    int *parent;
    
    graph(int n){
        visited = new int[n];
        parent = new int[n];
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
    }

    void add_edge(int x,int y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    bool check_cycle(){
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto nbr: mp[t]){
                if(visited[nbr]==1 && parent[t]!=nbr){ // as on visiting 2->5 i make parent of 5 as 2. Hence 5->2 is okay as par[5]=2.But 4->2 will mark a cycle(appraching same node from 2 nodes) 
                    return true;
                }
                if(!visited[nbr]){
                    visited[nbr]=1;
                    parent[nbr]=t;
                    q.push(nbr);
                }
            }
        }
        return false;
    }

    

    


};

int main() {
    graph g(5);
    g.add_edge(0,1);
    g.add_edge(0,3);
    g.add_edge(0,4);
    g.add_edge(1,2);
    
    cout<<g.check_cycle();
    
}