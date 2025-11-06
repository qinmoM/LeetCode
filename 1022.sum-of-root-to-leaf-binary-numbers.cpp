/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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

class Solution
{
public:
    int sumRootToLeaf(TreeNode* root)
    {
        return recursion(root, 0);
    }

    int recursion(TreeNode* node, int bit)
    {
        if (!node)
        {
            return 0;
        }
        bit = (bit << 1) + node->val;
        if (!node->left && !node->right)
        {
            return bit;
        }
        return recursion(node->left, bit) + recursion(node->right, bit);
        // int temp = 0;
        // if (node->left)
        // {
        //     temp += recursion(node->left);
        // }
        // if (node->right)
        // {
        //     temp += recursion(node->right);
        // }
        // return temp;
    }

};
// @lc code=end

