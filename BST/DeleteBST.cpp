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

node * deleteinbst(node* root,int d){

    if(d>root->data){
       root->right= deleteinbst(root->right,d);
       return root;
    }
    else if(d<root->data){
        root->left = deleteinbst(root->left,d);
        return root;
    }

    else{ //found the node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL){
            node *t = root->right;
            delete root;
            return t;
        }
        else if(root->right==NULL){
            node *t = root->left;
            delete root;
            return t;
        }

        else{ //when 2 children
            node * replacenode = root->right;//as we replace with min in right subtree
            while(replacenode->left!=NULL){
                replacenode=replacenode->left;//recursively go left to get min element
            }
            root->data = replacenode->data;
            root->right=deleteinbst(root->right,replacenode->data);
            return root;

        }
    }


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
    cout<<endl;
    node * root1 = deleteinbst(root,7);
    bfs(root1);

}
