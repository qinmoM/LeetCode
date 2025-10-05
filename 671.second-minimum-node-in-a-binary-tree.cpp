/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    int findSecondMinimumValue(TreeNode* root)
    {
        std::set<int> set;
        preorder(root, set);
        return set.size() == 1 ? -1 : *(++set.begin());
    }

    void preorder(TreeNode* node, std::set<int>& set)
    {
        if (!node)
        {
            return;
        }
        set.insert(node->val);
        preorder(node->left, set);
        preorder(node->right, set);
    }
};
// @lc code=end

