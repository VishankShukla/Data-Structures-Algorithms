#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;
        }

        if (slow != fast) return NULL;

        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main() {
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    Solution obj;

    ListNode* cycleStart = obj.detectCycle(node1);

    if (cycleStart != nullptr)
        cout << "Cycle starts at node: " << cycleStart->val << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
