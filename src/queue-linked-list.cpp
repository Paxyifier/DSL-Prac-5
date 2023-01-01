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
    bool run = true;
    int choice, ip;
    cout << "Queue Implementation using Linked List"<<endl;
    while(run){
        cout << "Operations:"<<endl;
        cout <<"\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Size\n\t5.Exit\nEnter Your Choice: ";
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