/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }

        bool isBalanced = true;
        height(root, isBalanced);

        return isBalanced;
    }

    int height(TreeNode* root, bool& isBalanced)
    {
        if (!root)
        {
            return 0;
        }

        int left = height(root->left, isBalanced);
        int right = height(root->right, isBalanced);

        if (abs(left - right) > 1)
        {
            isBalanced = false;
            return 0;
        }

        return 1 + max(left, right);
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int abs(int a)
    {
        return a > 0 ? a : -a;
    }

};
// @lc code=end

