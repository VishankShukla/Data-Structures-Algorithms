#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main() {
    vector<int> arr = {3,4,5,2,3};
    Node* y = new Node(arr[0]);
    cout << "Print memory location of node:" << y << endl;
    cout << "Print data stored in node:" << y->data;
    return 0;
}