/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using std::vector;

class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        std::unordered_map<int, int> hash;
        for (int i : nums1)
            ++hash[i];

        std::vector<int> res;
        for (int i : nums2)
        {
            auto it = hash.find(i);
            if (it == hash.end() || it->second == 0) continue;

            --it->second;
            res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

