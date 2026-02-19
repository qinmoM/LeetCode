/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#ifndef NULL
#define NULL nullptr
#endif

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (p->val > q->val) std::swap(p, q);
        return traverse(root, p, q);
    }

    TreeNode* traverse(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (node->val >= p->val && node->val <= q->val)
            return node;
            
        if (q->val < node->val)
            return traverse(node->left, p, q);
        else
            return traverse(node->right, p, q);
    }
};
// @lc code=end

