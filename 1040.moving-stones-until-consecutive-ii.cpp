/*
 * @lc app=leetcode id=1040 lang=cpp
 *
 * [1040] Moving Stones Until Consecutive II
 */

// @lc code=start
// #include <set>
#include <vector>
#include <limits.h>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<int> numMovesStonesII(vector<int>& stones)
    {
        std::sort(stones.begin(), stones.end());
        int n = stones.size();
        
        int max = std::max(
            stones[n - 1] - stones[1] - n + 2,
            stones[n - 2] - stones[0] - n + 2
        );

        // std::set<int> tree;
        // for (int i : stones)
        //     tree.insert(i);
        //
        // std::vector<int> res(2, 0);
        // res[0] = INT_MAX;
        // dfs(0, tree, res);
        // return res;
    }

    // void dfs(int count, std::set<int>& tree, std::vector<int>& res)
    // {
    //     bool trigger = false;
    //
    //     int temp = *tree.begin();
    //     tree.erase(temp);
    //     for (int i = *tree.begin() + 1; i < *--tree.end(); ++i)
    //     {
    //         auto itTemp = tree.find(i);
    //         if (itTemp != tree.end())
    //             continue;
    //
    //         trigger = true;
    //         tree.insert(i);
    //         dfs(count + 1, tree, res);
    //         tree.erase(i);
    //     }
    //     tree.insert(temp);
    //
    //     temp = *(--tree.end());
    //     tree.erase(temp);
    //     for (int i = *tree.begin() + 1; i < *--tree.end(); ++i)
    //     {
    //         auto itTemp = tree.find(i);
    //         if (itTemp != tree.end())
    //             continue;
    //
    //         trigger = true;
    //         tree.insert(i);
    //         dfs(count + 1, tree, res);
    //         tree.erase(i);
    //     }
    //     tree.insert(temp);
    //
    //     if (!trigger)
    //     {
    //         res[0] = std::min(res[0], count);
    //         res[1] = std::max(res[1], count);
    //     }
    // }
};
// @lc code=end

