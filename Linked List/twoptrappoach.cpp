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

void inserttail(node *&head,int d){
    if(head==NULL){
        head = new node(d);
    }
    else{
        node *t = head;
        while(t->next!=NULL){
            t = t->next;
        }
        node *n = new node(d);
        t->next = n;
    }
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void getmid(node *head){
    node *p1 = head;
    node*p2 = head;
    while(p1!=NULL && p1->next!=NULL){
        p1 = p1->next->next;
        p2 = p2->next;
    }
    cout<<"Mid is "<<p2->data<<endl;
}

void kthfromend(node* head,int k){
    node* f=head;
    node *s = head;
    while(k--){
        f = f->next;
    }
    while(f!=NULL){
        f=f->next;
        s = s->next;
    }

    cout<<s->data<<endl;

}

int main() {
    node *head = NULL;
    inserttail(head,2);
    inserttail(head,3);
    inserttail(head,1);
    inserttail(head,5);
    inserttail(head,7);
    inserttail(head,9);
    inserttail(head,11);
    print(head);
    cout<<endl;
    getmid(head);
    kthfromend(head,6);

}
