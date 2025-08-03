/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int sizeA = 0;
        int sizeB = 0;
        {
            ListNode* nodeA = headA;
            ListNode* nodeB = headB;
            while (NULL != nodeA)
            {
                ++sizeA;
                nodeA = nodeA->next;
            }
            while (NULL != nodeB)
            {
                ++sizeB;
                nodeB = nodeB->next;
            }
            int diff = std::abs(sizeA - sizeB);
            while (diff--)
            {
                if (sizeA > sizeB)
                {
                    headA = headA->next;
                }
                else
                {
                    headB = headB->next;
                }
            }
        }

        while (NULL != headA && NULL != headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
// @lc code=end

