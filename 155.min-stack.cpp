/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <vector>
#include <limits.h>

class MinStack
{
public:
    MinStack() { }

    void push(int val)
    {
        int pre = (stack_.empty() ? INT_MAX : stack_.back().second);
        stack_.push_back({ val, std::min(pre, val) });
    }

    void pop()
    {
        stack_.pop_back();
    }

    int top()
    {
        return stack_.back().first;
    }

    int getMin()
    {
        return stack_.back().second;
    }

private:
    std::vector<std::pair<int, int>> stack_;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
