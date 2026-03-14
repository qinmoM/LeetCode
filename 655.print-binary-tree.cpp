/*
 * @lc app=leetcode id=655 lang=cpp
 *
 * [655] Print Binary Tree
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
#include <string>
#include <cmath>
#include <iostream>

using std::vector;
using std::string;

class Solution
{
public:
    vector<vector<string>> printTree(TreeNode* root)
    {
        int level = height(root, 0);

        if (1 == level) return { { std::to_string(root->val) } };

        int n = (2 << (level - 1)) - 1;
        std::vector<std::vector<std::string>> vec(level, std::vector<std::string>(n, ""));

        int col = (n - 1) / 2;
        vec[0][col] = std::to_string(root->val);

        matrix(root->left, 0, col - (2 == level ? 1 : (2 << (level - 3))), vec, true, level - 1);
        matrix(root->right, 0, col + (2 == level ? 1 : (2 << (level - 3))), vec, false, level - 1);

        return vec;
    }

    void matrix(TreeNode* node, int level, int col, std::vector<std::vector<std::string>>& vec, bool isLeft, int height)
    {
        if (!node) return;

        ++level;
        std::cout << level << ' ' << col << "\n";
        vec[level][col] = std::to_string(node->val);

        int temp = (height - level - 2 >= 0 ? 2 << (height - level - 2) : 1);
        int left = col - temp;
        int right = col + temp;
        std::cout << temp << ' ' << left << ' ' << right << "\n";

        matrix(node->left, level, left, vec, true, height);
        matrix(node->right, level, right, vec, false, height);
    }

    int height(TreeNode* node, int level)
    {
        if (!node) return level;

        return std::max(height(node->left, level + 1), height(node->right, level + 1));
    }
};
// @lc code=end

