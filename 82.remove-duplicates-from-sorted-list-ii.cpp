/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
//  struct ListNode
//  {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* newHead = new ListNode(0, head);
        ListNode* curr = newHead;
        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            if (curr->next->val == curr->next->next->val) duplicate(curr);
            else curr = curr->next;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }

    void duplicate(ListNode* node)
    {
        int target = node->next->val;
        while (node->next && node->next->val == target)
        {
            ListNode* temp = node->next;
            node->next = temp->next;
            delete temp;
        }
    }

};
// @lc code=end

