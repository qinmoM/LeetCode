/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
#include <string>

using std::string;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int size = dominoes.size();
        std::string temp = dominoes;
        for (int i = 0; i < size; )
        {
            if ('R' == dominoes[i])
            {
                int j = i + 1;
                while (j < size && '.' == dominoes[j]) ++j;
                if (j == size || 'R' == dominoes[j]) for (int n = i + 1; n < j; ++n) temp[n] = 'R';
                else
                {
                    int m = (i + j - 1) / 2;
                    for (int n = i + 1; n <= m; ++n) temp[n] = 'R';
                    for (int n = m + (((i + j) & 1) ? 1 : 2); n < j; ++n) temp[n] = 'L';
                }
                i = j;
            }
            else if ('L' == dominoes[i])
            {
                int j = i - 1;
                while (j >= 0 && '.' == dominoes[j]) --j;
                if (-1 == j || 'L' == dominoes[j]) for (int n = j + 1; n < i; ++n) temp[n] = 'L';
                ++i;
            }
            else ++i;
        }
        return temp;

        // if (1 >= dominoes.size()) return dominoes;
        // int size = dominoes.size();
        // int step = 1;
        // while (step)
        // {
        //     step = 0;
        //     std::string temp = dominoes;
        //     if ('.' == dominoes[0] && 'L' == dominoes[1])
        //     {
        //         temp[0] = 'L';
        //     }
        //     for (int i = 1; i < size - 1; ++i)
        //     {
        //         if ('.' != dominoes[i]) continue;
        //         if ('L' == dominoes[i + 1])
        //         {
        //             if ('R' != dominoes[i - 1])
        //             {
        //                 temp[i] = 'L';
        //                 ++step;
        //             }
        //         }
        //         else
        //         {
        //             if ('R' == dominoes[i - 1])
        //             {
        //                 temp[i] = 'R';
        //                 ++step;
        //             }
        //         }
        //     }
        //     if ('.' == dominoes[size - 1] && 'R' == dominoes[size - 2])
        //     {
        //         temp[size - 1] = 'R';
        //     }
        //     dominoes = temp;
        // }
        // return dominoes;

        // std::vector<int> vecL(dominoes.size(), 0);
        // std::vector<int> vecR(dominoes.size(), 0);
        // for (int i = 0; i < dominoes.size(); ++i)
        // {
        //     if (dominoes[i] == 'R') vecR[i] = 1;
        //     else if (dominoes[i] == '.') vecR[i] = (0 != i ? vecR[i - 1] + 1 : 0);
        // }
        // for (int i = dominoes.size() - 1; i >= 0; --i)
        // {
        //     if (dominoes[i] == 'L') vecL[i] = -1;
        //     else if (dominoes[i] == '.') vecL[i] = (dominoes.size() - 1 != i ? vecL[i + 1] - 1 : 0);
        // }
        // auto temp = vecR.end();
        // for (auto it = vecR.begin(); it != vecR.end(); ++it)
        // {
        //     if (0 != *(it))
        //     {
        //         if (vecR.end() == temp) temp = it;
        //     }
        //     else
        //     {
        //         if (vecR.end() != temp)
        //         {
        //             std::reverse(temp, it);
        //             temp == vecR.end();
        //         }
        //     }
        // }
        // if (vecR.end() != temp)
        // {
        //     std::reverse(temp, vecR.end());
        //     temp == vecR.end();
        // }
        // for (auto it = vecL.begin(); it != vecL.end(); ++it)
        // {
        //     if (0 != *(it))
        //     {
        //         if (vecL.end() == temp) temp = it;
        //     }
        //     else
        //     {
        //         if (vecL.end() != temp)
        //         {
        //             std::reverse(temp, it);
        //             temp == vecL.end();
        //         }
        //     }
        // }
        // if (vecL.end() != temp)
        // {
        //     std::reverse(temp, vecL.end());
        //     temp == vecL.end();
        // }
        // for (int i = 0; i < vecR.size(); ++i) vecR[i] = vecR[i] + vecL[i];
        // std::string result(vecR.size(), '.');
        // for (int i = 0; i < vecR.size(); ++i)
        // {
        //     if (vecR[i] > 0) result[i] = 'R';
        //     else if (vecR[i] < 0) result[i] = 'L';
        // }
        // return result;
    }
};
// @lc code=end

