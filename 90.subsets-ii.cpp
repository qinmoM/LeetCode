/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include <vector>
#include <algorithm>
// #include <unordered_set>
// #include <string>

using std::vector;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        std::vector<int> vec;
        prefix(result, 0, vec, nums);
        return result;

        // std::vector<std::vector<int>> result;
        // std::unordered_set<std::string> hash;
        // std::string s;
        // std::vector<int> vec;
        // for (int i = 0; i <= nums.size(); ++i)
        // {
        //     recursion(result, nums, 0, hash, vec, s, i);
        // }
        // return result;
    }

    void prefix(std::vector<std::vector<int>>& result, int index, std::vector<int>& vec, const std::vector<int>& nums)
    {
        result.push_back(vec);

        for (int i = index; i < nums.size(); ++i)
        {
            if (index != i && nums[i] == nums[i - 1])
            {
                continue;
            }

            vec.push_back(nums[i]);
            prefix(result, i + 1, vec, nums);
            vec.pop_back();
        }
    }

    // void recursion(std::vector<std::vector<int>>& result, const std::vector<int>& nums, int index,
    //     std::unordered_set<std::string>& hash, std::vector<int>& vec, std::string& s, int depth)
    // {
    //     if (0 == depth)
    //     {
    //         if (hash.find(s) == hash.end())
    //         {
    //             result.push_back(vec);
    //             hash.insert(s);
    //         }
    //         return;
    //     }
    //
    //     for (int i = index; i <= nums.size() - (depth - vec.size()); ++i)
    //     {
    //         vec.push_back(nums[i]);
    //         std::string temp = s + std::to_string(nums[i]);
    //         recursion(result, nums, index + 1, hash, vec, temp, depth - 1);
    //         vec.pop_back();
    //     }
    // }

    // std::string toString(const std::vector<int>& vec)
    // {
    //     std::string result;
    //     for (int i : vec) result += std::to_string(i);
    //     return result;
    // }

};
// @lc code=end

