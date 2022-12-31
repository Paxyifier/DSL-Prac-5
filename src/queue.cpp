#include <iostream>
using namespace std;
const int MAX=10;
class Queue{
    private:
        int front;
        int rear;
        int capacity;
        int array[MAX];
    public:
        Queue(){
            front=-1;
            rear=-1;
            capacity=MAX;
        }
        void enqueue(int x){
            if(rear==capacity-1){
                cout<<"Queue Overflow"<<endl;
                return;
            }
            if (rear==front && rear == -1){
                front=0;
                rear=0;
                array[rear]=x;
            }
            else{
                rear++;
                array[rear]=x;
            }
        }
        int dequeue(){
            if(front==-1){
                cout<<"Queue Underflow"<<endl;
                return -1;
            }
            int x=array[front];
            front++;
            // if(front==capacity-1){
            //     front=0;
            // }
            return x;
        }
        int size(){
            return rear-front+1;
        }
        void display(){
            if(front==-1){
                cout<<"Queue is Empty"<<endl;
            }
            else{
                cout<<"Queue is : ";
                for(int i=front;i<=rear;i++){
                    cout<<array[i]<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.display( );
    q.enqueue(2);
    q.display( );
    q.enqueue(3);
    q.display( );
    q.enqueue(4);
    q.display( );
    q.enqueue(5);
    q.display( );
    q.enqueue(6);
    q.display( );
    q.enqueue(7);
    q.display( );
    q.enqueue(8);
    q.display( );
    q.enqueue(9);
    q.display( );
    q.enqueue(10);
    q.display( );
    q.dequeue();
    q.display( );
    q.dequeue();
    q.display( );
    q.dequeue();
    q.display( );
    q.enqueue(7);
    q.display( );
    q.enqueue(8);
    q.display( );
    q.enqueue(9);
    q.display();
    q.dequeue();
    q.display( );
    q.dequeue();
    q.display( );
    q.dequeue();
    q.display( );
    q.dequeue();
    q.display( );
    q.dequeue();
    q.display( );
    q.dequeue();
    q.display( );
    q.dequeue();
    q.display( );
}