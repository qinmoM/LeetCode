/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        std::vector<std::string> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tempNum = i;
            while (nums.size() - 1 > i && nums[i + 1] == nums[i] + 1)
            {
                ++i;
            }
            std::string temp = std::to_string(nums[tempNum]);
            if (tempNum != i)
            {
                temp = temp + "->" + std::to_string(nums[i]);
            }
            result.push_back(temp);
        }
        return result;
    }
};
// @lc code=end

