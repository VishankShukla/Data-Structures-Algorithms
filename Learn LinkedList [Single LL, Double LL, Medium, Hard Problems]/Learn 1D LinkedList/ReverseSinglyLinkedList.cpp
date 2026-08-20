#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* ConvertArr2LL(vector<int> &arr) {
    int n = arr.size();

    if (n == 0)
        return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i], nullptr);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseLinkedlist(Node* head) {
    if (head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;
    temp->next = nullptr;

    Node* prev = temp;

    while (head != nullptr) {
        temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
    }

    return prev;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};

    cout << "Converted Array To Linkedlist" << endl;

    Node* head = ConvertArr2LL(arr);
    print(head);

    cout << "Reversed Linkedlist" << endl;

    head = reverseLinkedlist(head);
    print(head);

    return 0;
}