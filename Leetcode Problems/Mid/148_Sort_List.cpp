#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if (list1)
            curr->next = list1;
        else
            curr->next = list2;

        return dummy.next;
    }

    // Find the last node of the left half
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge Sort
    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        ListNode* middle = findMiddle(head);

        // Split the list
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        middle->next = nullptr;

        // Sort both halves
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        // Merge sorted halves
        return mergeTwoLists(leftHead, rightHead);
    }
};


// Print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << '\n';
}


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


// Free linked list memory
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}


int main() {

    // Test Case
    vector<int> arr = {8, 2, 5, 3};

    // Create linked list
    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    // Sort
    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List:   ";
    printList(head);

    // Free memory
    deleteList(head);

    return 0;
}

