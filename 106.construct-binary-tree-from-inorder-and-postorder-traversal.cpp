/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        std::unordered_map<int, int> hash(inorder.size());
        for (int i = 0; i < inorder.size(); ++i) hash[inorder[i]] = i;
        int currIndex = postorder.size() - 1;
        return build(hash, 0, inorder.size() - 1, postorder, currIndex);
    }

    TreeNode* build(const std::unordered_map<int, int>& hash, int left, int right, const vector<int>& postorder, int& index)
    {
        if (index < 0 || left > right) return nullptr;

        int mid = hash.at(postorder[index]);
        TreeNode* node = new TreeNode(postorder[index--]);
        node->right = build(hash, mid + 1, right, postorder, index);
        node->left = build(hash, left, mid - 1, postorder, index);
        return node;
    }
};
// @lc code=end

