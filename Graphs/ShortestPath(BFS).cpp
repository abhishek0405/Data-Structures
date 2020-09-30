#include <iostream>
#include<list>
#include<queue>
#include<climits>
using namespace std;
class graph{
    int v;
    list<int>* l;
    queue<int> q;
    int *distance;
    public:

    graph(int vertices){
        v = vertices;
        l = new list<int>[vertices];
    }

    void add_edge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);

    }
    //SHORTEST PATH USING BFS ONLY FOR UNWEIGHTED GRAPH
    void bfs(){
        for(int i=0;i<v;i++){
            distance[i]=INT_MAX;
        }
        q.push(0);
        distance[0]=0;
        while(!q.empty()){
            int currnode = q.front();
            q.pop();
            cout<<currnode<<" ";
            for(int neigbor:l[currnode]){
                if(distance[neigbor]==INT_MAX){
                    q.push(neigbor);
                    distance[neigbor] = distance[currnode]+1; //since the node neighboe is conncected to node currnode, nbor will havae distance 1 more than distance of currnode from source.
                }
            }
        }
        cout<<endl;
        for(int i=0;i<v;i++){
            cout<<"Distance of source(node 0) to node "<<i<<" is "<<distance[i]<<endl;
        }
    }
};
int main() {
    graph g(6);
    g.add_edge(0,1);
    g.add_edge(0,4);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(4,5);
    g.add_edge(3,5);
    g.add_edge(5,2);
    g.bfs();
    
    
}
