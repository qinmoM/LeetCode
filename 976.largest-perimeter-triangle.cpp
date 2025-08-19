/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int result = 0;
        int k = nums.size() - 1;
        while (k >= 2)
        {
            if (isTriangle(nums[k - 2], nums[k - 1], nums[k]))
            {
                return nums[k - 2] + nums[k - 1] + nums[k];
            }
            k -= 1;
        }
        return result;
    }

    bool isTriangle(int a, int b, int c)
    {
        if (a + b <= c)
        {
            return false;
        }
        return true;
    }

};
// @lc code=end

