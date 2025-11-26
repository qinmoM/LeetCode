/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x)
    {
        if (!head || !head->next) return head;
        ListNode* newHead = new ListNode(0, head);
        ListNode* curr = newHead;
        ListNode* less = nullptr;
        ListNode* lessCurr = nullptr;
        while (curr->next)
        {
            if (curr->next->val < x)
            {
                if (!less)
                {
                    less = curr->next;
                    lessCurr = less;
                }
                else
                {
                    lessCurr->next = curr->next;
                    lessCurr = lessCurr->next;
                }
                curr->next = curr->next->next;
                lessCurr->next = nullptr;
            }
            else curr = curr->next;
        }
        if (less)
        {
            lessCurr->next = newHead->next;
            newHead->next = less;
        }
        head = newHead->next;
        delete newHead;
        return head;

        // ListNode* newHead = new ListNode(0, head);
        // ListNode* curr = newHead;
        // ListNode* equal = nullptr;
        // ListNode* equalCurr = nullptr;
        // ListNode* greater = nullptr;
        // ListNode* greaterCurr = nullptr;
        // while (curr->next)
        // {
        //     if (curr->next->val > x)
        //     {
        //         if (!greater) greater = curr->next;
        //         greaterCurr = curr->next;
        //         curr->next = curr->next->next;
        //         greaterCurr->next = nullptr;
        //     }
        //     else if (curr->next->val == x)
        //     {
        //         if (!equal) equal = curr->next;
        //         equalCurr = curr->next;
        //         curr->next = curr->next->next;
        //         equalCurr->next = nullptr;
        //     }
        //     else curr = curr->next;
        // }
        // curr->next = equal;
        // equalCurr->next = greater;
        // head = newHead->next;
        // delete newHead;
        // return head;
    }
};
// @lc code=end

