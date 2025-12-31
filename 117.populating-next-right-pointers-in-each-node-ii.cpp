/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
#ifndef NULL
#define NULL nullptr
#endif

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (!root) return nullptr;

        if (root->left)
            root->left->next = findNext(root, root->right);
        if (root->right)
            root->right->next = findNext(root, nullptr);

        connect(root->right);
        connect(root->left);

        return root;
    }

    Node* findNext(Node* root, Node* next)
    {
        while (!next)
        {
            if (!(root = root->next)) break;
            if (root->left) next = root->left;
            else if (root->right) next = root->right;
        }
        return next;
    }
};
// @lc code=end

