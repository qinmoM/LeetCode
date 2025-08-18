/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findLHS(vector<int>& nums)
    {
        std::unordered_map<int, int> hash;
        for (int i : nums)
        {
            if (hash.find(i) == hash.end())
            {
                hash[i] = 1;
            }
            else
            {
                hash[i] += 1;
            }
        }

        int result = 0;
        for (std::pair<int, int> temp : hash)
        {
            if (hash.find(temp.first + 1) != hash.end())
            {
                result = max(temp.second + hash[temp.first + 1], result);
            }
        }
        return result;
    }
};
// @lc code=end

