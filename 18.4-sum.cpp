/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if (nums.size() < 4)
        {
            return { };
        }
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        int index3 = 2, index4 = 3;
        for (int i = 0; i < nums.size() - 3; )
        {
            for (int j = i + 1; j < nums.size() - 2; )
            {
                int sumTwo = nums[i] + nums[j];
                index3 = j + 1;
                index4 = nums.size() - 1;
                while (index4 > index3)
                {
                    long long tempTwo = nums[index3] + nums[index4];
                    if (sumTwo + tempTwo == target)
                    {
                        result.push_back( { nums[i], nums[j], nums[index3], nums[index4] } );
                        int temp = nums[index4];
                        while (index4 > index3 && nums[--index4] == temp);
                        temp = nums[index3];
                        while (index4 > index3 && nums[++index3] == temp);
                    }
                    else if (sumTwo + tempTwo > target)
                    {
                        int temp = nums[index4];
                        while (index4 > index3 && nums[--index4] == temp);
                    }
                    else
                    {
                        int temp = nums[index3];
                        while (index4 > index3 && nums[++index3] == temp);
                    }
                }
                int temp = nums[j];
                while (j < nums.size() - 2 && nums[++j] == temp);
            }
        int temp = nums[i];
        while (i < nums.size() - 3 && nums[++i] == temp);
        }
        return result;
    }
};
// @lc code=end

