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

#include <queue>
#include <algorithm>

class Solution
{
public:
    using ull = unsigned long long;
    int widthOfBinaryTree(TreeNode* root)
    {
        std::queue<std::pair<TreeNode*, ull>> q;
        q.push({root, 0});
        ull ans = 0;
        int size = q.size();

        while (size)
        {
            ull left = q.front().second;
            ull right = left;

            for (int i = 0; i < size; ++i)
            {
                auto [node, val] = q.front();
                q.pop();

                right = val;

                if (node->left)
                    q.push({node->left, val * 2});
                if (node->right)
                    q.push({node->right, val * 2 + 1});
            }

            ans = std::max(ans, right - left + 1);
            size = q.size();
        }
        return static_cast<int>(ans);
    }
};
// @lc code=end

