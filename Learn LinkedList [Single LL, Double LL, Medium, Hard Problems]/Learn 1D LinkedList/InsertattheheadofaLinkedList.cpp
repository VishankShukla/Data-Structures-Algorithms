// Problem Statement: Given a linked list and an integer value val,
//  insert a new node with that value at the beginning (before the head) 
// of the list and return the updated linked list.
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
}
