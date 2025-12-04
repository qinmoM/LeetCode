/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode* evenHead = head->next;
        head->next = head->next->next;
        ListNode* oddLast = head;
        ListNode* oddCurr = head->next;
        ListNode* evenCurr = evenHead;
        while (oddCurr && oddCurr->next)
        {
            evenCurr->next = oddCurr->next;
            oddCurr->next = oddCurr->next->next;
            oddLast = oddCurr;
            oddCurr = oddCurr->next;
            evenCurr = evenCurr->next;
        }
        evenCurr->next = nullptr;
        if (oddCurr) oddCurr->next = evenHead;
        else oddLast->next = evenHead;
        return head;
    }
};
// @lc code=end

