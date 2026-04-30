/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<int> pancakeSort(vector<int>& arr)
    {
        int curr = arr.size();
        std::vector<int> res;

        while (curr)
        {
            auto it = std::find(arr.begin(), arr.begin() + curr, curr);
            std::reverse(arr.begin(), it + 1);
            res.push_back(it + 1 - arr.begin());
            std::reverse(arr.begin(), arr.begin() + curr);
            res.push_back(curr);
            --curr;
        }
        return res;
    }
};
// @lc code=end

