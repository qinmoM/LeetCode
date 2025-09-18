/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        postorder(root, result);
        return result;
    }

    void postorder(TreeNode* node, std::vector<int>& v)
    {
        if (nullptr == node)
        {
            return;
        }

        postorder(node->left, v);
        postorder(node->right, v);
        v.push_back(node->val);
    }

};
// @lc code=end

