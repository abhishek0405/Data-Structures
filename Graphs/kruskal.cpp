#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<list>

class dsu{
    int *parent;
    int *rank;
    vector<pair<pair<int,int>,int>> l; //(dist,x,y) store dist first as sort by distance(first element)
    public:
    dsu(int v){
        parent =new int[v];
        rank = new int[v];
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }

    int find(int x,int *parent){
        if(parent[x]==-1){
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }

    void rankunion(int x,int y,int *parent,int * rank){
        int s1 = find(x,parent);
        int s2 = find(y,parent);
        if(s1!=s2){
            if(rank[s1]>rank[s2]){
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
            else{
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
        }
    }

    void add_edge(int x,int y,int wt){
        pair<pair<int,int>,int> p;
        p.first.first=wt;
        p.first.second=x;
        p.second=y;
        l.push_back(p);
    }

    void kruskal(){
        int ans=0;
        sort(l.begin(),l.end());
        for(auto edge:l){
            //edge->(dist,x,y) ie <<int,int>,int>
            int dist = edge.first.first;
            int x = edge.first.second;
            int y = edge.second;
            if(find(x,parent)!=find(y,parent)){//ie different set hence cycle won't from so can take this.
                rankunion(x,y,parent,rank);
                ans+=dist;
            }

        }
        cout<<ans<<endl;
    }
    

};


int main() {
    int node,edge,x,y,wt;
    cin>>node>>edge;
    dsu g(node);
    for(int i=0;i<edge;i++){
        cin>>x>>y>>wt;
        g.add_edge(x-1,y-1,wt);
    }
    g.kruskal();

}
