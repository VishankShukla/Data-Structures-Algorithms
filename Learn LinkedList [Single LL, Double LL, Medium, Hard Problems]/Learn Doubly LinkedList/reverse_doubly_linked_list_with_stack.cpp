#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;
    
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* ConvertArr2DLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<n; i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp; 
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

void reverseLinkedlist(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
}

int main(){
    vector<int> arr = {1,2,3,4};
    cout << "Converted Array To Linkedlist" << endl;
    Node* head = ConvertArr2DLL(arr);
    print(head);
    cout << "Reversed Linkedlist" << endl;
    reverseLinkedlist(head);
    print(head);
    return 0;
}

//Time Comp: O(2n)
//Space Comp: O(n)


