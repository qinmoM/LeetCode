/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int>& candyType)
    {
        std::unordered_set<int> hash(candyType.begin(), candyType.end());
        return candyType.size() / 2 > hash.size() ? hash.size() : candyType.size() / 2;
    }
};
// @lc code=end

