/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using std::vector;

class Solution
{
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        std::unordered_map<int, int> hash;
        int result = 0;
        int prefix = 0;
        hash[0] = 1;
        for (int num : nums)
        {
            prefix += num;

            auto it = hash.find(prefix - goal);
            if (it != hash.end())
                result += it->second;

            hash[prefix] += 1;
        }
        return result;

        // int count = 0;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     int all = 0;
        //     for (int j = i; j < nums.size(); ++j)
        //     {
        //         all += nums[j];
        //         if (all == goal)
        //             ++count;
        //     }
        // }
        // return count;
    }
};
// @lc code=end

