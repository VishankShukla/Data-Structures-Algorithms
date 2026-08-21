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

Node* ConvertArr2DLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i], nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

Node* sortAccTo0s1s2s(Node* head) {
    Node* temp = head;

    Node* l0 = new Node(-1);
    Node* l1 = new Node(-1);
    Node* l2 = new Node(-1);

    Node* l0Head = l0;
    Node* l1Head = l1;
    Node* l2Head = l2;

    while (temp != NULL) {
        if (temp->data == 0) {
            l0->next = temp;
            l0 = l0->next;
        }
        else if (temp->data == 1) {
            l1->next = temp;
            l1 = l1->next;
        }
        else {
            l2->next = temp;
            l2 = l2->next;
        }

        temp = temp->next;
    }

    l0->next = l1Head->next;
    l1->next = l2Head->next;
    l2->next = NULL;

    return l0Head->next;
}

int main(){
    vector<int> arr = {0,1,0,2,1,0,2};
    cout << "Converted Array To Linkedlist" << endl;
    Node* head = ConvertArr2DLL(arr);
    print(head);
    cout << "Sort Acc. to 0's 1's 2's" << endl;
    head = sortAccTo0s1s2s(head);
    print(head);
    return 0;
}
