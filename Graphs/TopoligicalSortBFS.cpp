#include <iostream>
using namespace std;
#include<queue>
#include<map>
#include<list>

class graph{
    public:
    map<int,list<int>>mp;
    int *visited;
    
    graph(int n){
        visited = new int[n];
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
    }

    void add_edge(int x,int y){
        mp[x].push_back(y);
    }

    /*TOPO SORT USING BFS:
    IDEA
    1)Get indegree of all nodes
    2)Push nodes with 0 indegree in Queue(as no dependency)
    3)do bfs now.(print the node before popping the front)
    4)Whenever a node visited,decrement its indegree
    5)If indegree becomes 0, push it in the queue*/

    void toposortbfs(int n){
        queue<int>q;
        int indegree[n]={0};
        for(auto it:mp){
            int node = it.first;
            for(int nbr:it.second){
                indegree[nbr]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int t = q.front();
            cout<<t<<" ";
            q.pop();
            for(auto nbr:mp[t]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }

        }
    }

    


};

int main() {
    graph g(6);
    g.add_edge(1,0);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(5,1);
    g.toposortbfs(6);
}
