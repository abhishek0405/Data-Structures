#include<iostream>
using namespace std;
#include<queue>
#include<list>
#include<map>
#include<climits>

class graph{
    public:
    int * visited;
    map<int,list<int>>mp;
    graph(int n){
        visited = new int[n];
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
    }
};

void add_edge(graph &g,int x,int y){
    g.mp[x].push_back(y);
    g.mp[y].push_back(x);
}

void dfs(graph &g,int src){
    cout<<src<<" ";
    g.visited[src]=1;
    for(auto nbr:g.mp[src]){
        if(g.visited[nbr]==0){
            dfs(g,nbr);
            
        }
        
        
    }

}

int main(){
    
    int n;
    cin>>n;
    graph g(n);
    add_edge(g,0,1);
    add_edge(g,0,2);
    add_edge(g,0,5);
    add_edge(g,1,2);
    add_edge(g,2,5);
    add_edge(g,2,3);
    dfs(g,0);

    
}