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

int solve(node *root,int &final_ans){
    if(root==NULL){
        return 0;
    }
    int ans1 = root->data;
    if(root->left){
        ans1+= solve(root->left->left,final_ans)+solve(root->left->right,final_ans);
    }
    if(root->right){
        ans1+= solve(root->right->left,final_ans)+solve(root->right->right,final_ans);
    }
    int ans2 = 0;
    ans2+= solve(root->left,final_ans)+solve(root->right,final_ans);
    return max(ans1,ans2);

    }



int main(){
    
    node * root = buildtree();
    int final_ans=0;
    cout<<solve(root,final_ans);
    
}