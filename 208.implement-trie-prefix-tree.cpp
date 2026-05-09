/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <vector>
#include <string>

using std::string;

class Trie
{
public:
    struct Node
    {
        Node() : next_(26, nullptr), end_(false), pass_(false) { }

        std::vector<Node*> next_;
        bool end_;
        bool pass_;
    };

    Trie() : root_(new Node()) { }
    
    void insert(string word)
    {
        Node* curr = root_;
        curr->pass_ = true;

        for (char c : word)
        {
            if (nullptr == curr->next_[index(c)])
                curr->next_[index(c)] = new Node();

            curr = curr->next_[index(c)];
            curr->pass_ = true;
        }

        curr->end_ = true;
    }
    
    bool search(string word)
    {
        Node* curr = root_;

        for (char c : word)
        {
            curr = curr->next_[index(c)];
            if (nullptr == curr)
                return false;
        }
        return true == curr->end_;
    }
    
    bool startsWith(string prefix)
    {
        Node* curr = root_;

        for (char c : prefix)
        {
            curr = curr->next_[index(c)];
            if (nullptr == curr)
                return false;
        }
        return true == curr->pass_;
    }
private:
    int index(char c)
    {
        return c - 'a';
    }

    Node* root_;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

