/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
// struct TreeNode {
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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return creatAVL(nums, 0, nums.size() - 1);
    }

    TreeNode* creatAVL(std::vector<int>& vec, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = (right + left) / 2;
        TreeNode* temp = new TreeNode(vec[mid]);
        temp->left = creatAVL(vec, left, mid - 1);
        temp->right = creatAVL(vec, mid + 1, right);
        return temp;
    }

};
// @lc code=end

