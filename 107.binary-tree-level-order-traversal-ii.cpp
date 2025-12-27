/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
#include <algorithm>
#include <queue>

using std::vector;

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> queue;
        if (root) queue.push(root);
        int count = 0;
        while (count = queue.size())
        {
            std::vector<int> pair;
            while (count--)
            {
                TreeNode* temp = queue.front();
                pair.push_back(temp->val);
                if (temp->left) queue.push(temp->left);
                if (temp->right) queue.push(temp->right);
                queue.pop();
            }
            result.push_back(pair);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

