#include <iostream>
using namespace std;

struct Node{

    int data;
    Node* next;
    Node* prev;
};

int main(){

    Node* head = new Node;

    head->data = 10;
    head->next = nullptr;
    head->prev = nullptr;

    Node* current = head;
    int check = 0;
    while (check != 9)
    {
        cout << "The current list data is: " << current->data << endl;
        
        cout << "Press 1 to go forward in the linked list.\n"
             << "Press 2 to go back in the linked list.\n"
             << "Press 9 to exit.\n";
        cin >> check;

        switch (check)
        {
        case 1:
            if (current->next == nullptr)
            {
                cout << "There is no next element so creating the next element!\nPlease enter list data: ";
                current->next = new Node;
                cin >> current->next->data;
                current->next->next = nullptr;
                current->next->prev = current;
                current = current->next;
            }
            else
            {
                current = current->next;
            }
            break;
        
        case 2:
            if (current->prev == nullptr)
            {
                cout << "There is no previous element so creating the previous element!\nPlease enter list data: ";
                current->prev = new Node;
                cin >> current->prev->data;
                current->prev->prev = nullptr;
                current->prev->next = current;
                current = current->prev;
            }
            else
            {
                current = current->prev;
            }
            break;
        
        default:
            break;
        }        
    }

    cout << "Exiting and cleaning up memory..." << endl;

    current = head;
    while (current->prev != nullptr)
    {
        current = current->prev;
    }
    while (current != nullptr)
    {
        Node* temp = current;      
        current = current->next;   
        delete temp;              
    }
}