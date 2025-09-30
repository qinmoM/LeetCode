/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
class Solution
{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root)
        {
            return false;
        }
        return isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode* node, TreeNode* subNode)
    {
        if (!node && !subNode)
        {
            return true;
        }
        if (!node || !subNode)
        {
            return false;
        }
        if (node->val != subNode->val)
        {
            return false;
        }
        return isSame(node->left, subNode->left) && isSame(node->right, subNode->right);
    }

};
// @lc code=end

