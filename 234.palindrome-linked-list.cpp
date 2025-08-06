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
#include <stack>

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
            curr = curr->next;
            ++size;
        }
        if (0 == size || 1 == size)
        {
            return true;
        }
        curr = head;
        std::stack<int> s;
        bool isOddCenter = size & 1;
        for (int i = 0; i < size; ++i)
        {
            if (size / 2 > i)
            {
                s.push(curr->val);
                curr = curr->next;
            }
            else
            {
                if (s.empty())
                {
                    return false;
                }
                if (isOddCenter)
                {
                    curr = curr->next;
                    isOddCenter = false;
                    continue;
                }
                if (s.top() == curr->val)
                {
                    curr = curr->next;
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

