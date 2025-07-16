/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int size = flowerbed.size();
        int count = 1;
        int sum = 0;
        int i = 0;

        for (int j = 0; j < size; j++)
        {
            if (0 == flowerbed[j])
            {
                count++;
                if (!(j + 1 - size))
                {
                    sum += count / 2;
                }
            }
            else
            {
                sum += (count - 1) / 2;
                count = 0;
            }
        }

        return sum >= n;
    }
};
// @lc code=end

