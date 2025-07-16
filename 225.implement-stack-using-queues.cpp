/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack
{
public:
    MyStack()
        : isQ1(true)
    {
        
    }
    
    void push(int x)
    {
        if (isQ1)
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }
    
    int pop()
    {
        isQ1 =! isQ1;
        if (!isQ1)
        {
            if (q1.empty())
            {
                throw "error";
            }

            int temp = 0;
            while (true)
            {
                temp = q1.front();
                q1.pop();
                if (q1.empty())
                {
                    return temp;
                }
                q2.push(temp);
            }
        }
        else
        {
            if (q2.empty())
            {
                throw "error";
            }

            int temp = 0;
            while (true)
            {
                temp = q2.front();
                q2.pop();
                if (q2.empty())
                {
                    return temp;
                }
                q1.push(temp);
            }
        }
    }
    
    int top()
    {
        isQ1 =! isQ1;
        if (!isQ1)
        {
            if (q1.empty())
            {
                throw "error";
            }

            int temp = 0;
            while (true)
            {
                temp = q1.front();
                q1.pop();
                q2.push(temp);
                if (q1.empty())
                {
                    return temp;
                }
            }
        }
        else
        {
            if (q2.empty())
            {
                throw "error";
            }

            int temp = 0;
            while (true)
            {
                temp = q2.front();
                q2.pop();
                q1.push(temp);
                if (q2.empty())
                {
                    return temp;
                }
            }
        }
    }
    
    bool empty()
    {
        return q1.empty() && q2.empty();
    }

protected:
    std::queue<int> q1;
    std::queue<int> q2;
    bool isQ1;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

