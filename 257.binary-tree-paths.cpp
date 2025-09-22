/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        std::vector<std::string> result;
        if (nullptr != root)
        {
            pathGenerate(root, result, "");
        }
        return result;
    }

    void pathGenerate(TreeNode* node, std::vector<std::string>& vec, std::string last)
    {
        last += (last == "" ? "" : "->") + std::to_string(node->val);
        if (nullptr == node->left && nullptr == node->right)
        {
            vec.push_back(last);
            return;
        }

        if (node->left)
        {
            pathGenerate(node->left, vec, last);
        }
        if (node->right)
        {
            pathGenerate(node->right, vec, last);
        }
    }

};
// @lc code=end

