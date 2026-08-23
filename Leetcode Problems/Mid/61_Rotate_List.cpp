#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* tail = head;
        int n = 1;

        // Find length and tail
        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        k = k % n;

        if (k == 0)
            return head;

        // Make the list circular
        tail->next = head;

        // Find new tail
        int step = n - k;
        ListNode* newTail = head;

        for (int i = 1; i < step; i++) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};

// Create linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty())
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

// Free memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // LeetCode example:
    // Input: head = [1,2,3,4,5], k = 2
    // Output: [4,5,1,2,3]

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "After Rotation: ";
    printList(head);

    deleteList(head);

    return 0;
}