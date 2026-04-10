/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
#include <deque>

class RecentCounter
{
public:
    RecentCounter() { }
    
    int ping(int t)
    {
        int target = t - 3000;
        q_.push_back(t);

        while (q_.size() && q_.front() < target)
            q_.pop_front();

        return q_.size();
    }
private:
    std::deque<int> q_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

