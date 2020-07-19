#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void inserthead(int d,node*&head){ //we want to change head here hence passed by reference
    node *n = new node(d);
    n->next=head;
    head=n;
}

void inserttail(int d,node*head){ //since head is not be changed pass by value
    while(head->next!=NULL){ // No node *t needed as head is passed by value.
        head=head->next;
    }
    node *n=new node(d);
    head->next = n;
    n->next=NULL;
}

void insertmiddle(int pos,int d,node*head){
    int c=0;
    while(c<pos-2){
        c++;
        head=head->next;
    }
    node*n = new node(d);
    n->next=head->next;
    head->next=n;
}

void deleltehead(node*&head){ //head has to be sent by reference
    node *t=head;
    head=head->next;
    delete t;
}

void deletetail(node*head){
    node*prev=head;
    while(head->next!=NULL){
        prev=head;
        head=head->next;
    }
    prev->next=NULL;
    delete head;
}

void deletemid(node*head,int pos){
    int c=0;
    while(c<pos-2){
        c++;
        head=head->next;
    }
    node *t=head->next;
    head->next = head->next->next;
    delete t;
    
}



void printlinkedlist(node*head){//head should not be permanently changed hence pass by value.
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main() {
    node *head=NULL;
    inserthead(1,head);
    inserttail(10,head);
    inserthead(3,head);
    inserthead(5,head);
    insertmiddle(3,7,head);
    insertmiddle(1,0,head);
    insertmiddle(2,-1,head);
    deleltehead(head);
    deletetail(head);
    deletemid(head,4);
    
    printlinkedlist(head);
}
