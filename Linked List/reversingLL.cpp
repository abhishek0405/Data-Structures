#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int d){
        data = d;
        next = NULL;
    }
};

void inserthead(node *&head,int d){
    node *n = new node(d);
    n->next = head;
    head = n;



}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}

void reverseiter(node *&head){
    node*t = head;
    node *p=NULL;
    while(t!=NULL){
        node*n = t->next;
        t->next = p;
        p=t;
        t=n;
    }
    head = p;
}

node* reverserecursion(node *head){
 
if(head->next==NULL){
    return head;
}

node* subhead = reverserecursion(head->next);
node *t = head;
t->next->next = t;
t->next = NULL;
return subhead;

    
    
}

int main() {
    node *head = NULL;
    inserthead(head,1);
    inserthead(head,2);
    inserthead(head,7);
    inserthead(head,10);
    inserthead(head,3);
    inserthead(head,3);
    print(head);
    cout<<endl;
    reverseiter(head);
    cout<<endl;
    print(head);
    cout<<endl;
    head = reverserecursion(head);
    print(head);
    
    
    
}
