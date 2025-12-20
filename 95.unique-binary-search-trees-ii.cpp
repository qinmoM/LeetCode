/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n)
    {
        if (0 == n) return {};
        return build(1, n);
    }

    std::vector<TreeNode*> build(int left, int right)
    {
        std::vector<TreeNode*> res;
        if (left > right)
        {
            res.push_back(nullptr);
            return res;
        }
        for (int i = left; i <= right; ++i)
        {
            std::vector<TreeNode*> leftTrees = build(left, i - 1);
            std::vector<TreeNode*> rightTrees = build(i + 1, right);
            for (TreeNode* leftTree : leftTrees)
            {
                for (TreeNode* rightTree : rightTrees)
                {
                    TreeNode* node = new TreeNode(i, leftTree, rightTree);
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
// @lc code=end

