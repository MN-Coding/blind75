/*
Problem: 98. Validate Binary Search Tree
Time Complexity: O(n)
Space Complexity: O(1)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int valid(TreeNode *root, int *min, int *max) {
        if (!root) return true;
        if (min && root->val <= *min) return false;
        if (max && root->val >= *max) return false;
        return valid(root->left, min, &(root->val)) && valid(root->right, &(root->val), max);
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, NULL, NULL);
    }
};
