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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    
    head->back=nullptr;
    prev->next=nullptr;
    
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->back->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
}

Node* deleteKthNode(Node* head, int k){
    if(head == NULL || k <= 0) return head;
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(cnt == k) break;
        temp=temp->next;
    }
    
    if(temp == NULL) return head;
    
    Node* prev = temp->back;
    Node* front = temp->next;
    
    if(prev == NULL && front == NULL){
        return NULL;
    }else if(prev == NULL){
        return deleteHead(head);
    }else if(front == NULL){
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    
    temp->next = nullptr;
    temp->back = nullptr;
    
    delete temp;
    return head;
}

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    
    prev->next = front;
    front->back = prev;
    
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    cout << "Converted Array" << endl;
    Node* head = ConvertArr2DLL(arr);
    print(head);
    cout << "After Deleteing Head" << endl;
    head = deleteHead(head);
    print(head);
    cout << "After Deleteing Tail" << endl;
    head = deleteTail(head);
    print(head);
    cout << "Deleteing Kth Element" << endl;
    int k;
    cout << "Enter the Kth element: ";
    cin >> k;
    head = deleteKthNode(head,k);
    print(head);
    cout << "Deleteing the 2nd Element" << endl;
    deleteNode(head->next);
    print(head);
    return 0;
}


