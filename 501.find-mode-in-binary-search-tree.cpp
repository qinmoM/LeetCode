/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findMode(TreeNode* root)
    {
        std::unordered_map<int, int> hash;
        std::vector<int> result;
        inorder(root, hash);
        int Max = 0;
        for (auto [key, value] : hash)
        {
            Max = std::max(value, Max);
        }
        for (auto [key, value] : hash)
        {
            if (value == Max)
            {
                result.push_back(key);
            }
        }
        return result;
    }

    void inorder(TreeNode* node, std::unordered_map<int, int>& hash)
    {
        if (!node)
        {
            return;
        }

        inorder(node->left, hash);

        ++hash[node->val];

        inorder(node->right, hash);
    }

};
// @lc code=end

