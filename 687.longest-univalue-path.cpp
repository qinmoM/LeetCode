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

class Solution
{
public:
    int longestUnivaluePath(TreeNode* root)
    {
        if (!root) return 0;
        int all = 1;
        recursion(root->left, root->val, 1, all);
        recursion(root->right, root->val, 1, all);
        return all;
    }

    void recursion(TreeNode* node, int last, int same, int& all)
    {
        if (nullptr == node)
        {
            all = std::max(same, all);
            return;
        }

        if (node->val != last)
        {
            all = std::max(same, all);
            same = 0;
        }

        recursion(node->left, node->val, same + 1, all);
        recursion(node->right, node->val, same + 1, all);
    }
};
// @lc code=end

