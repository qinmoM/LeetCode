/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* newHead1 = new ListNode(0, list1);
        ListNode* newHead2 = new ListNode(0, list2);
        list1 = newHead1;
        list2 = newHead2;
        while (list1->next)
        {
            if (!list2->next)
            {
                break;
            }

            if (list1->next->val > list2->next->val)
            {
                ListNode* temp = list1->next;
                list1->next = list2->next;
                list2->next = list2->next->next;
                list1->next->next = temp;
            }
            list1 = list1->next;
        }
        if (list2->next)
        {
            list1->next = list2->next;
        }
        list1 = newHead1->next;
        delete newHead1;
        delete newHead2;
        return list1;
    }
};
// @lc code=end

