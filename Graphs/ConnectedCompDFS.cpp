#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
class graph{
    public:
    map<int,list<int>> mp;
    int * visited;
    
    graph(int nodes){
        for(int i=0;i<nodes;i++){
            visited[i] = 0;
        }
    }

    void add_edge(int x,int y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    void connected_comp_dfs(int n,int src){
      visited[src]=1;
      for(auto nbr: mp[src]){
          if(!visited[nbr]){
              connected_comp_dfs(n,nbr);
          }
      }  
      

    }
};




int main(){
    graph g(11);
    g.add_edge(0,1);
    g.add_edge(0,3);
    g.add_edge(1,2);
    g.add_edge(3,4);
    g.add_edge(5,5);
    g.add_edge(2,10);
    g.add_edge(6,7);
    g.add_edge(8,9);
   int ans=0;
   //ALGO IS TO ITERATE THROUGH ALL NODES,WHEN YOU FIND NODE NOT VISITED, DFS, HENCE ALL CONNECTED WOULD BE VISITED.
   //Now in the next iteration, the non visited node is taken, again dfs done....THIS IS DONE TILL ALL NODES COVERED
   //Increment by 1 after each dfs traversal.
   for(auto it:g.mp){
       int node = it.first;
       if(g.visited[node]==0){
           g.connected_comp_dfs(11,node);
           ans++;
       }
   }
   cout<<ans;
   cout<<endl;
   //cout<<g.diffconnectedcompBFS(11);


}


