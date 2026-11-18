
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p == nullptr && q == nullptr) {
            return true;
        }

        if(p == nullptr || q == nullptr) {
            return false;
        }

        if(p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {

    // First Tree
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Second Tree
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if(obj.isSameTree(p, q)) {
        cout << "Both trees are same";
    }
    else {
        cout << "Both trees are not same";
    }

    return 0;
}
