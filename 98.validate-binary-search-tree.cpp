/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
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
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        bool start = false;
        int last = 0;
        return inorder(root, last, start);
    }

    bool inorder(TreeNode* node, int& last, bool& start)
    {
        if (!node) return true;

        if (!inorder(node->left, last, start)) return false;
        if (!start) start = true;
        else if (last >= node->val) return false;
        last = node->val;

        if (!inorder(node->right, last, start)) return false;

        return true;
    }
};
// @lc code=end

