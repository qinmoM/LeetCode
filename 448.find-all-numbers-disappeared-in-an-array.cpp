/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> result;
        int temp = 0;
        for (int i = 0; i < size; i++)
        {
            temp = (nums[i] > 0 ? nums[i] : -nums[i]) - 1;
            if (0 <= nums[temp])
            {
                nums[temp] *= -1;
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > 0)
            {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
// @lc code=end

