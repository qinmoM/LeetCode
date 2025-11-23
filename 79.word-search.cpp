/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        std::vector<std::vector<bool>> exist(board.size(), std::vector<bool>(board[0].size(), false));
        bool result = false;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (word[0] == board[i][j])
                {
                    exist[i][j] = true;
                    recursion(board, exist, result, word.substr(1, word.size() - 1), i, j);
                    if (result) return result;
                    exist[i][j] = false;
                }
            }
        }
        return result;
    }

    void recursion(const std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& exist
        , bool& result, std::string word, int x, int y)
    {
        if (!word.size())
        {
            result = true;
            return;
        }

        if (0 != x && board[x - 1][y] == word[0] && !exist[x - 1][y])
        {
            exist[x - 1][y] = true;
            recursion(board, exist, result, word.substr(1, word.size() - 1), x - 1, y);
            if (result) return;
            exist[x - 1][y] = false;
        }
        if (0 != y && board[x][y - 1] == word[0] && !exist[x][y - 1])
        {
            exist[x][y - 1] = true;
            recursion(board, exist, result, word.substr(1, word.size() - 1), x, y - 1);
            if (result) return;
            exist[x][y - 1] = false;
        }
        if (board.size() - 1 != x && board[x + 1][y] == word[0] && !exist[x + 1][y])
        {
            exist[x + 1][y] = true;
            recursion(board, exist, result, word.substr(1, word.size() - 1), x + 1, y);
            if (result) return;
            exist[x + 1][y] = false;
        }
        if (board[0].size() - 1 != y && board[x][y + 1] == word[0] && !exist[x][y + 1])
        {
            exist[x][y + 1] = true;
            recursion(board, exist, result, word.substr(1, word.size() - 1), x, y + 1);
            if (result) return;
            exist[x][y + 1] = false;
        }
    }

};
// @lc code=end

