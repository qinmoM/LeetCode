/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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

#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        std::vector<TreeNode*> hash(501, nullptr);
        build(root, hash);
        std::vector<int> result;
        find(k, target, nullptr, hash, result);
        return result;
    }

    void find(int level, TreeNode* curr, TreeNode* last, std::vector<TreeNode*>& hash, std::vector<int>& vec)
    {
        if (!curr) return;

        if (!level)
            return vec.push_back(curr->val);

        if (last != curr->left) find(level - 1, curr->left, curr, hash, vec);
        if (last != curr->right) find(level - 1, curr->right, curr, hash, vec);
        if (last != hash[curr->val]) find(level - 1, hash[curr->val], curr, hash, vec);
    }

    void build(TreeNode* node, std::vector<TreeNode*>& hash)
    {
        if (node->left)
        {
            hash[node->left->val] = node;
            build(node->left, hash);
        }
        if (node->right)
        {
            hash[node->right->val] = node;
            build(node->right, hash);
        }
    }
};
// @lc code=end

