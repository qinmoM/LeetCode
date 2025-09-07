/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        std::unordered_map<char, int> hash(26);
        for (int i = 0; i < order.length(); ++i)
        {
            hash[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
            {
                if (words[i + 1].size() == j)
                {
                    return false;
                }
                int index0 = hash[words[i][j]];
                int index1 = hash[words[i + 1][j]];
                if (index0 > index1)
                {
                    return false;
                }
                if (index0 < index1)
                {
                    break;
                }
            }
        }
        return true;
    }
};
// @lc code=end

