/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        std::istringstream iss(s);
        std::string temp;
        std::unordered_map<char, std::string> hash;
        std::unordered_set<string> setHash;

        for (char c : pattern)
        {
            if (!(iss >> temp))
            {
                return false;
            }
            if (!hash.count(c))
            {
                if (setHash.find(temp) != setHash.end())
                {
                    return false;
                }
                hash[c] = temp;
                setHash.insert(temp);
            }
            else
            {
                if (hash[c] != temp)
                {
                    return false;
                }
            }
        }
        return !(iss >> temp);
    }
};
// @lc code=end

