/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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

#include <stack>

class BSTIterator
{
public:
    BSTIterator(TreeNode* root) : root_(root), curr_(nullptr), end_(root)
    {
        while (end_->right)
            end_ = end_->right;
    }
    
    int next()
    {
        if (!hasNext())
            throw "BSTIterator class next function.\n";

        if (nullptr == curr_)
        {
            curr_ = root_;
            stack_.push(curr_);

            while (curr_->left)
                stack_.push(curr_ = curr_->left);

            return curr_->val;
        }

        stack_.pop();

        if (!curr_->right)
        {
            curr_ = stack_.top();
            return curr_->val;
        }

        stack_.push(curr_ = curr_->right);
        while (curr_->left)
            stack_.push(curr_ = curr_->left);

        return curr_->val;
    }
    
    bool hasNext()
    {
        return end_ != curr_;
    }
private:
    TreeNode* root_;
    TreeNode* curr_;
    TreeNode* end_;
    std::stack<TreeNode*> stack_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

