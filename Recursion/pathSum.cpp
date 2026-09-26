#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    bool solve(TreeNode* root, int targetSum) {

        // Base case
        if (root == nullptr) {
            return false;
        }

        // Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        // Left OR Right
        return solve(root->left, targetSum - root->val) ||
               solve(root->right, targetSum - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};

int main() {

    /*
             5
            / \
           4   8
          /   / \
         11  13  4
        /  \
       7    2
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    int targetSum = 22;

    Solution obj;

    bool answer = obj.hasPathSum(root, targetSum);

    if (answer) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}