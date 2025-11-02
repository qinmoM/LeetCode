/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        if (rec1[0] == rec2[0] && rec1[1] == rec2[1] && rec1[2] == rec2[2] && rec1[3] == rec2[3])
        {
            return true;
        }
        if (((rec1[0] > rec2[0] && rec1[0] < rec2[2]) || (rec1[2] > rec2[0] && rec1[2] < rec2[2]) ||
             (rec2[0] > rec1[0] && rec2[0] < rec1[2]) || (rec2[2] > rec1[0] && rec2[2] < rec1[2]))&&
            ((rec1[1] > rec2[1] && rec1[1] < rec2[3]) || (rec1[3] > rec2[1] && rec1[3] < rec2[3]) ||
             (rec2[1] > rec1[1] && rec2[1] < rec1[3]) || (rec2[3] > rec1[1] && rec2[3] < rec1[3])) )
        {
            return true;
        }
        return false;

        // if (rec1[0] == rec2[0] && rec1[1] == rec2[1] && rec1[2] == rec2[2] && rec1[3] == rec2[3])
        // {
        //     return true;
        // }
        // if (overlap(rec1, rec2[0], rec2[1]) || overlap(rec1, rec2[0], rec2[3]) ||
        //     overlap(rec1, rec2[2], rec2[1]) || overlap(rec1, rec2[2], rec2[3]) ||
        //     overlap(rec2, rec1[0], rec1[1]) || overlap(rec2, rec1[0], rec1[3]) ||
        //     overlap(rec2, rec1[2], rec1[1]) || overlap(rec2, rec1[2], rec1[3])  )
        // {
        //     return true;
        // }
        // return false;
    }

    // bool overlap(const std::vector<int>& vec, const int pointX, const int pointY)
    // {
    //     if (pointX > vec[0] && pointX < vec[2] && pointY < vec[3] && pointY > vec[1])
    //     {
    //         return true;
    //     }
    //     return false;
    // }

};
// @lc code=end

