#include <iostream>
#include<list>
using namespace std;

class graph{
    int v;
    list<int>* l;//as each element in l will now point to a list of integers. NOTE list<int*> means list with element poining to integer.
    public:
    graph(int vertices){
        v = vertices;
        l = new list<int>[vertices];//AS WE NEED VERTICE NUMBER OF LISTS.
    }
    void add_edge(int a,int b){
        l[a].push_back(b);
        l[b].push_back(a); //for bidirected graph.
    }

    void print_graph(){
        for(int i=0;i<v;i++){
            cout<<i<<" is connected to ";
            for(auto it:l[i]){
                cout<<it<<",";
            }
            cout<<endl;
        }
    }


};
int main() {
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(0,3);
    g.add_edge(2,3);
    g.add_edge(0,2);
    g.print_graph();

    
}
