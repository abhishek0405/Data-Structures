#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left =NULL;
        right = NULL;
    }



};

node* buildtree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    node *root = new node(x);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

node* mirror(node * root){
    if(root==NULL){
        return NULL;
    }
    node * root1 = new node(root->data);
    root1->right = mirror(root->left);
    root1->left = mirror(root->right);
    return root1;

}

void invert_inplace(node * root){
    if(root==NULL){
        return;
    }
    invert_inplace(root->left);
    invert_inplace(root->right);
    swap(root->left,root->right);
}

int main(){
    node * root =  buildtree();
    inorder(root);
    cout<<endl;
    node *root1= mirror(root);
    inorder(root1);
}
