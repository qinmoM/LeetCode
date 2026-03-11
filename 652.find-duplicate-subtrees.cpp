/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
#include <unordered_map>
#include <string>

using std::vector;

class Solution
{
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        std::unordered_map<std::string, int> hash;
        std::vector<TreeNode*> vec;
        serialize(root, vec, hash);
        return vec;
    }

    std::string serialize(TreeNode* node, std::vector<TreeNode*>& vec, std::unordered_map<std::string, int>& hash)
    {
        if (!node) return "#";

        std::string temp = std::to_string(node->val) + " " + serialize(node->left, vec, hash) + " " + serialize(node->right, vec, hash);

        hash[temp] += 1;
        if (2 == hash[temp])
            vec.push_back(node);

        return temp;
    }
};
// @lc code=end

