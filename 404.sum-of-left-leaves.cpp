/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        int sum = 0;
        leftLeaves(root->left, sum, LEFT);
        leftLeaves(root->right, sum, RIGHT);
        return sum;
    }

    void leftLeaves(TreeNode* node, int& sum, bool left)
    {
        if (!node)
        {
            return;
        }

        if ((!node->left) && (!node->right))
        {
            if (left)
            {
                sum += node->val;
            }
            return;
        }

        if (node->left)
        {
            leftLeaves(node->left, sum, LEFT);
        }
        if (node->right)
        {
            leftLeaves(node->right, sum, RIGHT);
        }
    }

public:
    constexpr static bool LEFT = true;
    constexpr static bool RIGHT = false;

};
// @lc code=end

