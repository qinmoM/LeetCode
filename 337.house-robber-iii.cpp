/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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

#include <iostream>

class Solution
{
public:
    int rob(TreeNode* root)
    {
        auto [left, right] = dfs(root);
        return std::max(left, right);
    }

    std::pair<int, int> dfs(TreeNode* node)
    {
        if (!node) return { 0, 0 };

        std::pair<int, int> left = dfs(node->left);
        std::pair<int, int> right = dfs(node->right);

        return { left.second + right.second + node->val,
            std::max(
                std::max(left.first + right.first, left.second + right.second),
                std::max(left.second + right.first, left.first + right.second)
            ) };
    }
};
// @lc code=end

