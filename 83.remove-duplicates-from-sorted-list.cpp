/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* curr = head;
        while (nullptr != curr && nullptr != curr->next)
        {
            if (curr->next->val == curr->val)
            {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};
// @lc code=end

