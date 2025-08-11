/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 */

// @lc code=start
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> words;
        istringstream iss(text);
        string word;
        while (iss >> word)
        {
            words.push_back(word);
        }

        vector<string> result;
        for (int i = 2; i < words.size(); ++i)
        {
            if (words[i - 2] == first && words[i - 1] == second)
            {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
// @lc code=end

