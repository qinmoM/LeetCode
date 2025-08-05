/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode* newHead = new ListNode(0, head);
        while (nullptr != head->next)
        {
            ListNode* temp = newHead->next;
            newHead->next = head->next;
            head->next = head->next->next;
            newHead->next->next = temp;
        }
        ListNode* durr = newHead->next;
        delete newHead;
        return durr;
    }

};
// @lc code=end

