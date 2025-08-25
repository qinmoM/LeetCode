/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words)
    {
        std::unordered_map<char, int> hash;
        for (char c : licensePlate)
        {
            if (c >= 'a' && c <= 'z')
            {
                ++hash[c];
            }
            else
            {
                if (c >= 'A' && c <= 'Z')
                {
                    ++hash[c - 'A' + 'a'];
                }
            }
        }

        std::string result;
        int count = 0;
        int size = 0;
        for (std::string word : words)
        {
            int tempCount = countStr(word, hash);
            if (tempCount > count || (tempCount == count && size > word.length()))
            {
                result = word;
                count = tempCount;
                size = word.length();
            }
        }
        return result;
    }

    int countStr(const std::string& word, std::unordered_map<char, int> map)
    {
        int count = 0;
        for (char c : word)
        {
            if (map.find(c) != map.end() || (c >= 'A' && c <= 'Z' && map.find(c - 'A' + 'a') != map.end()))
            {
                if (map[c])
                {
                    ++count;
                    --map[c];
                }
            }
        }
        return count;
    }

};
// @lc code=end

