/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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

class Solution
{
public:
    int pathSum(TreeNode* root, int targetSum)
    {
        int count = 0;
        std::vector<long long> vec;
        dfs(root, targetSum, vec, count);
        return count;
    }

    void dfs(TreeNode* node, int targetSum, std::vector<long long>& nums, int& count)
    {
        if (!node) return;

        nums.push_back(0);

        for (long long& num : nums)
        {
            num += node->val;

            if (num == targetSum)
                ++count;
        }

        dfs(node->left, targetSum, nums, count);
        dfs(node->right, targetSum, nums, count);

        for (long long& num : nums)
            num -= node->val;

        nums.pop_back();
    }
};
// @lc code=end

