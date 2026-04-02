/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using std::vector;

class Solution
{
public:
    int totalFruit(vector<int>& fruits)
    {
        int size = fruits.size(), left = 0, right = 0, count = 1;
        int result = count;
        std::unordered_map<int, int> hash;
        ++hash[fruits[right]];

        while (right < size - 1)
        {
            ++count;
            ++hash[fruits[++right]];

            while (hash.size() == 3)
            {
                --count;
                auto it = hash.find(fruits[left++]);
                (*it).second -= 1;
                if ((*it).second == 0)
                    hash.erase(it);
            }

            result = std::max(result, count);
        }

        return result;
    }
};
// @lc code=end

