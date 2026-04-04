/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        std::vector<int> uni(edges.size() + 1, 0);
        for (int i = 0; i < uni.size(); ++i)
            uni[i] = i;

        for (const std::vector<int>& vec : edges)
        {
            if (find(uni, vec[0]) == find(uni, vec[1]))
                return vec;

            merge(uni, vec[0], vec[1]);
        }

        return {};
    }

    void merge(std::vector<int>& vec, int x, int y)
    {
        int rx = find(vec, x);
        int ry = find(vec, y);

        if (rx == ry) return;

        vec[rx] = ry;
    }

    int find(std::vector<int>& vec, int x)
    {
        if (vec[x] != x)
            vec[x] = find(vec, vec[x]);

        return vec[x];
    }
};
// @lc code=end

