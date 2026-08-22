#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val) {
            curr->next = curr->next->next;
        } 
        else {
            curr = curr->next;
        }
    }

    return head;
}

// Linked List print karne ke liye
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {
    // Input: [1,1,2,3,3]

    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Before removing duplicates: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "After removing duplicates:  ";
    printList(head);

    return 0;
}