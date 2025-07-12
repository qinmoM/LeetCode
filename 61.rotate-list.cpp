/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (nullptr == head)
        {
            return head;
        }
        int Size = size(head); // O(n)
        k %= Size;
        if (0 == k)
        {
            return head;
        }
        ListNode* curr = head; // O(n)
        ListNode* temp = head;
        while (k--)
        {
            curr = curr->next;
        }
        while (nullptr != curr->next)
        {
            curr = curr->next;
            temp = temp->next;
        }
        curr->next = head;
        head = temp->next;
        temp->next = nullptr;
        return head;
        // if (0 == k || nullptr == head || nullptr == head->next)
        // {
        //     return head;
        // }
        //
        // ListNode* curr = head;
        // ListNode* last = nullptr;
        // int size = 0;
        // while (nullptr != curr)
        // {
        //     if (last == nullptr)
        //     {
        //         last = head;
        //     }
        //     else
        //     {
        //         last = last->next;
        //     }
        //     curr = curr->next;
        //     size++;
        //     if (k == size)
        //     {
        //         last->next = nullptr;
        //         ListNode* temp = curr;
        //         while (nullptr != temp->next)
        //         {
        //             temp = temp->next;
        //         }
        //         temp->next = head;
        //         head = curr;
        //         return head;
        //     }
        // }
        //
        // k %= size;
        // curr = head;
        // if (0 == k)
        // {
        //     return head;
        // }
        //
        // while (k)
        // {
        //     curr = curr->next;
        //     k--;
        // }
        // return head;
    }

    int size(ListNode* head)
    {
        int size = 0;
        while (nullptr != head)
        {
            size++;
            head = head->next;
        }
        return size;
    }
};
// @lc code=end

