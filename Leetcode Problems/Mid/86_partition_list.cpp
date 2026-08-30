#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* partition(ListNode* head, int x) {

    ListNode lessDummy(0);
    ListNode greaterDummy(0);

    ListNode* lesshead = &lessDummy;
    ListNode* greaterhead = &greaterDummy;

    ListNode* temp = head;

    while (temp != nullptr) {

        if (temp->val < x) {
            lesshead->next = temp;
            lesshead = lesshead->next;
        }
        else {
            greaterhead->next = temp;
            greaterhead = greaterhead->next;
        }

        temp = temp->next;
    }

    // Connect both partitions
    lesshead->next = greaterDummy.next;

    // Terminate the list
    greaterhead->next = nullptr;

    return lessDummy.next;
}

ListNode* createList(vector<int> arr) {

    if (arr.empty())
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

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

    // Example 1
    vector<int> arr = {1, 4, 3, 2, 5, 2};
    int x = 3;

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    ListNode* result = partition(head, x);

    cout << "After Partition: ";
    printList(result);

    return 0;
}