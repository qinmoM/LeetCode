/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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

using namespace std;
 
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        if (!root)
        {
            return { };
        }
        std::vector<double> vec;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            int sizeTemp = size;
            double average = 0.0;
            while (size--)
            {
                if (queue.front()->left)
                {
                    queue.push(queue.front()->left);
                }
                if (queue.front()->right)
                {
                    queue.push(queue.front()->right);
                }
                average += static_cast<double>(queue.front()->val);
                queue.pop();
            }
            vec.push_back(average / sizeTemp);
        }
        return vec;
    }
};
// @lc code=end

