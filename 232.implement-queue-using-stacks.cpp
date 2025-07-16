/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue
{
public:
    MyQueue()
    {
        
    }
    
    void push(int x)
    {
        s1.push(x);
    }
    
    int pop()
    {
        if (s2.empty())
        {
            if (s1.empty())
            {
                throw "error";
            }
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
    
    int peek()
    {
        if (s2.empty())
        {
            if (s1.empty())
            {
                throw "error";
            }
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        return s2.top();
    }
    
    bool empty()
    {
        return s1.empty() && s2.empty();
    }

protected:
    stack<int> s1;
    stack<int> s2;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

