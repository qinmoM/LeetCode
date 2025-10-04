/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
#include <unordered_set>

class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        std::unordered_set<int> hash;
        return inorder(root, k, hash);
    }

    bool inorder(TreeNode* node, const int& k, std::unordered_set<int>& hash)
    {
        if (!node)
        {
            return false;
        }

        bool left = inorder(node->left, k, hash);
        if (hash.find(node->val) != hash.end())
        {
            return true;
        }
        else
        {
            hash.insert(k - node->val);
        }
        bool right = inorder(node->right, k, hash);
        return left || right;
    }

};
// @lc code=end

