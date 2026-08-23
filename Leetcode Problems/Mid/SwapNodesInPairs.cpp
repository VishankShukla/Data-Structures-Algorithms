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

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* temp = NULL;

    ListNode* newHead = head->next;

    while (curr != NULL && curr->next != NULL) {
        temp = curr->next;

        // Swap pair
        curr->next = temp->next;
        temp->next = curr;

        // Previous pair ko current swapped pair se connect karo
        if (prev != NULL)
            prev->next = temp;

        // Move pointers
        prev = curr;
        curr = curr->next;
    }

    return newHead;
}

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
    // Input: [1,2,3,4,5]

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before swapping: ";
    printList(head);

    head = swapPairs(head);

    cout << "After swapping:  ";
    printList(head);

    return 0;
}