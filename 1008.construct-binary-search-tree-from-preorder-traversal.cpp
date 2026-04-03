/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
#include <iostream>

using std::vector;

class Solution
{
public:
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int index = 0;
        return dfs(preorder, index, INT_MAX);
    }

    TreeNode* dfs(const vector<int>& preorder, int& index, int bound)
    {
        if (index >= preorder.size() || preorder[index] > bound) return nullptr;

        int val = preorder[index++];
        return new TreeNode(val,
            dfs(preorder, index, val),
            dfs(preorder, index, bound)
        );
    }

    // TreeNode* dfs(int left, int right, const vector<int>& preorder)
    // {
    //     if (left > right) return nullptr;

    //     int mid = left + 1;
    //     while (mid <= right && preorder[mid] < preorder[left]) ++mid;

    //     return new TreeNode(preorder[left],
    //         dfs(left + 1, mid - 1, preorder),
    //         dfs(mid, right, preorder)
    //     );
    // }
};
// @lc code=end

