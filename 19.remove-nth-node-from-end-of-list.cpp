/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head->next == nullptr)
        {
            delete head;
            return nullptr;
        }
        ListNode* result = head;
        ListNode* curr = head;
        while (n--)
        {
            curr = curr->next;
        }
        while (nullptr != curr && nullptr != curr->next)
        {
            curr = curr->next;
            result = result->next;
        }
        if (curr == nullptr)
        {
            curr = head->next;
            delete head;
            return curr;
        }
        curr = result->next;
        result->next = curr->next;
        delete curr;
        return head;
    }
};
// @lc code=end

