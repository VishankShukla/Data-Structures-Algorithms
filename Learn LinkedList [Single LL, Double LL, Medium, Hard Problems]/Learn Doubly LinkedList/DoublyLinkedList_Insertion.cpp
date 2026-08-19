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

Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    
    return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL) return insertBeforeHead(head, val);
    
    Node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    Node* prev = temp->back;
    
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val){
    if(k==1) return insertBeforeHead(head,val);
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    if(temp == NULL) return head;
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    
    prev->next = newNode;
    temp->back = newNode;
    
    return head;
}

void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val,node,prev);
    prev->next = newNode;
    node->back = newNode;
}
int main(){
    vector<int> arr = {1,2,3,4};
    cout << "Converted Array" << endl;
    Node* head = ConvertArr2DLL(arr);
    print(head);
    cout << "Add before head" << endl;
    int val;
    cout << "enter the value: ";
    cin>>val;
    head = insertBeforeHead(head,val);
    print(head);
    cout << "Add before tail" << endl;
    cout << "enter the value: ";
    cin>>val;
    head = insertBeforeTail(head,val);
    print(head);
    cout << "Add before Kth Element" << endl;
    int k;
    cout << "Enter K: ";
    cin >> k;
    cout << "Enter the value: ";
    cin >> val;
    head = insertBeforeKthElement(head, k, val);
    print(head);
    cout << "Add before a Node" << endl;
    cout << "Enter the value: ";
    cin >> val;
    insertBeforeNode(head->next->next, val);
    print(head);
    return 0;
}


