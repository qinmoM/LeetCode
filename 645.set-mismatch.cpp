/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        long long all = nums.size() / 2 * (nums.size() + 1) + ((nums.size() & 1) ? (1 + nums.size()) / 2 : 0);
        std::unordered_set<int> hash;
        int repeat = 0;
        for (int i : nums)
        {
            if (hash.find(i) == hash.end())
            {
                all -= i;
                hash.insert(i);
            }
            else
            {
                repeat = i;
            }
        }
        return { repeat, static_cast<int>(all) };
    }
};
// @lc code=end

