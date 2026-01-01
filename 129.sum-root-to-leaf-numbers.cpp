/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root)
    {
        if (!root) return 0;
        int all = 0;
        sum(root, all, 0);
        return all;
    }

    void sum(TreeNode* node, int& all, int path)
    {
        int temp = path * 10 + node->val;
        if (!node->left && !node->right)
        {
            all += temp;
            return;
        }

        if (node->left) sum(node->left, all, temp);
        if (node->right) sum(node->right, all, temp);
    }
};
// @lc code=end

