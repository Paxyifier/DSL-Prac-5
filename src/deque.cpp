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
            int x = rear->data;
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
    bool run = true;
    int choice, ip;
    cout << "Double-ended Queue Implementation using Linked List"<<endl;
    while(run){
        cout << "Operations:"<<endl;
        cout <<"\t1.EnqueueFront\n\t2.DequeueFront\n\t3.EnqueueRear\n\t4.DequeueRear\n\t5.Display\n\t6.Size\n\t7.Exit\nEnter Your Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter Element to Enqueue: ";
                cin >> ip;
                q.enqueueFront(ip);
                break;
            case 2:
                ip = q.dequeueFront();
                cout << "Element Dequeued is : " << ip << endl;
                break;
            case 3:
                cout << "Enter Element to Enqueue: ";
                cin >> ip;
                q.enqueueRear(ip);
                break;
            case 4:
                ip = q.dequeueRear();
                cout << "Element Dequeued is : " << ip << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                ip = q.size();
                cout << "Size of Queue is : " << ip << endl;
                break;
            case 7:
                run = false;
                break;
            default:
                cout << "Invalid Operation" << endl;
                break;
        }
    }
}