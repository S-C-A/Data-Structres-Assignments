#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class MyQueue {
private:
    Node* front;
    Node* rear;
    int cnt;

public:
    MyQueue() {
        front = nullptr;
        rear = nullptr;
        cnt = 0;
    }

    bool isEmpty() {
        return cnt == 0;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cnt++;
        cout << x << " kuyruga eklendi." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Hata: Kuyruk bos, eleman cikarilamaz!");
        }

        Node* temp = front; 
        int value = temp->data;
        
        front = front->next; 

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;             
        cnt--;                 
        return value;
    }

    int peek() {
        if (isEmpty()) throw runtime_error("Kuyruk bos!");
        return front->data;
    }

    int size() {
        return cnt;
    }

    ~MyQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    MyQueue q;

    q.enqueue(10);
    q.enqueue(20); 
    q.enqueue(30); 

    cout << "Kuyruk boyutu: " << q.size() << endl;
    cout << "En bastaki eleman: " << q.peek() << endl;

    cout << "\n--- Eleman Cikarma (FIFO) ---" << endl;
    cout << "Cikarilan: " << q.dequeue() << endl; 
    cout << "Cikarilan: " << q.dequeue() << endl;
    
    q.enqueue(40);
    cout << "Yeni eklenen sonrası en bastaki: " << q.peek() << endl;

    return 0;
}