/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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

#include <iostream>

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int count1 = 0;
        int count2 = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        while (curr1)
        {
            ++count1;
            curr1 = curr1->next;
        }
        while (curr2)
        {
            ++count2;
            curr2 = curr2->next;
        }
        if (count2 > count1)
        {
            std::swap(count1, count2);
            std::swap(l1, l2);
        }
        ListNode* newl1 = new ListNode(0, l1);
        ListNode* newl2 = new ListNode(0, l2);
        int t = count1 - count2;
        while (t--) newl2 = new ListNode(0, newl2);
        add(newl1, newl2);
        if (!newl1->val)
        {
            ListNode* temp = newl1;
            newl1 = newl1->next;
            delete temp;
        }
        while (newl2 != l2)
        {
            ListNode* temp = newl2;
            newl2 = newl2->next;
            delete temp;
        }
        return newl1;
    }

    bool add(ListNode* l1, ListNode* l2)
    {
        if (!l1) return false;
        int carry = false;
        carry = add(l1->next, l2->next);
        int temp = l1->val + l2->val + (carry ? 1 : 0);
        l1->val = temp % 10;
        return temp / 10;
    }

};
// @lc code=end

