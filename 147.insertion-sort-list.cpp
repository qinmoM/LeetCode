/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head)
    {
        if (!head->next) return head;
        ListNode* newHead = new ListNode(0, head->next);
        ListNode* sortHead = new ListNode(0, head);
        head->next = nullptr;
        while (newHead->next)
        {
            ListNode* temp = newHead->next;
            newHead->next = newHead->next->next;
            ListNode* curr = sortHead;
            while (curr->next && temp->val > curr->next->val) curr = curr->next;
            temp->next = curr->next;
            curr->next = temp;
        }
        head = sortHead->next;
        delete sortHead;
        delete newHead;
        return head;
    }
};
// @lc code=end

