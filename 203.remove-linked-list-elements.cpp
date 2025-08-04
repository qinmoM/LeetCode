/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* temp = new ListNode(0, head);
        ListNode* curr = head;
        ListNode* last = temp;
        while (nullptr != curr)
        {
            if (val == curr->val)
            {
                curr = deleteNextNode(last);
            }
            else
            {
                last = curr;
                curr = curr->next;
            }
        }
        ListNode* newNode = temp->next;
        delete temp;
        return newNode;
    }

    ListNode* deleteNextNode(ListNode* node)
    {
        ListNode* curr = node->next;
        node->next = curr->next;
        delete curr;
        return node->next;
    }

};
// @lc code=end

