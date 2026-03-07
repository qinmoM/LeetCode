/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root)
    {
        int result = 0;
        int levelMax = 0;
        dfs(root, 1, levelMax, result);
        return result;
    }

    auto dfs(TreeNode* node, int levelCurr, int& levelMax, int& target) -> void
    {
        if (!node) return;

        if (!node->left && !node->right && levelCurr > levelMax)
        {
            levelMax = levelCurr;
            target = node->val;
        }

        dfs(node->left, levelCurr + 1, levelMax, target);
        dfs(node->right, levelCurr + 1, levelMax, target);
    }
};
// @lc code=end

