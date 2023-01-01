#include <iostream>
using namespace std;
const int MAX=10;
class Node{
    public:
        int data;
        Node *next;
        bool isFront = false;
        Node(int data){
            this->data = data;
        }
        Node(int data, Node *next){
            this->data = data;
            this->next = next;
        }
};
class CircularQueue{
    private:
        Node* front=NULL;
        Node* rear=NULL;
    public:
        CircularQueue(){
        }
        void enqueue(int x){
            Node* temp = new Node(x);
            if(front==NULL){
                front = temp;
                rear = temp;
                front->isFront = true;
                rear->next = rear;
            }
            else{
                rear->next = temp;
                temp->next = front;
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
            front->isFront = true;
            free(temp);
            return x;
        }
        int size(){
            if(front==NULL){
                return 0;
            }
            Node* temp = front;
            int count = 0;
            do{
                count++;
                temp=temp->next;
            }while(!temp->isFront);
            return count;
        }
        void display(){
            if(front==NULL){
                cout<<"Queue is Empty"<<endl;
                return;
            }
            Node* temp = front;
            do{
                cout<<temp->data<<"->";
                temp=temp->next;
            }while(!temp->isFront);
            cout << endl;
        }
};

int main(){
    CircularQueue q;
    bool run = true;
    int choice, ip;
    cout << "Circular Queue Implementation using Linked List"<<endl;
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