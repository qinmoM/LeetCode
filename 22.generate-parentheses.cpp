/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        // std::vector<std::string> result;
        // parent(result, 2, n, "()", true);
        // return result;
    }

    // void parent(std::vector<std::string>& result, const int level, const int target, std::string word, bool notNest = false)
    // {
    //     if (level > target)
    //     {
    //         result.push_back(word);
    //         return;
    //     }
    //
    //     parent(result, level + 1, target, "(" + word + ")");
    //     parent(result, level + 1, target, "()" + word, true);
    //     if (!notNest)
    //     {
    //         parent(result, level + 1, target, word + "()");
    //     }
    // }

};
// @lc code=end

