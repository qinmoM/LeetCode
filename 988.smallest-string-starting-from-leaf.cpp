/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
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
    string smallestFromLeaf(TreeNode* root)
    {
        string res = std::string(1, char('z' + 1));
        dfs(root, "", res);
        return res;
    }

    void dfs(TreeNode* node, std::string s, std::string& res)
    {
        if (!node) return;

        s = char('a' + node->val) + s;

        if (!node->left && !node->right)
        {
            if (s < res) res = s;
            return;
        }

        dfs(node->left, s, res);
        dfs(node->right, s, res);
    }
};
// @lc code=end

