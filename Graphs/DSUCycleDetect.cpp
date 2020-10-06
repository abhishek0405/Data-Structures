#include <iostream>
#include<list>
using namespace std;

class graph{
    list<pair<int,int>> l;
    public:

    void add_edge(int x,int y){
        l.push_back(make_pair(x,y));
    }

    int find(int x,int *parent){
        if(parent[x]==-1){
            return x;
        }
        return find(parent[x],parent);
    }

    void union_nodes(int x,int y,int *parent){
        int set1 = find(x,parent);
        int set2=find(y,parent);
        if(set1!=set2){//if equal then cycle created
            parent[set1]=set2;
        }
    }

    bool check_cycle(){
        int i;
        int parent[100];
        for(i=0;i<100;i++){
            parent[i]=-1;
        }
        for(auto it:l){
            int x = it.first;
            int y = it.second;
            int s1 = find(x,parent);
            int s2 = find(y,parent);
            if(s1!=s2){
                union_nodes(s1,s2,parent);
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
