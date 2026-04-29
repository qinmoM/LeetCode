/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using std::vector;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        std::sort(people.begin(), people.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) -> bool
            {
                return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
            }
        );

        std::vector<std::vector<int>> res;
        for (std::vector<int>& vec : people)
            res.insert(res.begin() + vec[1], vec);

        return res;

        // std::map<int, std::set<int>> tree;
        //
        // for (std::vector<int>& vec : people)
        // {
        //     tree[vec[0]].insert(vec[1]);
        //     vec[0] = -1;
        // }
        //
        // for (const std::pair<int, std::set<int>>& set : tree)
        // {
        //     int temp = 0;
        //     auto it = set.second.begin();
        //
        //     for (int i = 0; i < people.size() && it != set.second.end(); ++i)
        //     {
        //         if (-1 != people[i][0]) continue;
        //
        //         if (temp == *it)
        //         {
        //             people[i][0] = set.first;
        //             people[i][1] = *it;
        //             ++it;
        //         }
        //
        //         ++temp;
        //     }
        // }
        //
        // return people;
    }
};
// @lc code=end

