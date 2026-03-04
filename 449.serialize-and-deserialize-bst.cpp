/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #ifndef NULL
// #define NULL nullptr
// #endif

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

#include <string>
#include <vector>
#include <sstream>

using std::string;

class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        std::stringstream data;
        serialize(root, data);
        return data.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        std::vector<int> vec;
        std::stringstream ss(data);
        std::string temp;
        while (getline(ss, temp, ','))
        {
            if (!temp.empty())
                vec.push_back(std::stoi(temp));
        }
        int index = 0;
        return deserialize(vec, index);
    }
private:
    void serialize(TreeNode* node, std::stringstream& data)
    {
        if (!node)
        {
            data << std::to_string(10001) << ",";
            return;
        }
        data << std::to_string(node->val) << ",";

        serialize(node->left, data);
        serialize(node->right, data);
    }

    TreeNode* deserialize(const std::vector<int>& data, int& index)
    {
        if (index >= data.size() || data[index] == 10001)
        {
            ++index;
            return nullptr;
        }

        TreeNode* node = new TreeNode(data[index++]);

        node->left = deserialize(data, index);
        node->right = deserialize(data, index);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

