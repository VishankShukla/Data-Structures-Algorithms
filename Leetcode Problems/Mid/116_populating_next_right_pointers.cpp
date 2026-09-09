#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL || root->left == NULL) return root;

        Node* leftnode = root;

        while (leftnode->left != NULL) {
            Node* curr = leftnode;

            while (curr != NULL) {
                curr->left->next = curr->right;

                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            leftnode = leftnode->left;
        }

        return root;
    }
};

// Helper function to print the tree level-wise using next pointers.
void printLevels(Node* root) {
    Node* levelStart = root;

    while (levelStart != NULL) {
        Node* curr = levelStart;

        while (curr != NULL) {
            cout << curr->val;
            if (curr->next != NULL)
                cout << " -> ";
            else
                cout << " -> NULL";

            curr = curr->next;
        }

        cout << '\n';
        levelStart = levelStart->left;
    }
}

int main() {
    // Perfect binary tree:
    //
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    sol.connect(root);

    printLevels(root);

    return 0;
}
