/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int count = s.length() / 2 / k;
        for (int i = 0; i < count; ++i)
        {
            reverse(s, i * k * 2, i * k * 2 + k - 1);
        }
        if (s.length() % (k * 2))
        {
            reverse(s, count * k * 2, std::min(static_cast<int>(s.length()), k + count * k * 2) - 1);
        }
        return s;
    }

    void reverse(std::string& s, int left, int right)
    {
        while (left < right)
        {
            std::swap(s[left++], s[right--]);
        }
    }
};
// @lc code=end

