/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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

#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> largestValues(TreeNode* root)
    {
        std::vector<int> vec;
        dfs(root, 0, vec);
        return vec;
    }

    auto dfs(TreeNode* node, int level, std::vector<int>& vec) -> void
    {
        if (!node) return;

        if (level == vec.size())
            vec.push_back(node->val);
        else if (level < vec.size())
            vec[level] = std::max(vec[level], node->val);

        dfs(node->left, level + 1, vec);
        dfs(node->right, level + 1, vec);
    }
};
// @lc code=end

