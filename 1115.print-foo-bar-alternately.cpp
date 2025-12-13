/*
 * @lc app=leetcode id=1115 lang=cpp
 *
 * [1115] Print FooBar Alternately
 */

// @lc code=start
#include <functional>
#include <mutex>
#include <condition_variable>

using std::function;

class FooBar
{
private:
    std::mutex mu_;
    std::condition_variable cv_;
    int n;
    bool isFoo_;

public:
    FooBar(int n) : isFoo_(true)
    {
        this->n = n;
    }

    void foo(function<void()> printFoo)
    {
        
        for (int i = 0; i < n; i++)
        {
            {
                std::unique_lock lock(mu_);
                cv_.wait(lock, [this]() -> bool { return isFoo_; });
        	    // printFoo() outputs "foo". Do not change or remove this line.
        	    printFoo();
                isFoo_ = false;
            }
            cv_.notify_one();
        }
    }

    void bar(function<void()> printBar)
    {
        
        for (int i = 0; i < n; i++)
        {
            {
                std::unique_lock lock(mu_);
                cv_.wait(lock, [this]() -> bool { return !isFoo_; });
        	    // printBar() outputs "bar". Do not change or remove this line.
        	    printBar();
                isFoo_ = true;
            }
            cv_.notify_one();
        }
    }
};
// @lc code=end

