#include <iostream>
using namespace std;
#include<queue>
#include<map>
#include<list>

class graph{
    public:
    map<int,list<int>>mp;
    int *visited;
    int *inpath; //array that tells whether current node in the recursive path.If i reach a node which is aldready in the path, then cycle exist.
    
    graph(int n){
        visited = new int[n];
        inpath = new int[n];
        for(int i=0;i<n;i++){
            visited[i]=0;
            inpath[i]=0;
        }
    }

    void add_edge(int x,int y){
        mp[x].push_back(y);
        mp[y].push_back(x);
        
    }

    bool undirected_cycle(int *visited,int node,int parent){
        visited[node]=1;
        for(int nbr: mp[node]){
           if(!visited[nbr]){
           bool cycle =  undirected_cycle(visited,nbr,node);
           if(cycle)
            return cycle;
           }
           else{
           if(nbr!=parent){
               return true;
           }
           
           }
        }
        return false;
    }



    
             

   
};

int main() {
    graph g(5);
    g.add_edge(0,1);
    g.add_edge(1,3);
    g.add_edge(3,4);
    g.add_edge(4,2);
    g.add_edge(0,2);
    int visited[5]={0};
    cout<<g.undirected_cycle(visited,0,0);
    
    
}