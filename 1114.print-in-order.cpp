/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

// @lc code=start
#include <functional>
#include <mutex>
#include <condition_variable>

using std::function;

class Foo
{
public:
    Foo() : level_(0) { }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mu_.lock();
        level_ = 1;
        mu_.unlock();
        cv_.notify_all();
    }

    void second(function<void()> printSecond)
    {
        std::unique_lock lock(mu_);
        cv_.wait(lock,
            [this]() -> bool
            {
                return 1 == level_;
            }
        );
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        level_ = 2;
        lock.unlock();
        cv_.notify_one();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock lock(mu_);
        cv_.wait(lock,
            [this]() -> bool
            {
                return 2 == level_;
            }
        );
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    int level_;
    std::condition_variable cv_;
    std::mutex mu_;
};
// @lc code=end

