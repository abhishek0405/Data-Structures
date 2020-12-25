#include<iostream>
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

void printtree(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printtree(root->left);
    
    printtree(root->right);
    return;

}

int getheight(node * root){
    if(root==NULL){
        return 0;
    }
    return max(getheight(root->left),getheight(root->right))+1;

}

void ithlevel(node *root,int i){
    if(root==NULL){
        return;
    }
    if(i==1){
        cout<<root->data<<" ";
        return;
    }
    
    ithlevel(root->left,i-1);
    ithlevel(root->right,i-1);
    return;
}

void levelordertraversal(node *root,int ht){
    int i;
    for(i=1;i<=ht;i++){
        ithlevel(root,i);
        cout<<endl;
    }
    return;
    
}

int main(){
    
    node * root = buildtree();
    printtree(root);
    int ht=getheight(root);
    cout<<endl<<ht<<endl;
    levelordertraversal(root,ht);
    
}