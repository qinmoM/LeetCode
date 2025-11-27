/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (left == right) return head;
        ListNode* newHead = new ListNode(0, head);
        ListNode* curr = newHead;
        ListNode* temp = new ListNode(0, nullptr);
        ListNode* tempTail = nullptr;
        int i = 1;
        while (i <= right)
        {
            if (i < left) curr = curr->next;
            else
            {
                ListNode* t = curr->next;
                curr->next = curr->next->next;
                t->next = temp->next;
                temp->next = t;
                if (!tempTail) tempTail = t;
            }
            ++i;
        }
        tempTail->next = curr->next;
        curr->next = temp->next;
        head = newHead->next;
        delete newHead;
        delete temp;
        return head;
    }
};
// @lc code=end

