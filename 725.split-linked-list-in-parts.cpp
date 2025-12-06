/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

#include <vector>

using std::vector;

class Solution
{
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        int count = 0;
        ListNode* curr = head;
        while (curr)
        {
            ++count;
            curr = curr->next;
        }
        int gap = count / k;
        int temp = count % k;
        std::vector<int> nums(k, gap);
        for (int i = 0; i < k; ++i)
        {
            if (temp)
            {
                nums[i] += 1;
                --temp;
            }
        }
        std::vector<ListNode*> result(k, nullptr);
        curr = head;
        for (int i = 0; i < k; ++i)
        {
            result[i] = curr;
            while (nums[i]--)
            {
                if (!nums[i])
                {
                    ListNode* t = curr;
                    curr = curr->next;
                    t->next = nullptr;
                }
                else curr = curr->next;
            }
        }
        return result;
    }
};
// @lc code=end

