#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};


node * buildbst(node *root,int d){

    if(root==NULL){
        return new node(d);
    }

    if(d>root->data){
        root->right = buildbst(root->right,d);
    }
    else{
        root->left = buildbst(root->left,d);
    }

    return root;
}

void bfs(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *t=q.front();
        
        if(t==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
         }
        else{
            cout<<t->data<<" ";
            q.pop();
         if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }
    }
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    node * root=NULL;
    int arr[]={5,3,7,1,6,8};
    for(auto it:arr){
       root= buildbst(root,it);
    }
    inorder(root);
    cout<<endl;
    bfs(root);

}
