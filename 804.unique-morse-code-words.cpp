/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        std::vector<std::string> morse_code = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
        std::unordered_set<std::string> unique_morse_codes;
        for (std::string word : words)
        {
            std::string morsed_word;
            for (char c : word)
            {
                morsed_word += morse_code[c - 'a'];
            }
            unique_morse_codes.insert(morsed_word);
        }
        return unique_morse_codes.size();
    }
};
// @lc code=end

