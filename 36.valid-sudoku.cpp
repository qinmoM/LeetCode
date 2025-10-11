/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        std::unordered_set<char> hash;
        for (const std::vector<char>& vec : board)
        {
            for (char c : vec)
            {
                if ('.' == c)
                {
                    continue;
                }
                if (hash.find(c) != hash.end())
                {
                    return false;
                }
                else
                {
                    hash.insert(c);
                }
            }
            hash.clear();
        }

        for (int i = 0; i < board[0].size(); ++i)
        {
            for (int j = 0; j < board.size(); ++j)
            {
                if ('.' == board[j][i])
                {
                    continue;
                }
                if (hash.find(board[j][i]) != hash.end())
                {
                    return false;
                }
                else
                {
                    hash.insert(board[j][i]);
                }
            }
            hash.clear();
        }

        for (int i = 0; i < 7; i += 3)
        {
            for (int j = 0; j < 7; j += 3)
            {
                for (int n = 0; n < 3; ++n)
                {
                    for (int m = 0; m < 3; ++m)
                    {
                        if ('.' == board[i + n][j + m])
                        {
                            continue;
                        }
                        if (hash.find(board[i + n][j + m]) != hash.end())
                        {
                            return false;
                        }
                        else
                        {
                            hash.insert(board[i + n][j + m]);
                        }
                    }
                }
                hash.clear();
            }
        }
        return true;
    }
};
// @lc code=end

