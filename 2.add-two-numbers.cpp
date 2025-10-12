/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* temp1 = l1;
        ListNode* prev1 = nullptr;
        ListNode* temp2 = l2;
        ListNode* prev2 = nullptr;
        bool isCarry = false;
        while (temp1 && temp2)
        {
            int temp = temp1->val + temp2->val + isCarry;
            isCarry = temp / 10;
            temp1->val = temp % 10;
            prev1 = temp1;
            temp1 = temp1->next;
            prev2 = temp2;
            temp2 = temp2->next;
        }
        if (temp2)
        {
            prev1->next = temp2;
            temp1 = temp2;
        }
        while (temp1 && isCarry)
        {
            int temp = temp1->val + isCarry;
            isCarry = temp / 10;
            temp1->val = temp % 10;
            prev1 = temp1;
            temp1 = temp1->next;
        }
        if (isCarry)
        {
            prev1->next = new ListNode(1);
        }
        return l1;
    }
};
// @lc code=end

