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
    bool run = true;
    int choice, ip;
    cout << "Queue Implementation using Array"<<endl;
    while(run){
        cout <<"Operations: \n\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Size\n\t5.Exit\nEnter Your Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter Element to Enqueue: ";
                cin >> ip;
                q.enqueue(ip);
                break;
            case 2:
                ip = q.dequeue();
                cout << "Element Dequeued is : " << ip << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                ip = q.size();
                cout << "Size of Queue is : " << ip << endl;
                break;
            case 5:
                run = false;
                break;
            default:
                cout << "Invalid Operation" << endl;
                break;
        }
    }
}