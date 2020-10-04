#include <iostream>
#include<unordered_map>
#include<list>
#include<string>
#include<set>
#include<climits>
#include<utility>
using namespace std;
//To model distance between locations
class graph{
    int v;
    unordered_map<string,list<pair<string,int>>> l; // each element in l is a mapping from string to a list of pairs(eg the other city and its distance) it is connected to.
    public:
    void add_edge(string a,string b,int dist,bool isbidirec){
        l[a].push_back(make_pair(b,dist));//l[a] corresponds to list it maps to
        if(isbidirec){
            l[b].push_back(make_pair(a,dist));
        }
    }

    void djkstras(string src){
        unordered_map<string,int> distance;
        set<pair<int,string>> s;//we use the set to get the least distance node of next iteration in o(1) ie the first node in the set.(int ie the distance kept as first para as set sorts wrt first param)
        //INITIALSE DISTANCE FROM SOURCE TO OTHER NODES AS INFINITY
        for (auto it:l){
            //it is pair<str,list<str,int>>
            distance[it.first] =INT_MAX;
        }
        distance[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto nodepair = *(s.begin());
            int dist = nodepair.first;
            string node = nodepair.second;
            s.erase(s.begin());
            for(auto nbr: l[node]){
               // nbr is pair of <str,int>
                if(distance[nbr.first]>dist + nbr.second){
                    //distance[nbr.first] is current distance from source of nbr node
                    //dist is the distance of current node from source.
                    // nbr.second is the distance of the nbr node from the current node.

                    auto t = s.find(make_pair(distance[nbr.first],nbr.first));//find if aldready presennt in set, as in set we can't update, only remove then add new
                    if(t!=s.end()){//ie the pair is aldready present hence remove it
                        s.erase(t);
                    }
                    distance[nbr.first] = dist +nbr.second;
                    s.insert(make_pair(distance[nbr.first],nbr.first));
                }
            }
        }
        for(auto d:distance){
            cout<<d.first<<" is at distance of "<<d.second<<" from source "<<endl;
        }




    }

    void printgraph(){
        for(auto it :l){
            //it would be a pair like this-> <string>,list<pair<<string,integer>> ie a string ->list of pairs
            string source = it.first;
            for(auto it1: it.second){
		//it.second is list of pairs.
                //it1 would be a pair(string,dist)
                string dest = it1.first;
                int dist = it1.second;
                cout<<"Distance between "<<source<<" and "<<dest<<" is "<<dist<<endl;
            }

        }
    }
};

int main() {
    graph g;
    g.add_edge("Mumbai","Pune",100,true);
    g.add_edge("Mumbai","Delhi",2000,true);
    g.add_edge("Pune","Delhi",9000,true);
    g.add_edge("Delhi","Chennai",1800,true);
    g.djkstras("Pune");
    

    
}