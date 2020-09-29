#include <iostream>
using namespace std;
class treenode{
    public:
    int data;
    treenode* left;
    treenode* right;
    treenode(int d){
        data=d;
        left = NULL;
        right=NULL;
    }
};

treenode *buildtree(){
        int d;
        cin>>d;
        if(d==-1){
            return NULL;
        }
        treenode * root = new treenode(d);
        root->left = buildtree();
        root->right = buildtree();
        return root;
    }

    void printpreorder(treenode *root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        printpreorder(root->left);
        printpreorder(root->right);

    }

    void printinorder(treenode *root){
        if(root==NULL){
            return;
        }
        printinorder(root->left);
        cout<<root->data<<" ";
        printinorder(root->right);
        

    }

     void printpostorder(treenode *root){
        if(root==NULL){
            return;
        }
        printpostorder(root->left);
        printpostorder(root->right);
        cout<<root->data<<" ";
        

    }

    


int main(){
    treenode * root = buildtree();
    printpreorder(root);
    cout<<endl;
    printinorder(root);
    cout<<endl;
    printpostorder(root);
    
}