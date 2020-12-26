#include <iostream>
#include<stack>
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

void preorder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void preorder_iterative(node *root){
    node * curr = root;
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node * t = s.top();
        s.pop();
        cout<<t->data<<" ";
        //first push right node so that left at top and hence processed first in the stack.
        if(t->right){
            s.push(t->right);
        }
        if(t->left){
            s.push(t->left);
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
    return;
}

void inorder_iterative(node *root){
    stack<node *>s;
    node * curr = root;
    while(!s.empty() || curr!=NULL){
        if(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        else{
            node *t = s.top();
            s.pop();
            cout<<t->data<<" ";
            curr = t->right;
        }
    }

}

void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}

void postorder_iterative(node *root){
    stack<node *>s;
    stack<int>out;
    s.push(root);
    node * t;
    while(!s.empty()){
        t = s.top();
        s.pop();
        out.push(t->data);
        if(t->left){
            s.push(t->left);
        }
        if(t->right){
            s.push(t->right);
        }
    }
    while(!out.empty()){
        cout<<out.top()<<" ";
        out.pop();

    }

}




int main(){
    node * root =  buildtree();
    postorder(root);
    cout<<endl;
    postorder_iterative(root);
    
}
