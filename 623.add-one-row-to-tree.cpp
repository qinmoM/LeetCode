/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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

class Solution
{
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if (!root) return nullptr;

        if (1 == depth)
            return new TreeNode(val, root, nullptr);

        if (2 == depth)
        {
            TreeNode* left = new TreeNode(val, root->left, nullptr);
            TreeNode* right = new TreeNode(val, nullptr, root->right);
            root->left = left;
            root->right = right;
            return root;
        }

        addOneRow(root->left, val, depth - 1);
        addOneRow(root->right, val, depth - 1);

        return root;
    }
};
// @lc code=end

