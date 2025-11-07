/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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

#include <vector>

class Solution
{
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        std::vector<int> sequence1;
        std::vector<int> sequence2;
        leafDepth(root1, sequence1);
        leafDepth(root2, sequence2);
        if (sequence1.size() != sequence2.size())
        {
            return false;
        }
        for (int i = 0; i < sequence1.size(); ++i)
        {
            if (sequence1[i] != sequence2[i])
            {
                return false;
            }
        }
        return true;
    }

    void leafDepth(TreeNode* node, std::vector<int>& vec)
    {
        if (!node)
        {
            return;
        }
        if (!node->right && !node->left)
        {
            vec.push_back(node->val);
            return;
        }
        leafDepth(node->left, vec);
        leafDepth(node->right, vec);
    }

};
// @lc code=end

