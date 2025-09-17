/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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

using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode* node, std::vector<int>& vec)
    {
        if (node == nullptr)
        {
            return;
        }

        vec.push_back(node->val);
        preorder(node->left, vec);
        preorder(node->right, vec);
    }

};
// @lc code=end

