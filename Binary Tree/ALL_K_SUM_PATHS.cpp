#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d){
        data =d;
        left=NULL;
        right=NULL;
    }

};

node *buildtree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    node * root = new node(x);
    root->left = buildtree();
    root->right = buildtree();
    return root;

}
void ksumpath(node * root,int k,vector<int>&v){
    if(root==NULL){
        return;
    }
    //push element to vector 
    v.push_back(root->data);
    ksumpath(root->left,k,v);
    ksumpath(root->right,k,v);
    //if here means traversed one complete path from roott to leaf. Now vector stores the path,check one by one from end to start if any sub path is k sum
    //start from end as we will pop the last one
    int sum=0;
    int i;
    for(i=v.size()-1;i>=0;i--){
        sum+= v[i];
        if(sum ==k){
            for(int j=v.size()-1;j>=i;j--){
                cout<<v[j]<<" ";
            }
            cout<<endl;
        }
    }
    v.pop_back();

}




int main(){
    
    node * root = buildtree();
    vector<int>v;
    int k=-1;
    ksumpath(root,k,v);
    

    
}