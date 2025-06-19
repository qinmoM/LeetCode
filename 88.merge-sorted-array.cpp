/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count1 = m - 1, count2 = n - 1, countAll = m + n - 1;
        while (count2 >= 0)
        {
            if (count1 >= 0 && nums1[count1] >= nums2[count2])
            {
                nums1[countAll--] = nums1[count1--];
            }
            else
            {
                nums1[countAll--] = nums2[count2--];
            }
        }
    }
};
// @lc code=end

