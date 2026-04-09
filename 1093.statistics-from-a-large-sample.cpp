/*
 * @lc app=leetcode id=1093 lang=cpp
 *
 * [1093] Statistics from a Large Sample
 */

// @lc code=start
#include <vector>
#include <limits.h>

using std::vector;

using ll = long long;

class Solution
{
public:
    vector<double> sampleStats(vector<int>& count)
    {
        double min = INT_MAX;
        double max = INT_MIN;
        ll all = 0;
        ll sum = 0;
        int mode = 0;
        for (int i = 0; i < 256; ++i)
        {
            if (!count[i]) continue;

            sum += count[i];
            min = std::min(min, static_cast<double>(i));
            max = std::max(max, static_cast<double>(i));
            all += count[i] * static_cast<ll>(i);
            mode = (count[mode] > count[i] ? mode : i);
        }
        double average = static_cast<double>(all) / static_cast<double>(sum);
        ll mid = (sum + 1) / 2;
        double median1 = 0.0;
        double median2 = 0.0;

        bool odd = sum & 1;
        for (int i = 0; i < 256 && mid > 0; ++i)
        {
            mid -= count[i];
            if (mid <= 0)
            {
                if (odd || mid < 0)
                {
                    median1 = median2 = i;
                    break;
                }
                else
                {
                    median1 = i;
                    for (int j = i + 1; j < 256; ++j)
                    {
                        if (count[j])
                        {
                            median2 = j;
                            break;
                        }
                    }
                }
            }
        }

        return { min, max, average, (median1 + median2) / 2, static_cast<double>(mode) };
    }
};
// @lc code=end

