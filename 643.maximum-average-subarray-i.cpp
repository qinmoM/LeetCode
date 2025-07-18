/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        int size = nums.size();
        double curr = 0.0;
        double max = 0.0;

        for (int i = 0; i < k; i++)
        {
            curr += nums[i];
        }
        max = curr;

        for (int i = k; i < size; i++)
        {
            curr = curr + nums[i] - nums[i - k];
            if (curr > max)
            {
                max = curr;
            }
        }
        max /= k;

        return max;
    }
};
// @lc code=end

