/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int size = bits.size();
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            if (1 == bits[i])
            {
                i++;
                flag = false;
            }
            else
            {
                flag = true;
            }
        }
        return flag;
    }
};
// @lc code=end

