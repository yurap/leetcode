// https://leetcode.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        if ((left == nullptr) != (right == nullptr))
            return false;
        if (!left)
            return true;
        if (left->val != right->val)
            return false;
        return checkSymmetric(left->left, right->right)
            && checkSymmetric(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return checkSymmetric(root->left, root->right);
    }
};
