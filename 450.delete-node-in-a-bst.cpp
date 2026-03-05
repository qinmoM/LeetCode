/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        TreeNode* node = root;
        TreeNode* parent = nullptr;
        while (node && node->val != key)
        {
            parent = node;

            if (node->val > key)
                node = node->left;
            else
                node = node->right;
        }

        if (!node) return root;

        if (node->left && node->right)
        {
            TreeNode* pre = node->left;
            TreeNode* preParent = nullptr;
            while (pre->right)
            {
                preParent = pre;
                pre = pre->right;
            }
            node->val = pre->val;
            if (preParent)
                preParent->right = pre->left;
            else
                node->left = pre->left;
            delete pre;
        }
        else if (node->left)
        {
            TreeNode* temp = node;

            if (!parent)
                root = node->left;
            else if (parent->left == node)
                parent->left = node->left;
            else
                parent->right = node->left;

            delete temp;
        }
        else
        {
            TreeNode* temp = node;

            if (!parent)
                root = node->right;
            else if (parent->left == node)
                parent->left = node->right;
            else
                parent->right = node->right;

            delete temp;
        }

        return root;
    }
};
// @lc code=end

