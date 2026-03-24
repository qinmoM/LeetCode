/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        std::vector<std::string> result;
        dfs(0, s, result);
        return result;
    }

    void dfs(int index, std::string& s, std::vector<std::string>& result)
    {
        if (index >= s.size())
            return result.push_back(s);

        if (!letter(s[index]))
        {
            return dfs(index + 1, s, result);
        }
        dfs(index + 1, s, result);
        s[index] = transform(s[index]);
        dfs(index + 1, s, result);
        s[index] = transform(s[index]);
    }

    char transform(char a)
    {
        if (a >= 'A' && a <= 'Z')
            return a - 'A' + 'a';
        
        return a - 'a' + 'A';
    }

    bool letter(char a)
    {
        return a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z';
    }
};
// @lc code=end

