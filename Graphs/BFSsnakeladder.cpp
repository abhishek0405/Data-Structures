#include<iostream>
using namespace std;
#include<queue>
#include<list>
#include<map>
#include<climits>

class graph{
    map<int,list<int>> mp;
    public:
    void add_edge(int src,int dest){
        mp[src].push_back(dest);//as unidirectional graph in this problem
    }

    void bfs(int n){
        int dist[n];
        queue<int>q;
        cout<<"1454";
        q.push(0);
        for(auto neighbpair:mp){
            dist[neighbpair.first]=INT_MAX;
        }
        dist[0]=0;
       while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int nbr:mp[t]){
                //mp[t] is a list of neighbors, hence it is integer
                if(dist[nbr]==INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[t]+1;
                }
            }
        }
    }
        
    
};

int main() {
    int t,n,x,i,j,k,s,l,y;
	cin>>t;
	while(t--){
		cin>>n>>l>>s;
         graph g;
        int jump[n];
        for(i=0;i<l;i++){
            cin>>x>>y;
            jump[x] = y-x;

        }
        for(i=0;i<s;i++){
            cin>>x>>y;
            jump[x] = y-x;
        }

        for(i=0;i<=n;i++){
            for(j=1;j<=6;j++){
                int tt = i+j+jump[i+j];
                if(tt<=n)
                    g.add_edge(i,tt);
            }
        }
        
        g.bfs(n);



	}
	return 0;
}