/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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

#include <string>

using std::string;

class Solution
{
public:
    string tree2str(TreeNode* root)
    {
        std::string s;
        dfs(root, s);
        return s;

        // if (!root) return "";

        // if (!root->left && !root->right)
        //     return std::to_string(root->val);

        // std::string left = tree2str(root->left);
        // std::string right = tree2str(root->right);

        // return std::to_string(root->val) + "(" + left + ")" + (root->right ? "(" + right + ")" : "");
    }

    void dfs(TreeNode* node, std::string& s)
    {
        if (!node) return;

        s += std::to_string(node->val);

        if (node->left || node->right)
        {
            s += "(";
            dfs(node->left, s);
            s += ")";
        }

        if (node->right)
        {
            s += "(";
            dfs(node->right, s);
            s += ")";
        }
    }
};
// @lc code=end

