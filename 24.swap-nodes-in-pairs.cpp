/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode* oddHead = head;
        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = head->next;
        while (nullptr != even && nullptr != odd)
        {
            if (nullptr != even)
            {
                odd->next = even->next;
                odd = odd->next;
            }
            if (nullptr != odd)
            {
                even->next = odd->next;
                even = even->next;
            }
        }
        odd = oddHead;
        even = evenHead;
        while (nullptr != even)
        {
            if (nullptr == even->next)
            {
                even->next = odd;
                break;
            }
            ListNode* temp = odd->next;
            odd->next = even->next;
            even->next = odd;
            even = odd->next;
            odd = temp;
        }
        return evenHead;
    }
};
// @lc code=end

