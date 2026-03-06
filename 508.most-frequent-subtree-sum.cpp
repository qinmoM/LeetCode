/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        std::unordered_map<int, int> hash;
        std::vector<int> result;
        int rootNum = dfs(root, hash);
        
        int max = std::max_element(hash.begin(), hash.end(), 
            [](const std::pair<int, int>& a, const std::pair<int, int>& b)
            {
                return a.second < b.second;
            }
        )->second;

        for (auto [num, count] : hash)
        {
            if (max == count)
                result.push_back(num);
        }

        return result;
    }

    int dfs(TreeNode* node, std::unordered_map<int, int>& hash)
    {
        if (!node) return 0;

        int left = dfs(node->left, hash);
        int right = dfs(node->right, hash);

        int all = left + right + node->val;
        hash[all] += 1;
        return all;
    }
};
// @lc code=end

