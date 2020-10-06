#include <iostream>
#include<list>
using namespace std;

class graph{
    list<pair<int,int>> l;
    public:

    void add_edge(int x,int y){
        l.push_back(make_pair(x,y));
    }

    int find(int x,int *parent){//added path compression
        if(parent[x]==-1){
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }

    void union_nodes(int x,int y,int *parent,int *rank){//Added rank optimisation
        int set1 = find(x,parent);
        int set2=find(y,parent);
        if(set1!=set2){//if equal then cycle created
            if(rank[set1]>rank[set2]){ //ie set 1 has more nodes in it
                parent[set2]=set1; //parent of lesser rank set. ie connecting small to large.
                rank[set1]+=rank[set2];//adding smaller elements rank to larger.
            }
            else{//set 2 is more
                parent[set1]=set2;
                rank[set2]+=rank[set1];
            }
        }
    }

    bool check_cycle(){
        int i;
        int parent[100];
        int rank[100];
        for(i=0;i<100;i++){
            rank[i]=1;
            parent[i]=-1;
        }
        for(auto it:l){
            int x = it.first;
            int y = it.second;
            int s1 = find(x,parent);
            int s2 = find(y,parent);
            if(s1!=s2){
                union_nodes(s1,s2,parent,rank);
            }
            else{
                return true;
            }
        }
        return false;
    }



};
int main() {
    graph g;
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,0);
    
    cout<<g.check_cycle();
}
