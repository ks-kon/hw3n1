#include <iostream>
#include <random>
#include <set>
#include <vector>
#include <chrono>


class Timer
{
public:
    using clock_t = std::chrono::steady_clock;
    using time_point_t = clock_t::time_point;
    Timer() : m_begin(clock_t::now()) {};
    ~Timer()
    {
        auto end = clock_t::now();
        std::cout << "micro " << std::chrono::duration_cast <std::chrono::microseconds> (end - m_begin).count() << std::endl;
    }
private:
    time_point_t m_begin;
};


int main()
{
    std::set <int> s;
    int N = 100;
    {
        Timer t;
        for (auto i = 0; i < N; ++i)
        {
            s.insert(std::rand());
        }
    }

    std::vector <int> v;
    {
        Timer t;
        std::rand();
        for (auto i : s)
        {
            v.push_back(i);
        }
        std::sort(v.begin(), v.end());
    }

    //vector is faster N = 100, 10000, 1000000



	return EXIT_SUCCESS;
}