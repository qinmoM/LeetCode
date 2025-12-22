/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root)
    {
        inorder(root);
        std::swap(first->val, second->val);
    }

private:
    void inorder(TreeNode* node)
    {
        if (!node) return;

        inorder(node->left);

        if (nullptr != last && last->val > node->val)
        {
            if (!first) first = last;
            second = node;
        }
        last = node;

        inorder(node->right);
    }

    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* last = nullptr;
};
// @lc code=end

