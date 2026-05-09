/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <string>

using std::string;

class Trie
{
public:
    struct Node
    {
        Node()
            : end_(false)
        {
            for (int i = 0; i < 26; ++i)
                next_[i] = nullptr;
        }

        Node* next_[26];
        bool end_;
    };

    Trie() : root_(new Node()) { }
    
    void insert(string word)
    {
        Node* curr = root_;

        for (char c : word)
        {
            if (nullptr == curr->next_[index(c)])
                curr->next_[index(c)] = new Node();

            curr = curr->next_[index(c)];
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
        return true;
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

