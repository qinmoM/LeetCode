/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head)
    {
        int size = 0;
        ListNode* curr = head;
        while (curr)
        {
            ++size;
            curr = curr->next;
        }
        if (0 == size || 1 == size)
        {
            return true;
        }
        curr = head;

        ListNode* newHead = new ListNode(0, head);
        int gap = (size + 1) / 2 - 1;
        while (gap)
        {
            curr = curr->next;
            --gap;
        }
        while (curr->next)
        {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = newHead->next;
            newHead->next = temp;
        }
        curr = newHead->next;
        gap = size / 2;
        while (gap)
        {
            if (curr->val == head->val)
            {
                head = head->next;
                curr = curr->next;
            }
            else
            {
                return false;
            }
            --gap;
        }
        return true;

        // int size = 0;
        // ListNode* curr = head;
        // while (curr)
        // {
        //     curr = curr->next;
        //     ++size;
        // }
        // if (0 == size || 1 == size)
        // {
        //     return true;
        // }
        // curr = head;
        // std::stack<int> s;
        // bool isOddCenter = size & 1;
        // for (int i = 0; i < size; ++i)
        // {
        //     if (size / 2 > i)
        //     {
        //         s.push(curr->val);
        //         curr = curr->next;
        //     }
        //     else
        //     {
        //         if (s.empty())
        //         {
        //             return false;
        //         }
        //         if (isOddCenter)
        //         {
        //             curr = curr->next;
        //             isOddCenter = false;
        //             continue;
        //         }
        //         if (s.top() == curr->val)
        //         {
        //             curr = curr->next;
        //             s.pop();
        //         }
        //         else
        //         {
        //             return false;
        //         }
        //     }
        // }
        // return true;
    }
};
// @lc code=end

