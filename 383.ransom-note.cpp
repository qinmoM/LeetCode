/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (magazine.size() < ransomNote.size())
        {
            return false;
        }
        std::unordered_map<char, int> hash;
        for (char c : magazine)
        {
            ++hash[c];
        }
        for (char c : ransomNote)
        {
            if (hash[c])
            {
                --hash[c];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

