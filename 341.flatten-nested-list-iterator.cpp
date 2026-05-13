/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <vector>
#include <stack>

using std::vector;

// class NestedInteger
// {
//   public:
//     // Return true if this NestedInteger holds a single integer, rather than a nested list.
//     bool isInteger() const;
//     // Return the single integer that this NestedInteger holds, if it holds a single integer
//     // The result is undefined if this NestedInteger holds a nested list
//     int getInteger() const;
//     // Return the nested list that this NestedInteger holds, if it holds a nested list
//     // The result is undefined if this NestedInteger holds a single integer
//     const vector<NestedInteger> &getList() const;
// };

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        dfs(nestedList);
    }

    int next()
    {
        return res_[index_++];
    }

    bool hasNext()
    {
        return index_ < res_.size();
    }

private:
    void dfs(const std::vector<NestedInteger>& nestedList)
    {
        for (const NestedInteger& nest : nestedList)
        {
            if (nest.isInteger())
                res_.push_back(nest.getInteger());
            else
                dfs(nest.getList());
        }
    }

    // std::stack<std::vector<NestedInteger>::iterator> stack_;
    std::vector<int> res_;
    int index_ = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

