/*
 * @lc app=leetcode id=1116 lang=cpp
 *
 * [1116] Print Zero Even Odd
 */

// @lc code=start
#include <functional>
#include <condition_variable>
#include <mutex>

using std::function;

class ZeroEvenOdd
{
private:
    std::mutex mu_;
    std::condition_variable cv_;
    int curr_;
    int n;
    bool zero_;

public:
    ZeroEvenOdd(int n) : curr_(1), zero_(true)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; ++i)
        {
            std::unique_lock<std::mutex> lock(mu_);
            cv_.wait(lock, [this, i]() -> bool { return zero_ && i == curr_; });
            printNumber(0);
            zero_ = false;
            cv_.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            std::unique_lock<std::mutex> lock(mu_);
            cv_.wait(lock, [this, i]() -> bool { return !zero_ && curr_ == i; });
            printNumber(i);
            zero_ = true;
            curr_ += 1;
            cv_.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            std::unique_lock<std::mutex> lock(mu_);
            cv_.wait(lock, [this, i]() -> bool { return !zero_ && curr_ == i; });
            printNumber(i);
            zero_ = true;
            curr_ += 1;
            cv_.notify_all();
        }
    }
};
// @lc code=end

