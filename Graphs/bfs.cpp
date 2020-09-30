#include <iostream>
#include<list>
#include<queue>
using namespace std;
class graph{
    int v;
    list<int>* l;
    queue<int> q;
    int *visited;
    public:

    graph(int vertices){
        v = vertices;
        l = new list<int>[vertices];
    }

    void add_edge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);

    }

    void bfs(){
        for(int i=0;i<v;i++){
            visited[i] = 0;
        }
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            cout<<t<<" ";
            for(int it:l[t]){
                if(visited[it]==0){
                    q.push(it);
                    visited[it]=1;
                }
            }


        }
    }
};
int main() {
    graph g(5);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,0);
    g.add_edge(3,4);
    g.bfs();
    
    
}
