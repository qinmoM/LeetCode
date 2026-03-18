/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <map>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        std::vector<int> pass(n, INT_MAX);
        pass[k - 1] = 0;

        std::unordered_map<int, std::vector<std::pair<int, int>>> hash;
        for (std::vector<int>& vec : times)
            hash[vec[0]].emplace_back(std::pair<int, int>(vec[1], vec[2]));

        std::multimap<int, std::pair<int, int>> queue;
        for (std::pair<int, int>& pair : hash[k])
            queue.emplace(pair.second, std::pair<int, int>(k, pair.first)); 
        
        while (queue.size())
        {
            std::pair<int, std::pair<int, int>> temp = *(queue.begin());
            queue.erase(queue.begin());
            for (std::pair<int, int>& pair : hash[temp.second.first])
                pass[temp.second.second - 1] = std::min(pass[temp.second.second - 1], temp.first + pass[temp.second.first - 1]);

            for (std::pair<int, int>& pair : hash[temp.second.second])
                queue.emplace(pair.second, std::pair<int, int>(temp.second.second, pair.first));

            for (std::multimap<int, std::pair<int, int>>::iterator it = queue.begin(); it != queue.end(); )
            {
                if (pass[it->second.second - 1] != INT_MAX)
                    it = queue.erase(it);
                else
                    ++it;
            }
        }

        auto it = std::max_element(pass.begin(), pass.end());
        return *(it) == INT_MAX ? -1 : *(it);
    }
};
// @lc code=end

