/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using std::vector;

class Twitter
{
public:
    Twitter()
        : times_(0)
    { }
    
    void postTweet(int userId, int tweetId)
    {
        root_[userId].second.push_back({ getTimes(), tweetId });
    }
    
    vector<int> getNewsFeed(int userId)
    {
        std::vector<int> vec;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;

        for (const std::pair<int, int>& pair : root_[userId].second)
            choice(heap, pair);

        for (int i : root_[userId].first)
        {
            for (const std::pair<int, int>& pair : root_[i].second)
                choice(heap, pair);
        }

        for (int i = 0; i < 10 && !heap.empty(); ++i)
        {
            vec.push_back(heap.top().second);
            heap.pop();
        }
        std::reverse(vec.begin(), vec.end());
        return vec;
    }
    
    void follow(int followerId, int followeeId)
    {
        root_[followerId].first.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        auto it = root_.find(followerId);

        if (it == root_.end()) return;

        it->second.first.erase(followeeId);
    }

private:
    void choice(std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>& heap, const std::pair<int, int>& pair)
    {
        if (heap.size() < 10)
            return heap.push(pair);

        if (heap.top() < pair)
        {
            heap.pop();
            heap.push(pair);
        }
    }

    int getTimes() { return times_++; }

private:
    std::unordered_map<int, std::pair<std::set<int>, std::vector<std::pair<int, int>>>> root_;
    int times_;

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

