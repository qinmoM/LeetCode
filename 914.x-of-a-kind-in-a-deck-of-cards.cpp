/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool hasGroupsSizeX(vector<int>& deck)
    {
        if (1 == deck.size())
        {
            return false;
        }
        std::unordered_map<int, int> hash;
        for (int i : deck)
        {
            ++hash[i];
        }
        int count = 0;
        for (std::pair<int, int> p : hash)
        {
            if (0 == count)
            {
                count = p.second;
            }
            else
            {
                if (p.second != count)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

