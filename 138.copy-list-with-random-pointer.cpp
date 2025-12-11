/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Node
// {
// public:
//     int val;
//     Node* next;
//     Node* random;
//     Node(int _val)
//     {
//         val = _val;
//         next = nullptr;
//         random = nullptr;
//     }
// };

#include <unordered_map>

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if (!head) return head;

        std::unordered_map<Node*, Node*> hash;
        Node* curr = head;
        Node* newHead = nullptr;
        Node* newCurr = nullptr;
        while (curr)
        {
            if (!newCurr)
            {
                newHead = new Node(curr->val);
                newCurr = newHead;
            }
            else
            {
                newCurr->next = new Node(curr->val);
                newCurr = newCurr->next;
            }
            hash[curr] = newCurr;
            curr = curr->next;
        }

        curr = head;
        newCurr = newHead;
        while (curr)
        {
            if (curr->random)
            {
                newCurr->random = hash[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};
// @lc code=end

