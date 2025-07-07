/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        vector<int>::iterator slow = nums.begin();
        vector<int>::iterator fase = nums.begin();
        vector<int>::iterator last = nums.end();
        while (true)
        {
            while (slow < last && *slow != 0)
            {
                slow++;
            }
            if (slow >= last)
            {
                return;
            }

            if (fase < slow)
            {
                fase = slow + 1;
            }

            while (fase < last && !*fase)
            {
                fase++;
            }
            if (fase >= last)
            {
                return;
            }
            
            *fase += *slow;
            *slow = *fase - *slow;
            *fase = *fase - *slow;
            slow++;
            fase++;
        }
    }
};
// @lc code=end

