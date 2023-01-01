#include <iostream>
using namespace std;
const int MAX=10;
class Node{
    public:
        int data;
        int priority;
        Node *next;
        Node(int data){
            this->data = data;
        }
        Node(int data, int priority){
            this->data = data;
            this->next = NULL;
            this->priority = priority;
        }
};
class PriorityQueue{
    private:
        Node* front=NULL;
        Node* rear=NULL;
    public:
        PriorityQueue(){
        }
        void enqueue(int x, int priority){
            Node* newNode = new Node(x, priority);
            Node* temp = front;
            if(front==NULL){
                front = newNode;
                rear = newNode;
                return;
            } else if (front->priority>priority){
                newNode->next = front;
                front = newNode;
                return;
            } else {
                while(temp->next!=NULL && temp->next->priority<priority){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
        int dequeue(){
            if(front==NULL){
                return -1;
            } else {
                int x = front->data;
                Node* temp = front;
                front = temp->next;
                free(temp);
                return x;
            }
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
                    cout<<temp->data<<","<<temp->priority<<"->";
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
    PriorityQueue pq;
    bool run = true;
    int choice, ip,priority;
    cout << "Priority Queue"<<endl;
    while(run){
        cout << "Operations:"<<endl;
        cout <<"\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Size\n\t5.Exit\nEnter Your Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter Element to Enqueue: ";
                cin >> ip;
                cout << "Enter it's Priority: ";
                cin >> priority;
                pq.enqueue(ip, priority);
                break;
            case 2:
                ip = pq.dequeue();
                cout << "Element Dequeued is : " << ip << endl;
                break;
            case 3:
                pq.display();
                break;
            case 4:
                ip = pq.size();
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