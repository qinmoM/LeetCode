/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>

using std::string;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        std::vector<int> vecL(dominoes.size(), 0);
        std::vector<int> vecR(dominoes.size(), 0);
        for (int i = 0; i < dominoes.size(); ++i)
        {
            if (dominoes[i] == 'R') vecR[i] = 1;
            else if (dominoes[i] == '.') vecR[i] = (0 != i ? vecR[i - 1] + 1 : 0);
        }
        for (int i = dominoes.size() - 1; i >= 0; --i)
        {
            if (dominoes[i] == 'L') vecL[i] = -1;
            else if (dominoes[i] == '.') vecL[i] = (dominoes.size() - 1 != i ? vecL[i + 1] - 1 : 0);
        }
        auto temp = vecR.end();
        for (auto it = vecR.begin(); it != vecR.end(); ++it)
        {
            if (0 != *(it))
            {
                if (vecR.end() == temp) temp = it;
            }
            else
            {
                if (vecR.end() != temp)
                {
                    std::reverse(temp, it);
                    temp == vecR.end();
                }
            }
        }
        if (vecR.end() != temp)
        {
            std::reverse(temp, vecR.end());
            temp == vecR.end();
        }
        for (auto it = vecL.begin(); it != vecL.end(); ++it)
        {
            if (0 != *(it))
            {
                if (vecL.end() == temp) temp = it;
            }
            else
            {
                if (vecL.end() != temp)
                {
                    std::reverse(temp, it);
                    temp == vecL.end();
                }
            }
        }
        if (vecL.end() != temp)
        {
            std::reverse(temp, vecL.end());
            temp == vecL.end();
        }
        for (int i = 0; i < vecR.size(); ++i) vecR[i] = vecR[i] + vecL[i];
        std::string result(vecR.size(), '.');
        for (int i = 0; i < vecR.size(); ++i)
        {
            if (vecR[i] > 0) result[i] = 'R';
            else if (vecR[i] < 0) result[i] = 'L';
        }
        return result;
    }
};
// @lc code=end

