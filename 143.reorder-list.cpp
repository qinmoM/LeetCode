/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head)
    {
        if (!head->next || !head->next->next) return;
        ListNode* newHead = new ListNode(0, head);
        ListNode* fast = newHead;
        ListNode* slow = newHead;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow = fast->next;
        fast->next = nullptr;
        ListNode* backHead = new ListNode(0, nullptr);
        ListNode* slowHead = new ListNode(0, slow);
        while (slowHead->next)
        {
            ListNode* temp = backHead->next;
            backHead->next = slowHead->next;
            slowHead->next = slowHead->next->next;
            backHead->next->next = temp;
        }
        delete slowHead;
        slow = head;
        while (backHead->next)
        {
            ListNode* temp = slow->next;
            slow->next = backHead->next;
            backHead->next = backHead->next->next;
            slow->next->next = temp;
            slow = temp;
        }
        delete backHead;
        delete newHead;
    }
};
// @lc code=end

