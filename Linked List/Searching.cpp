#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node*next;
        node(int d){
            data = d;
        }
};

void inserthead(node*&head,int d){
    node *n = new node(d);
    n->next = head;
    head = n;
}

void inserttail(node*head,int d){
    while(head->next!=NULL){
        head=head->next;
    }
    node *n = new node(d);
    head->next = n;
    n->next=NULL;
}

void printnode(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;

    }
}

void searchnodeiterative(node*head,int d){
    while(head!=NULL){
        if(head->data==d){
            cout<<"YES"<<endl;
            return;
        }
        head=head->next;
    }
    cout<<"NO"<<endl;
    return;
}

void searchnoderecursive(node*head,int d){
    if(head==NULL){
        cout<<"NO"<<" ";
        return;
    }

    if(head->data==d){
        cout<<"YES"<<" ";
        return;
    }
    searchnoderecursive(head->next,d);
}

void buildll(node*&head){
    int ip;
    cin>>ip;
    while(ip!=-1){
        if(head==NULL){
            inserthead(head,ip);
        }
        else{
        inserttail(head,ip);
        
        }
        cin>>ip;
        }
    return;
    }

 istream& operator >>(istream &ip,node*&head){
    buildll(head);
    return ip;
}

ostream& operator <<(ostream&op,node*head){
    printnode(head);
    return op;
}
    


int main(){
    node *head = NULL;
    cin>>head;
    cout<<head;
    cout<<endl;
    searchnodeiterative(head,5);
    searchnodeiterative(head,7);
    searchnoderecursive(head,4);
    searchnoderecursive(head,-1);
}