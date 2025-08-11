/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
// #include <iostream>
// #include <vector>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            int need = target - nums[i];
            if (hash.count(need))
            {
                return { i, hash[need]};
            }
            hash[nums[i]] = i;
        }
        return { };
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             return { i, j };
        //         }
        //     }
        // }
        // return { };
    }
};

// @lc code=end

