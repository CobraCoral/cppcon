#include <chrono>
#include <utility>

using namespace std::chrono;
template <class F, class ... Args>
auto test(F f, Args&&... args)
{
    auto pre = high_resolution_clock::now();
    auto res = f(std::forward<Args>(args)...);
    auto post = high_resolution_clock::now();
    return make_pair(res, post - pre);
}
