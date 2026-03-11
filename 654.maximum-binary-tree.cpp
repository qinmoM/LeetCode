/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        std::vector<TreeNode*> vec;

        for (int n : nums)
        {
            TreeNode* node = new TreeNode(n);

            while (vec.size() && vec.back()->val < n)
            {
                node->left = vec.back();
                vec.pop_back();
            }

            if (vec.size() && vec.back() != node)
                vec.back()->right = node;

            vec.push_back(node);
        }

        return vec.front();

        // return recursion(nums, 0, nums.size());
    }

    // TreeNode* recursion(const std::vector<int>& nums, int left, int right)
    // {
    //     if (left >= right) return nullptr;

    //     int maxIndex = left;
    //     for (int i = left + 1; i < right; ++i)
    //     {
    //         if (nums[i] > nums[maxIndex])
    //             maxIndex = i;
    //     }

    //     return new TreeNode(nums[maxIndex], recursion(nums, left, maxIndex), recursion(nums, maxIndex + 1, right));
    // }
};
// @lc code=end

