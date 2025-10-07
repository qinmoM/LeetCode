/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
#include <bits/stdc++.h>

class Solution
{
public:
    int minDiffInBST(TreeNode* root)
    {
        int result = INT_MAX, last = -1;
        inorder(root, last, result);
        return result;
    }

    void inorder(TreeNode* node, int& prev, int& minimum)
    {
        if (!node)
        {
            return;
        }

        inorder(node->left, prev, minimum);
        if (-1 != prev)
        {
            minimum = std::min(node->val - prev, minimum);
        }
        prev = node->val;
        inorder(node->right, prev, minimum);
    }

};
// @lc code=end

