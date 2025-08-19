/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        std::unordered_map<int, int> hash;
        for (int i : arr1)
        {
            if (hash.find(i) == hash.end())
            {
                hash[i] = 1;
            }
            else
            {
                ++hash[i];
            }
        }

        std::vector<int> result;
        for (int i : arr2)
        {
            while (hash[i])
            {
                --hash[i];
                result.push_back(i);
            }
        }

        std::multiset<int> tempHash;
        for (std::pair<int, int> pair : hash)
        {
            while (pair.second)
            {
                tempHash.insert(pair.first);
                --pair.second;
            }
        }

        for (int i : tempHash)
        {
            result.push_back(i);
        }

        return result;
    }
};
// @lc code=end

