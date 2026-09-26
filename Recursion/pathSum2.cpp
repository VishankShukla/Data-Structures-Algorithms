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

    void solve(TreeNode* root, int targetSum,
               vector<vector<int>>& ans,
               vector<int>& path) {

        // Base case
        if (root == nullptr) {
            return;
        }

        // Current node ko path mein add karo
        path.push_back(root->val);

        // Check: kya ye leaf hai aur target complete ho gaya?
        if (root->left == nullptr &&
            root->right == nullptr &&
            targetSum == root->val) {

            ans.push_back(path);
        }

        // Left subtree
        solve(root->left,
              targetSum - root->val,
              ans,
              path);

        // Right subtree
        solve(root->right,
              targetSum - root->val,
              ans,
              path);

        // Backtracking
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(root, targetSum, ans, path);

        return ans;
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

    vector<vector<int>> ans = obj.pathSum(root, targetSum);

    // Print answer
    for (auto path : ans) {

        cout << "[";

        for (int i = 0; i < path.size(); i++) {
            cout << path[i];

            if (i != path.size() - 1) {
                cout << ",";
            }
        }

        cout << "]" << endl;
    }

    return 0;
}