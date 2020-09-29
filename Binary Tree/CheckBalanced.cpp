#include <iostream>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d){
    data=d;
    left=NULL;
    right=NULL;
    }
};

node *buildtree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}




void bfs(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);//NULL MARKS A NEW LINE TO BE PRINTED. I.E 1 LEVEL BETWEEN 2 NULLS.
    while(!q.empty()){
        node * t=q.front();
        if(t==NULL){//1st NULL encountered 
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);//ADDING A NEW NULL VALUE.(HENCE THE LEVEL STORED BEFORE THIS NULL)
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

pair<int,bool> checkbalanced(node *root){
    if(root==NULL){
        pair<int,bool> p;
        p.first=0;
        p.second=true;
        return p;
        
    }
    pair<int,bool> proot;
    pair<int,bool> pleft;
    pair<int,bool> pright;
    pleft = checkbalanced(root->left);
    pright = checkbalanced(root->right);
    proot.first = max(pleft.first,pright.first)+1;
    if(abs(pleft.first-pright.first)<=1 &&pleft.second && pright.second){//ht check and both children should be balanced as we need all nodes balanced.
        proot.second=true;
    }
    else{
        proot.second=false;

    }

    return proot;

}





int main() {
    node *r=buildtree();
    bfs(r);
    pair<int,bool> p;
    p=checkbalanced(r);
    cout<<endl;
    cout<<p.second;
}
