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

node * buildbalancedtree(int * arr,int s,int e){
    //base case
    if(s==e){
        node * d=new node(arr[s]);
        return d;
    }

    int m = (s+e)/2;
    node * root = new node(arr[m]);
    root->left=buildbalancedtree(arr,s,m-1);
    root->right=buildbalancedtree(arr,m+1,e);

    return root;

}

int main(){
    
   int arr[100]={2,3,4,5,1,0,9};
   int s,e,n,m;
   n=6;
   s=0;
   e=n;
   node * root = buildbalancedtree(arr,s,e);
   bfs(root);
    

    
}