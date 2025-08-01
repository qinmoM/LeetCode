/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string>& words)
    {
        vector<int> result(26, 0);
        int size = words.size();
        int length = words[0].length();
        for (int i = 0; i < length; ++i)
        {
            result[words[0][i] - 'a'] += 1;
        }

        for (int i = 1; i < size; ++i)
        {
            int lengthTemp = words[i].length();
            vector<int> temp(26, 0);
            for (int j = 0; j < lengthTemp; ++j)
            {
                temp[words[i][j] - 'a'] += 1;
            }
            for (int j = 0; j < 26; ++j)
            {
                result[j] = result[j] < temp[j] ? result[j] : temp[j];
            }
        }

        vector<string> last;
        for (int i = 0; i < 26; ++i)
        {
            while (0 != result[i])
            {
                string temp(1, 'a' + i);
                last.push_back(temp);
                --result[i];
            }
        }
        return last;
    
    }

};
// @lc code=end

