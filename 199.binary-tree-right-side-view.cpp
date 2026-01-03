/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> result;
        preorder(result, root, 0);
        return result;
    }

    void preorder(std::vector<int>& result, TreeNode* node, int level)
    {
        if (!node) return;

        if (result.size() == level)
            result.push_back(node->val);
        else
            result[level] = node->val;

        preorder(result, node->left, level + 1);
        preorder(result, node->right, level + 1);
    }
};
// @lc code=end

