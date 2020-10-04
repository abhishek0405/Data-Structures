#include <iostream>
using namespace std;
#include<queue>
#include<map>
#include<list>


void floodfill(int arr[][100],int ans,int i,int j,int r,int c,int og){
    if(i<0 || i>=r|| j<0 || j>=c){
        return;
    }
    if(arr[i][j]!=og){
        return;
    }
    arr[i][j]=ans;
    floodfill(arr,ans,i+1,j,r,c,og);
    floodfill(arr,ans,i,j+1,r,c,og);
    floodfill(arr,ans,i-1,j,r,c,og);
    floodfill(arr,ans,i,j-1,r,c,og);

}

int main(){
    int r,c,i,j,k,x;
    cin>>r>>c;
    int arr[100][100];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    int og = arr[r-1][c-1];
    floodfill(arr,5,r-1,c-1,r,c,og);
     for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


}