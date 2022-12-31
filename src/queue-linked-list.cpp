#include <iostream>
using namespace std;
const int MAX=10;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
        }
        Node(int data, Node *next){
            this->data = data;
            this->next = next;
        }
};
class Queue{
    private:
        Node* front=NULL;
        Node* rear=NULL;
    public:
        Queue(){
        }
        void enqueue(int x){
            Node* temp = new Node(x);
            if(front==NULL){
                front = temp;
                rear = temp;
                rear->next = NULL;
            }
            else{
                rear->next = temp;
                rear = temp;
            }
        }
        int dequeue(){
            if(front==NULL){
                return -1;
            }
            int x = front->data;
            Node* temp = front;
            front = front->next;
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