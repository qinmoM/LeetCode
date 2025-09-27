/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int getMinimumDifference(TreeNode* root)
    {
        int m = 100001;
        preorder(root, m);
        return m;
    }

    void preorder(TreeNode* node, int& minTemp)
    {
        if (!node)
        {
            return;
        }
        if (node->right)
        {
            minTemp = std::min(minTemp, succeed(node->right) - node->val);
        }
        if (node->left)
        {
            minTemp = std::min(node->val - precursor(node->left), minTemp);
        }
        preorder(node->left, minTemp);
        preorder(node->right, minTemp);
    }

    int precursor(TreeNode* node)
    {
        if (!node->right)
        {
            return node->val;
        }
        return precursor(node->right);
    }

    int succeed(TreeNode* node)
    {
        if (!node->left)
        {
            return node->val;
        }
        return succeed(node->left);
    }

};
// @lc code=end

