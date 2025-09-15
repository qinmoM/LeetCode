/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }

        return depth(root);
    }

    int depth(TreeNode* root)
    {
        if (nullptr == root->left && nullptr == root->right)
        {
            return 1;
        }

        if (root->left && root->right)
        {
            return min(depth(root->left), depth(root->right)) + 1;
        }

        if (root->left)
        {
            return depth(root->left) + 1;
        }
        else
        {
            return depth(root->right) + 1;
        }
    }

    int min(int a, int b)
    {
        return a < b ? a : b;
    }

};
// @lc code=end

