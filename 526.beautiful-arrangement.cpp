/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    int countArrangement(int n)
    {
        std::vector<int> vec(n);
        for (int i = 0; i < n; ++i)
        {
            vec[i] = i + 1;
        }
        int count = 0;
        recursion(vec, count, 0);
        return count;
    }

    void recursion(std::vector<int>& vec, int& count, int index)
    {
        if (index == vec.size())
        {
            ++count;
            return;
        }

        int curr = index + 1;
        for (int i = index; i < vec.size(); i += 1)
        {
            if (!(vec[i] % curr == 0 || curr % vec[i] == 0)) continue;
            std::swap(vec[index], vec[i]);
            recursion(vec, count, curr);
            std::swap(vec[index], vec[i]);
        }
    }

};
// @lc code=end

