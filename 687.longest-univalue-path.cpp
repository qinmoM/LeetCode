/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int longestUnivaluePath(TreeNode* root)
    {
        if (!root) return 0;

        std::unordered_map<int, int> hash;
        dfs(root, hash);

        return std::max_element(hash.begin(), hash.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b)
            {
                return a.second < b.second;
            }
        )->second;
    }

    int findPath(TreeNode* node, int val)
    {
        if (!node || node->val != val) return 0;

        return std::max(findPath(node->left, val), findPath(node->right, val)) + 1;
    }

    void dfs(TreeNode* node, std::unordered_map<int, int>& hash)
    {
        if (!node) return;

        hash[node->val] = std::max(hash[node->val], findPath(node->left, node->val) + findPath(node->right, node->val));

        dfs(node->left, hash);
        dfs(node->right, hash);
    }
};
// @lc code=end

