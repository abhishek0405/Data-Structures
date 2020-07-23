#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void insert(node*&head,int d){
    node *n = new node(d);
    node *t = head;
    n->next = head;
    if(head!=NULL){
        while(t->next!=head){
            t = t->next;
        }
        t->next = n;

    }
    else{
        n->next = n;

    }
    head = n;

}

void print(node *head){
    node *t = head;
    while(t->next!=head){
        cout<<t->data<<"->";
        t = t->next;
    }
    cout<<t->data<<endl;
}

node* returnnode(node*head,int d){
    node *t=head;
    while(t->next!=head){
        if(t->data==d){
            return t;
        }
        t = t->next;
    }
    if(t->data==d){
        return t;
    }
    else{
        return NULL;

    }

}

void deletenode(node*&head,int d){
    node *targ = returnnode(head,d);
    if(targ==NULL){
        cout<<"invalid"<<" ";
    }

    else{
        if(targ==head){
            head=head->next;
        }
        else{
            node* t=head;
            while(t->next!=targ){
                t=t->next;
            }
            t->next = targ->next;

        }
        delete targ;
    }
}

int main() {
    node *head=NULL;
    insert(head,5);
    insert(head,10);
    insert(head,9);
    insert(head,1);
    deletenode(head,9);
    print(head);
}
