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
        
    }

    bool detect_cycle_directed(int node,int *visited,int *inpath){

        visited[node]=1;
        inpath[node]=1;

        for(auto nbr : mp[node]){
            if(inpath[nbr]==1){
                return true;
            }
            else if(!visited[nbr]){
                bool check_cycle = detect_cycle_directed(nbr,visited,inpath);
                if(check_cycle){
                    return true;
                }
                //DONT DEAL WITH FALSE CASE HERE AS WE WILL REMOVE FROM PATH IN THE END(AFTER COVERING NBRS ALL)
            }
        }
        inpath[node]=0;
        return false;
    }

   
};

int main() {
    graph g(5);
    g.add_edge(0,1);
    g.add_edge(0,3);
    g.add_edge(1,2);
    g.add_edge(1,4);
    g.add_edge(2,4);
    g.add_edge(2,3);
    g.add_edge(4,3);
    g.add_edge(4,0);
    int visited[5]={0};
    int inpath[5]={0};
    cout<<g.detect_cycle_directed(0,visited,inpath);
    
}