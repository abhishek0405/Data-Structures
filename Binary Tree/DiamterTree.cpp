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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

int getdiameter(node *root){
    if(root==NULL){
        return 0;
    }
    int op1=height(root->left)+height(root->right);
    int op2= getdiameter(root->left);
    int op3 = getdiameter(root->right);
    return max(op1,max(op2,op3));



}

int main(){
    
    node * root = buildtree();
    cout<<endl;
    cout<<height(root);
    cout<<" "<<getdiameter(root);
    

    
}