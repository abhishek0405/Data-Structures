#include <iostream>
#include<unordered_map>
#include<list>
#include<string>
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

    void printgraph(){
        for(auto it :l){
            //it would be a pair like this-> <string>,list<pair<<string,integer>> ie a string ->list of pairs
            string source = it.first;
            for(auto it1: it.second){
                //it1 would be list of pairs (string,dist)
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
    g.add_edge("Mumbai","Delhi",10000,true);
    g.add_edge("Pune","Delhi",9000,true);
    g.add_edge("Delhi","Chennai",1800,false);
    g.printgraph();
    

    
}
