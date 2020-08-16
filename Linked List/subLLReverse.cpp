#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int d){
        data=d;
        next = NULL;
    }
};

void buildll(node*&head,int d){
    node *n = new node(d);
    node *t = head;
    if(head==NULL){
        head = n;
    }
    else{
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=n;
    }
}
void printll(node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}

node* kreverse(node*head,int k,int n){
    node *curr = head;
    node*pr=NULL;
    node *next = NULL;
    int count = 0;
    while(count<k ){
        next = curr->next;
        curr->next = pr;
        pr = curr;
        curr = next;
        count++;
    }

    if(next!=NULL){
        head ->next = kreverse(next,k,n);

    }

    return pr;
    
}

int main() {
    int n,k,i,x;
    node *head=NULL;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>x;
        buildll(head,x);
    }
    printll(head);
    cout<<endl;
    head = kreverse(head,k,n);
    printll(head);
    


}
