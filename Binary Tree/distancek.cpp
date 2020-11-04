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


void ithlevel(node *root,int i){
    if(root==NULL){
        return;
    }
    if(i==0){
        cout<<root->data<<" ";
        return;
    }
    
    ithlevel(root->left,i-1);
    ithlevel(root->right,i-1);
    return;
}





int distancek(node *root,int target,int k){
    //BASE CASE
    if(root==NULL){
        return -1;
    }
    if(root->data==target){ // ONCE FOUND THE NODE, JUST PRINT ALL THE NODES AT ITH DISTANCE BELOW IT.
        ithlevel(root,k);
        return 0;
    }

    int ld = distancek(root->left,target,k);
    
    if(ld!=-1){ // If the node in left subtree, make call with apprpirate distance on the right subtree
        if(ld+1==k){
            cout<<root->data<<" ";
        }
        else{
            ithlevel(root->right,k-ld-2);
        }
        return ld+1;
    }


    int rd = distancek(root->right,target,k); //If the node in right subtree, make call with apprpirate distance on the left subtree
    if(rd!=-1){
        if(rd+1==k){
            cout<<root->data<<" ";
        }
        else{
            ithlevel(root->left,k-rd-2);
        }

        return rd+1;
    }
    return -1;
    }

int main(){
    
    node * root = buildtree();
    int k=2;
    distancek(root,4,k);

    

    
}