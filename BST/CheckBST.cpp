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

node *search(node *root,int d){
    node *ans;
    if(root==NULL){
        return NULL;
    }
    if(root->data==d){
        return root;
    }
    if(d>root->data){
        ans=search(root->right,d);
    }
    else{
        ans=search(root->left,d);
    }
    return ans;
}

bool check_bst(node * root,int mini,int maxi){

    if(root==NULL){
        return true;
    }

    if(root->data<mini || root->data>maxi){
        return false;
    }

    if(root->data>mini&&root->data<maxi && check_bst(root->left,mini,root->data)&&check_bst(root->right,root->data,maxi)){
        return true;
    }
    return false;
    



}
int main() {
    node * root=NULL;
    node *root1=NULL;
    root1 = buildtree();
    int arr[]={5,3,7,1,6,8};
    for(auto it:arr){
       root= buildbst(root,it);
    }
    cout<<check_bst(root1,-1000,1000);

}
