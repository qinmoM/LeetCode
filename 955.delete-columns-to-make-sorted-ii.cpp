/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */

// @lc code=start
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
public:
    int minDeletionSize(vector<string>& strs)
    {
        int size = strs[0].size();
        std::vector<bool> vec(strs.size() - 1, false);
        std::vector<bool> temp(vec);
        int num = 0;

        for (int i = 0; i < size; ++i)
        {
            bool ascend = false;
            temp = vec;
            for (int j = 0; j < strs.size() - 1; ++j)
            {
                if (vec[j]) continue;

                if (strs[j][i] > strs[j + 1][i])
                {
                    ascend = true;
                    break;
                }
                else if (strs[j][i] < strs[j + 1][i])
                    temp[j] = true;
            }
            if (ascend) ++num;
            else vec = temp;
        }
        return num;
    }
};
// @lc code=end

