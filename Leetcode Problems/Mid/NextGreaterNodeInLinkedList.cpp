#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = 0;
            else
                ans[i] = arr[st.top()];

            st.push(i);
        }

        return ans;
    }
};

int main() {
    // Linked List: 2 -> 7 -> 4 -> 3 -> 5
    ListNode* head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    vector<int> ans = obj.nextLargerNodes(head);

    cout << "Next Greater Nodes: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}