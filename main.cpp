#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {

    }

    void InsertAfter(int data, int afterData) {
        Node* temp = head;

        while (temp != nullptr && temp->data != afterData) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << afterData << " not found"<<endl;
            return;
        }

        Node* newNode = new Node(data);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void InsertBefore(int data, int beforeData) {
        if (head == nullptr)
            return;

        if (head->data == beforeData) {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr && temp->next->data != beforeData) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << beforeData << " not found!\n";
            return;
        }

        Node* newNode = new Node(data);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    int GetCount() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    int GetDataByIndex(int index) {
        if (index < 0)
            return -1;

        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            if (count == index)
                return temp->data;

            count++;
            temp = temp->next;
        }

        return -1;
    }

    void Append(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

};

int main() {
    LinkedList list;

    list.Append(10);
    list.Append(20);
    list.Append(30);

    list.InsertAfter(25, 20);

    list.InsertBefore(15, 20);

    list.InsertBefore(5, 10);
    list.InsertAfter(40, 30);

    cout <<"number of nodes "<<list.GetCount() << endl;
    cout <<list.GetDataByIndex(0) << endl;
    cout <<list.GetDataByIndex(3) << endl;
    cout <<list.GetDataByIndex(6) << endl;
    cout <<list.GetDataByIndex(-1) << endl;

    list.InsertAfter(100, 999);
    list.InsertBefore(100, 999);

    return 0;
}

