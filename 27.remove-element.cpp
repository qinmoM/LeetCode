/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int all = nums.size();
        int index = 0;
        int numVal = 0;
        for (int i = 0; i < all; i++)
        {
            int temp = nums[i];
            if (val == temp)
            {
                numVal++;
            }
            else
            {
                nums[index] = temp;
                index++;
            }
        }
        return all - numVal;
    }
};
// @lc code=end

