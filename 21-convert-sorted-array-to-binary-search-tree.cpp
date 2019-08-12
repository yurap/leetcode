// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* buildTree(vector<int>& nums, int b, int e) {
        if (e <= b) return nullptr;
        int mid = (e + b) / 2;
        
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = buildTree(nums, b, mid);
        cur->right = buildTree(nums, mid + 1, e);
        return cur;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size());
    }
};
