/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
#include <queue>

using std::vector;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root) return {};
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (queue.size())
        {
            int count = queue.size();
            std::vector<int> part;
            while (count--)
            {
                TreeNode* temp = queue.front();
                part.push_back(temp->val);
                queue.pop();
                if (temp->left) queue.push(temp->left);
                if (temp->right) queue.push(temp->right);
            }
            result.push_back(part);
        }
        return result;
    }
};
// @lc code=end

