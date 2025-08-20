/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
#include <vector>
#include <limits>

using namespace std;

class Solution
{
public:
    int smallestRangeI(vector<int>& nums, int k)
    {
        int max = std::numeric_limits<int>::min();
        int min = std::numeric_limits<int>::max();
        for (int i : nums)
        {
            min = std::min(min, i);
            max = std::max(max, i);
        }
        return (max - min - 2 * k > 0) ? max - min - 2 * k : 0;
    }
};
// @lc code=end

