/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        int depth = 0;
        TreeNode* tempNode = root->left;
        while (tempNode)
        {
            depth++;
            tempNode = tempNode->left;
        }
        int depthRight = 0;
        tempNode = root->right;
        while (tempNode)
        {
            depthRight++;
            tempNode = tempNode->left;
        }

        if (depth > depthRight)
        {
            return 1 + (depthRight > 1 ? (1 << depthRight) - 1 : depthRight) + count(root->left);
        }
        else
        {
            return (1 << depth) + count(root->right);
        }
    }

    int count(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + count(root->left) + count(root->right);
    }

};
// @lc code=end

