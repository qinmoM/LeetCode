/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
#include <string>
#include <unordered_map>

using std::string;

class WordDictionary
{
    struct Node
    {
        std::unordered_map<char, Node*> hash;
        bool has;
    };

    Node* root;

    bool search(const std::string& s, Node* node)
    {
        if (0 == s.size())
        {
            return node->has;
        }
        if ('.' == s[0])
        {
            for (const auto& [key, _] : node->hash)
            {
                if (search(s.substr(1, s.size() - 1), node->hash[key]))
                {
                    return true;
                }
            }
            return false;
        }
        if (node->hash.find(s[0]) == node->hash.end())
        {
            return false;
        }
        return search(s.substr(1, s.size() - 1), node->hash[s[0]]);
    }

public:
    WordDictionary()
    {
        root = new Node();
    }
    
    void addWord(string word)
    {
        Node* node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->hash.find(word[i]) == node->hash.end())
            {
                node->hash[word[i]] = new Node();
            }
            node = node->hash[word[i]];
        }
        node->has = true;
    }
    
    bool search(string word)
    {
        return search(word, root);
        // Node* node = root;
        // for (char c : word)
        // {
        //     if ('.' == c)
        //     {
        //         ;
        //     }
        //     if (node->hash.find(c) == node->hash.end())
        //     {
        //         return false;
        //     }
        //     node = node->hash[c];
        // }
        // return node->has;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

