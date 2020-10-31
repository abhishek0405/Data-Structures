#include <iostream>
#include<climits>
#include<vector>
using namespace std;
//Idea is to give alternate colors to nodes,if situation arises where 2 nodes get same color,then return false.
bool check_bipartite(int *colors,int currcolor,vector<int>*g,int node,int parent){
    colors[node]=currcolor;//we come only when node hasnt been covered yet so allocate color directly
    for(auto nbr:g[node]){
        if(colors[nbr]==-1){
            //currcolor->1 hence !currcolor->0
            bool check = check_bipartite(colors,!currcolor,g,nbr,node);
            if(!check){
                return false;
            }
        }
        //visited adready
        else{
            //if nbr has same color(cyclic nbr)
            if(nbr!=parent && colors[nbr]==currcolor){
                return false;
            }
        }
    }
    return true;
    
    
}

int main(){
    int n,x,y;
    int colors[100];
    for(int i=0;i<100;i++){
        colors[i]=-1;
    }
    vector<int> g[100];
    cin>>n;
    while(n--){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout<<check_bipartite(colors,0,g,0,-1);

}