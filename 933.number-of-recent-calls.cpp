/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
#include <list>

class RecentCounter
{
public:
    RecentCounter()
    {
        
    }
    
    int ping(int t)
    {
        int count = 0;
        int target = t - 3000;

        list_.push_back(t);

        for (auto it = list_.rbegin(); it != list_.rend() && *it >= target; ++it)
            ++count;

        return count;
    }
private:
    std::list<int> list_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

