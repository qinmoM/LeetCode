/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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

using std::vector;

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> pairs;
        if (root) depth(result, root, targetSum, pairs, 0);
        return result;
    }

    void depth(std::vector<std::vector<int>>& result, TreeNode* node, const int& targetSum, std::vector<int>& pairs, int all)
    {
        pairs.push_back(node->val);
        int currAll = all + node->val;
        if (!node->left && !node->right)
        {
            if (currAll == targetSum) result.push_back(pairs);
            pairs.pop_back();
            return;
        }

        if (node->left) depth(result, node->left, targetSum, pairs, currAll);
        if (node->right) depth(result, node->right, targetSum, pairs, currAll);

        pairs.pop_back();
    }
};
// @lc code=end

