#include <iostream>
using namespace std;
const int MAX=10;
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
        }
        Node(int data, Node *next, Node *prev){
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
};
class Deque{
    private:
        Node* front=NULL;
        Node* rear=NULL;
    public:
        Deque(){
        }
        void enqueueRear(int x){
            Node* temp = new Node(x);
            if(front==NULL){
                front = temp;
                rear = temp;
                rear->next = NULL;
                rear->prev = NULL;
            }
            else{
                temp->prev = rear;
                temp->next = NULL;
                rear->next = temp;
                rear = temp;
            }
        }
        int dequeueFront(){
            if(front==NULL){
                return -1;
            }
            int x = front->data;
            Node* temp = front;
            front = front->next;
            front->prev = NULL;
            free(temp);
            return x;
        }
        void enqueueFront(int x){
            Node* temp = new Node(x);
            if(front==NULL){
                front = temp;
                rear = temp;
                rear->next = NULL;
            }
            else{
                temp->next = front;
                temp->prev = NULL;
                front->prev = temp;
                front = temp;
            }
        }
        int dequeueRear(){
            if(front==NULL){
                return -1;
            }
            int x = front->data;
            Node* temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            free(temp);
            return x;
        }
        
        int size(){
            if(front==NULL){
                return 0;
            }
            Node* temp = front;
            int count = 1;
            while(temp->next!=NULL){
                temp = temp->next;
                count++;
            }
            return count;
        }
        void display(){
            if(front==NULL){
                cout<<"Queue is Empty";
            }
            else{
                Node* temp = front;
                while(temp!=NULL){
                    cout<<temp->data<<"->";
                    temp=temp->next;
                    if(temp==NULL){
                        cout<<endl;
                        break;
                    }
                }
            }
        }
};

int main(){
    Deque q;
    q.enqueueRear(1);
    q.display( );
    q.enqueueRear(2);
    q.display( );
    q.enqueueRear(3);
    q.display( );
    q.enqueueRear(4);
    q.display( );
    q.enqueueRear(5);
    q.display( );
    q.enqueueFront(6);
    q.display( );
    q.enqueueFront(7);
    q.display( );
    q.enqueueFront(8);
    q.display( );
    q.enqueueFront(9);
    q.display( );
    q.enqueueFront(10);
    q.display( );
    q.dequeueFront();
    q.display( );
    q.dequeueFront();
    q.display( );
    q.dequeueFront();
    q.display( );
    q.enqueueRear(7);
    q.display( );
    q.enqueueFront(8);
    q.display( );
    q.enqueueFront(9);
    q.display();
    q.dequeueRear();
    q.display( );
    q.dequeueRear();
    q.display( );
    q.dequeueRear();
    q.display( );
    q.dequeueFront();
    q.display( );
    q.dequeueFront();
    q.display( );
    q.dequeueFront();
    q.display( );
    q.dequeueFront();
    q.display( );
}