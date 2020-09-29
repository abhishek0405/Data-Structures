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

int countnodes(node *root){
    if(root==NULL){
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;
}

int nodessum(node *root){
     if(root==NULL){
        return 0;
    }
    return nodessum(root->left)+nodessum(root->right)+root->data;
}

int main(){
    
    node * root = buildtree();
    cout<<countnodes(root);
    cout<<endl;
    cout<<nodessum(root);
    

    
}