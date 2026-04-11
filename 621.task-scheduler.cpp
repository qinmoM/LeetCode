/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
#include <vector>

using std::vector;
class Solution
{
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        std::vector<int> hash(26, 0);
        int maxFrep = 0;
        for (char c : tasks)
        {
            int index = c - 'A';
            maxFrep = std::max(maxFrep, ++hash[index]);
        }
        int numMax = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (maxFrep == hash[i])
                ++numMax;
        }
        return std::max((n + 1) * (maxFrep - 1) + numMax, static_cast<int>(tasks.size()));
    }
};
// @lc code=end

