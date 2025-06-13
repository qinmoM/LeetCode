/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int all = 0;
        int temp = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (!i)
            {
                temp = nums[0];
                all += 1;
                continue;
            }
            if (temp != nums[i])
            {
                all += 1;
                temp = nums[i];
                nums[all - 1] = temp;
            }
        }
        return all;
    }
};
// @lc code=end

