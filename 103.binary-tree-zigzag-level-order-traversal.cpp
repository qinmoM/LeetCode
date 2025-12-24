/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
#include <stack>
#include <queue>

using std::vector;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> result;
        std::stack<TreeNode*> stack;
        bool opposite = false;
        if (root) stack.push(root);
        while (stack.size())
        {
            std::queue<TreeNode*> queue;
            std::vector<int> pair;
            if (opposite) while (stack.size())
            {
                TreeNode* temp = stack.top();
                pair.push_back(temp->val);
                if (temp->right) queue.push(temp->right);
                if (temp->left) queue.push(temp->left);
                stack.pop();
            }
            else while (stack.size())
            {
                TreeNode* temp = stack.top();
                pair.push_back(temp->val);
                if (temp->left) queue.push(temp->left);
                if (temp->right) queue.push(temp->right);
                stack.pop();
            }
            while (queue.size())
            {
                stack.push(queue.front());
                queue.pop();
            }
            result.push_back(pair);
            opposite = !opposite;
        }
        return result;
    }
};
// @lc code=end

