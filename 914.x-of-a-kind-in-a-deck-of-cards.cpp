/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution 
{
public:
    bool hasGroupsSizeX(vector<int>& deck)
    {
        std::unordered_map<int, int> hash;
        for (int i : deck)
        {
            ++hash[i];
        }
        int count = 0;
        for (const auto& [_, cnt] : hash)
        {
            count = std::gcd(count, cnt);
        }
        return count > 1;
    }
};
// @lc code=end

