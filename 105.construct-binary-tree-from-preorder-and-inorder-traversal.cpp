/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

using std::vector;

class Solution
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        std::unordered_map<int, int> hash(preorder.size());
        for (int i = 0; i < preorder.size(); ++i) hash[inorder[i]] = i;
        int curr = 0;
        return build(hash, preorder, curr, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(const std::unordered_map<int, int>& hash, const std::vector<int>& preorder, int& curr, const std::vector<int>& inorder, int inLeft, int inRight)
    {
        if (inLeft > inRight) return nullptr;
        int mid = hash.at(preorder[curr]);
        TreeNode* node = new TreeNode(preorder[curr++]);
        node->left = build(hash, preorder, curr, inorder, inLeft, mid - 1);
        node->right = build(hash, preorder, curr, inorder, mid + 1, inRight);
        return node;
    }
};
// @lc code=end

