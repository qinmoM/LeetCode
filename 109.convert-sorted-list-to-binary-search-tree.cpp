/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

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

class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (!head) return nullptr;
        std::vector<int> vec;
        while (head)
        {
            vec.push_back(head->val);
            ListNode* temp = head;
            head = head->next;
        }
        return recursion(vec, 0, vec.size() - 1);
    }

    TreeNode* recursion(const std::vector<int>& vec, int left, int right)
    {
        if (left == right) return new TreeNode(vec[left]);

        int mid = (left + right) / 2;
        TreeNode* curr = new TreeNode(vec[mid], nullptr, nullptr);
        if (left < mid) curr->left = recursion(vec, left, mid - 1);
        if (mid < right) curr->right = recursion(vec, mid + 1, right);
        return curr;
    }

};
// @lc code=end

