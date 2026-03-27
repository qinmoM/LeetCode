#include <string>
#include <vector>
#include <algorithm>

using std::string;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        std::vector<char> custom(26, 0xff);
        for (int i = 0; i < order.size(); ++i)
            custom[order[i] - 'a'] = static_cast<char>(i);

        std::sort(s.begin(), s.end(),
            [&custom](const char& a, const char& b)
            {
                return custom[a - 'a'] > custom[b - 'a'];
            }
        );

        return s;
    }
};