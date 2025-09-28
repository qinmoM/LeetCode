/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root)
    {
        int path = -1;
        num(root, path);
        return path;
    }

    int num(TreeNode* node, int& maxNum)
    {
        if (!node)
        {
            return 0;
        }

        int right = num(node->right, maxNum);
        int left = num(node->left, maxNum);
        maxNum = std::max(left + right, maxNum);
        return 1 + std::max(left, right);
    }

};
// @lc code=end

