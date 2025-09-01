/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int>& nums)
    {
        std::unordered_set<int> set;
        for (int i : nums)
        {
            if (set.find(i) != set.end())
            {
                return i;
            }
            set.insert(i);
        }
        throw "No repeated element found";
    }
};
// @lc code=end

