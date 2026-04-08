/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
#include <vector>
#include <string>

using std::string;

class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        std::vector<int> hash(26, 0);
        for (char c : tiles)
            ++hash[c - 'A'];

        return dfs(hash);
    }

    int dfs(std::vector<int>& hash)
    {
        int res = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (0 == hash[i]) continue;

            --hash[i];
            res += 1 + dfs(hash);
            ++hash[i];
        }
        return res;
    }
};
// @lc code=end

