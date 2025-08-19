/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        std::unordered_map<std::string, int> hash1;
        for (int i = 0; i < list1.size(); ++i)
        {
            hash1[list1[i]] = i;
        }
        
        std::vector<std::string> result;
        int min = INT_MAX;
        for (int i = 0; i < list2.size(); ++i)
        {
            if (hash1.find(list2[i]) != hash1.end())
            {
                int temp = i + hash1[list2[i]];
                if (temp > min)
                {
                    continue;
                }
                if (temp < min)
                {
                    min = temp;
                    result.clear();
                }
                result.push_back(list2[i]);
            }
        }
        return result;
    }
};
// @lc code=end

