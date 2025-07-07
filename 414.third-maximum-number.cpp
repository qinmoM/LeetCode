/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int thirdMax(vector<int>& nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){ return a > b; });
        int result = nums[0];
        int index = 2;
        for (int i = 1; i < size && index; i++)
        {
            if (nums[i] != result)
            {
                result = nums[i];
                index--;
            }
        }
        if (index)
        {
            return nums[0];
        }
        else
        {
            return result;
        }
    }
};
// @lc code=end

