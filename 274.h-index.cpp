/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        std::sort(citations.begin(), citations.end(), std::greater<int>());

        int i = 0;
        while (i < citations.size() && i + 1 <= citations[i]) ++i;

        return i;
    }
};
// @lc code=end

