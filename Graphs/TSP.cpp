#include <iostream>
#include<climits>
using namespace std;
//TRAVELLING SALESMAN PROBLEM. Return the distance from src to src covering all cities
int cit = 4;
int arr[4][4];
int dp[16][4];//2^cities states of the bitmask and n cities
int allcovered = (1<<cit)-1;
int tsp(int bitmask,int src){
    if(bitmask==allcovered){//all cities covered. Hence now return distane from current city to the main source (Lets say city A ie 0)
        return arr[src][0];
    }
     if(dp[bitmask][src]!=-1){
            return dp[bitmask][src];
            }
    int minpath = INT_MAX;
   
    for(int i=0;i<cit;i++){//4 cities

        
        //Check if city visited or not,Call func only if not visited.
        //1<<i like 0010 ie 2nd city(when i=1)
        //mask like 0011 ie 2 cities visited.
        //Hence after end we can have 0010 or 0000 for above example. If  equal to 0,then unvisited else visited.
        if(((1<<i)&bitmask)==0){
            //arr[src][i] returns distance from current city ie source to the ith city
            //while calling function use the new mask as mask|(1<<i) ie we add the city to the visited
            int path= arr[src][i] +tsp((1<<i)|bitmask,i);
            minpath = min(path,minpath);
        }
       
    }
    return dp[bitmask][src]= minpath;
}
int main() {
    int i,j;
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cin>>arr[i][j];

        }
    }
    for(i=0;i<16;i++){
        for(j=0;j<4;j++){
            dp[i][j]=-1;
            
        }
    }
    cout<<arr[0][2]<<endl;

    cout<<tsp(1,0);
}
