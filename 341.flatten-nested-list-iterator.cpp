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
    using IT = std::vector<NestedInteger>::const_iterator;
    using ITpair = std::pair<IT, IT>;

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        stack_.push({ nestedList.begin(), nestedList.end() });
    }

    int next()
    {
        return curr_;
    }

    bool hasNext()
    {
        if (quit_) return false;

        while (!stack_.empty())
        {
            ITpair* it = &stack_.top();

            if (it->first == it->second)
            {
                stack_.pop();
                if (!stack_.empty()) ++(stack_.top().first);
            }
            else if (it->first->isInteger())
            {
                curr_ = it->first->getInteger();

                ++(it->first);
                while (it->first == it->second)
                {
                    stack_.pop();
                    if (stack_.empty())
                    {
                        quit_ = true;
                        break;
                    }

                    it = &stack_.top();
                    ++(it->first);
                }

                return true;
            }
            else
            {
                const auto& temp = it->first->getList();
                stack_.push({ temp.begin(), temp.end() });
            }
        }

        return false;
    }

private:
    // void dfs(const std::vector<NestedInteger>& nestedList)
    // {
    //     for (const NestedInteger& nest : nestedList)
    //     {
    //         if (nest.isInteger())
    //             res_.push_back(nest.getInteger());
    //         else
    //             dfs(nest.getList());
    //     }
    // }

    std::stack<ITpair> stack_;
    int curr_ = 0;
    bool quit_ = false;
    // std::vector<int> res_;
    // int index_ = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

