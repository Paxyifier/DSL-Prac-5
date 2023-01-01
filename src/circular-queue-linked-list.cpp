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
                cout<<temp->data<<temp->isFront<<"->";
                temp=temp->next;
            }while(!temp->isFront);
            cout << endl;
        }
};

int main(){
    CircularQueue q;
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(1);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(2);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(3);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(4);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(5);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(6);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(7);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(8);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(9);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(10);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(7);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(8);
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.enqueue(9);
    q.display();
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
    q.dequeue();
    q.display( );
    cout<<"Count: "<<q.size()<<endl;
}