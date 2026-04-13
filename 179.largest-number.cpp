/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        std::vector<std::string> numsStr(nums.size(), "");
        for (int i = 0; i < nums.size(); ++i)
            numsStr[i] = std::to_string(nums[i]);

        std::sort(numsStr.begin(), numsStr.end(),
            [](const std::string& a, const std::string& b) -> bool
            {
                return a + b > b + a;
            }
        );

        for (int i = 1; i < nums.size(); ++i)
            numsStr[0] += std::move(numsStr[i]);

        return (numsStr[0][0] == '0' ? "0" : numsStr[0]);
    }
};
// @lc code=end

