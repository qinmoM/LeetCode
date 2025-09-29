/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    int findTilt(TreeNode* root)
    {
        int count = 0;
        sumAbs(root, count);
        return count;
    }

    int sumAbs(TreeNode* node, int& all)
    {
        if (!node)
        {
            return 0;
        }
        int left = sumAbs(node->left, all);
        int right = sumAbs(node->right, all);
        int temp = left + right + node->val;
        all += std::abs(left - right);
        return temp;
    }

    // int absChild(TreeNode* node, int& all)
    // {
    //     if (nullptr == node)
    //     {
    //         return 0;
    //     }

    //     all += std::abs(absChild(node->left, all) - absChild(node->right, all));
    //     return node->val;
    // }

};
// @lc code=end

