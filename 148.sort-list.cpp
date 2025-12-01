/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next) return head;

        ListNode* newHead = new ListNode(0, head);
        ListNode* fast = newHead;
        ListNode* slow = newHead;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        delete newHead;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left, right);
    }

    ListNode* merge(ListNode* node1, ListNode* node2)
    {
        ListNode* head = new ListNode(0, nullptr);
        ListNode* curr = head;
        while (node1 && node2)
        {
            if (node1->val > node2->val)
            {
                curr->next = node2;
                node2 = node2->next;
            }
            else
            {
                curr->next = node1;
                node1 = node1->next;
            }
            curr = curr->next;
        }
        curr->next = (node1 ? node1 : node2);
        ListNode* h = head->next;
        delete head;
        return h;
    }
};
// @lc code=end

