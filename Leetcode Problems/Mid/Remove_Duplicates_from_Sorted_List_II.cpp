#include <bits/stdc++.h>
using namespace std;

// Remove Duplicates from Sorted List II
// LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* temp = head;

        while (temp != nullptr) {

            // Duplicate mila
            if (temp->next != nullptr &&
                temp->val == temp->next->val) {

                int duplicateValue = temp->val;

                // Saare duplicates skip karo
                while (temp != nullptr &&
                       temp->val == duplicateValue) {
                    temp = temp->next;
                }

                prev->next = temp;
            }

            // Unique node hai
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        return dummy.next;
    }
};

// Helper function
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // Example:
    // 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    // Output:
    // 1 -> 2 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}