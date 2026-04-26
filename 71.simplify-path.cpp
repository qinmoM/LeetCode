/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
#include <string>
#include <vector>

using std::string;

class Solution
{
public:
    string simplifyPath(string path)
    {
        std::vector<std::string> stack;
        std::string temp;

        path.push_back('/');
        for (char c : path)
        {
            if ('/' != c)
            {
                temp.push_back(c);
                continue;
            }

            if (temp.empty() || "." == temp)
            {
                temp.clear();
                continue;
            }

            if (".." == temp)
            {
                if (!stack.empty())
                    stack.pop_back();
            }
            else
            {
                stack.push_back(temp);
            }

            temp.clear();
        }

        std::string res;
        for (const std::string& s : stack)
            res += '/' + s;

        return (res.empty() ? "/" : res);
    }
};
// @lc code=end

