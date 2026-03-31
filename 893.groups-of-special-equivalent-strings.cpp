/*
 * @lc app=leetcode id=893 lang=cpp
 *
 * [893] Groups of Special-Equivalent Strings
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using std::string;
using std::vector;

class Solution
{
public:
    int numSpecialEquivGroups(vector<string>& words)
    {
        std::unordered_set<std::string> hash;
        for (const std::string& s : words)
        {
            int size = s.size();
            std::string odd(size / 2 + (size & 1), '\0');
            std::string even(size / 2, '\0');

            for (int i = 0; i < size; ++i)
            {
                if (i & 1)
                    even[i / 2] = s[i];
                else
                    odd[i / 2] = s[i];
            }

            std::sort(odd.begin(), odd.end());
            std::sort(even.begin(), even.end());

            hash.insert(odd + even);
        }
        return hash.size();
    }
};
// @lc code=end

