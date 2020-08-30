#include <iostream>
using namespace std;

class queue{
    int * arr;
    int front,rear;
    int currsize=0;
    int maxsize=5;
    

    public:
    int currentsize(){
        return currsize;
    }
    bool isfull(){
        return currsize==maxsize;
    }
    bool isempty(){
        return currsize==0;
    }
    queue(){
        arr = new int[maxsize];
        front=0;
        rear=4;
    }
    void enq(int d){
        if(!isfull()){
        rear = (rear+1)%maxsize;
        arr[rear]=d;
        currsize++;
        }
        else{
            cout<<"full"<<endl;
        }

    }

    void deq(){
        if(!isempty()){
        front=(front+1)%maxsize;
        currsize--;
        }
        else{
            cout<<"empty"<<endl;
        }
    }
    int frontel(){
        return arr[front];
    }

    void show(){
        int i=front;
        while(i!=rear){
            cout<<arr[i]<<" ";
            i=(i+1)%maxsize;
        }
    }
};
int main() {
    queue q;
    q.enq(2);
    q.enq(3);
    q.enq(7);
    q.deq();
    q.enq(9);
    q.enq(11);
    q.deq();
    cout<<q.currentsize()<<endl;
    q.enq(10);
    cout<<q.currentsize()<<endl;]
    
    
    while(!q.isempty()){
        cout<<q.frontel()<<" ";
        q.deq();
    }


    

}
