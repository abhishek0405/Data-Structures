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
    if(i==0){
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

node * lca(node *root,int a,int b){
    if(root==NULL){
        return NULL;
    }

    if(root->data==a||root->data==b){ //RETURN THE ADDRESS OF FOUND NODE WHEN MATCHES
        return root;
    }

    node * leftaddr = lca(root->left,a,b);
    node * rightaddr = lca(root->right,a,b);

    if(leftaddr!=NULL && rightaddr!=NULL){ //this would be the lca hence return the root. Since elements are unique, we would get NULL from other branch(THE IRST NODE WHERE THIS SATISFIED)
        return root;
    }

    if(leftaddr!=NULL){
        return leftaddr;
    }
    if(rightaddr!=NULL){
        return rightaddr;
    }

    return NULL; // AS NO CHILD OF THIS ROOT IS ONE OF THE NODES
}

int distfromroot(node *root,int x,int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data==x){
        return dist;
    }
    return max(distfromroot(root->left,x,dist+1),distfromroot(root->right,x,dist+1));
    
}


int distbwnodes(node *root,int a,int b){
    node * lcanode = lca(root,a,b);
    int d1=distfromroot(lcanode,a,0);
    int d2 = distfromroot(lcanode,b,0);
    return d1+d2;

}



int main(){
    
    node * root = buildtree();
    cout<<distbwnodes(root,8,9);

    

    
}