#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class linklist {
    Node* head;
    Node* tail;

public:
    linklist() {
        head = NULL;
        tail = NULL;
    }

    void addnode(int n) {
        Node* temp = new Node;
        temp->data = n;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void AddNodeFront(int n) {
        Node* temp = new Node;
        temp->data = n;
        temp->next = head;

        head = temp;

        if (tail == NULL) {
            tail = head;
        }
    }

    void AddNodeMiddle(int n, int pos) {
        if (head == NULL || pos <= 1) {
            AddNodeFront(n);
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        for (int i = 1; i < pos - 1 && curr != NULL; i++) {
            prev = curr;
            curr = curr->next;
        }

        Node* temp = new Node;
        temp->data = n;
        temp->next = curr;

        prev->next = temp;

        if (curr == NULL) {
            tail = temp;
        }
    }

    void DeleteFront() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
    }

    void DeleteBack() {
        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* prev = head;

        while (prev->next->next != NULL) {
            prev = prev->next;
        }

        delete prev->next;
        prev->next = NULL;
        tail = prev;
    }

    void Display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    ~linklist() {
        Node* temp;

        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }

        tail = NULL;
    }
};

int main() {
    linklist list;

    list.addnode(10);
    list.addnode(20);
    list.addnode(30);

    cout << "Original List:" << endl;
    list.Display();

    list.AddNodeFront(5);

    cout << "\nAfter adding 5 at front:" << endl;
    list.Display();

    list.AddNodeMiddle(15, 3);

    cout << "\nAfter adding 15 at position 3:" << endl;
    list.Display();

    list.DeleteFront();

    cout << "\nAfter deleting front:" << endl;
    list.Display();

    list.DeleteBack();

    cout << "\nAfter deleting back:" << endl;
    list.Display();

    return 0;
}