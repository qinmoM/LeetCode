/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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

#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        std::unordered_map<int, std::pair<int, int>> hash;

        dfs(root, 0, 1, hash);

        std::unordered_map<int, std::pair<int, int>>::iterator it = std::max_element(hash.begin(), hash.end(),
            [](const std::pair<int, std::pair<int, int>>& a, const std::pair<int, std::pair<int, int>>& b)
            {
                return a.second.second - a.second.first < b.second.second - b.second.first;
            }
        );

        return it->second.second - it->second.first + 1;
    }

    void dfs(TreeNode* node, int level, int target, std::unordered_map<int, std::pair<int, int>>& hash)
    {
        if (!node) return;

        if (hash.find(level) == hash.end())
        {
            hash[level].first = INT_MAX;
            hash[level].second = INT_MIN;
        }
        hash[level].first = std::min(target, hash[level].first);
        hash[level].second = std::max(target, hash[level].second);

        dfs(node->left, level + 1, target * 2 - 1, hash);
        dfs(node->right, level + 1, target * 2, hash);
    }
};
// @lc code=end

