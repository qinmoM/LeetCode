/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int area = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right)
        {
            area = std::max(area, std::min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
            {
                int temp = left;
                while (left < right && height[left] <= height[temp]) ++left;
                continue;
            }
            if (height[left] > height[right])
            {
                int temp = right;
                while (left < right && height[right] <= height[temp]) --right;
                continue;
            }
            int leftCurr = left;
            int rightCurr = right;
            while (leftCurr < right && height[leftCurr] <= height[left]) ++leftCurr;
            while (left < rightCurr && height[rightCurr] <= height[right]) --rightCurr;
            if (right - rightCurr > leftCurr - left)
            {
                left = leftCurr;
            }
            else
            {
                right = rightCurr;
            }
        }
        return area;

        // int area = 0;
        // for (int i = 0; i < height.size() - 1; ++i)
        // {
        //     for (int j = i + 1; j < height.size(); ++j)
        //     {
        //         area = std::max(area, std::min(height[i], height[j]) * (j - i));
        //     }
        // }
        // return area;
    }
};
// @lc code=end

