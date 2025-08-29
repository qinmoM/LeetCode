/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    int countSegments(string s)
    {
        int count = 0;
        std::istringstream iss(s);
        std::string word;
        while (iss >> word)
        {
            ++count;
        }
        return count;
    }
};
// @lc code=end

