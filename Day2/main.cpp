#include <algorithm>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <sstream>


// template<typename OP>
// constexpr int is_safe(int a, int b, OP op)
// {
//     auto const val = std::abs(op(a,b));
//     return bool(val & 0x3) & !bool(val & ~0x3);
// }
template<typename OP>
constexpr int is_safe(int a, int b, OP op)
{
    auto const val = op(a,b);
    return int(val > 0 & val < 4);
}
constexpr int check_line(std::vector<int> const& vec)
{
    auto const op = (vec[0] - vec[1] > 0)
            ? [](int a, int b) { return a - b ; }
            : [](int a, int b) { return b - a; };
    for (auto it = std::next(vec.cbegin()); it != vec.cend(); ++it)
    {
        if (!is_safe(*std::prev(it), *it, op)) return 0;
    }
    return 1;
}
constexpr uint32_t check_line_counter(std::vector<int> const& vec)
{
    auto const op = (vec[0] - vec[1] > 0)
            ? [](int a, int b) { return a - b ; }
    : [](int a, int b) { return b - a; };
    uint32_t ret{};
    auto const start = std::next(vec.cbegin());
    auto const end = std::prev(vec.cend());
    for (auto it = start; it != vec.cend(); ++it)
    {
        auto const v = is_safe(*std::prev(it), *it, op) ^ 1;
        ret +=  v*int(&*it == &*start) + v + v*int(&*it == &*end);
    }
    return ret;
}
constexpr std::vector<int> make_vector(std::string const& s)
{
    std::vector<int> v;
    char c_str[400];
    std::strcpy(c_str, s.c_str());
    char *ptr = c_str, *start_of_word = c_str;
    while (*ptr != '\0')
    {
        if (*ptr == ' ')
        {
            *ptr = '\0';
            v.push_back(std::atoi(start_of_word));
            start_of_word = ptr + 1;
        }
        ++ptr;
    }
    v.push_back(std::atoi(start_of_word));
    return v;
}

int main()
{
    std::ifstream file("../../Day2/input.txt");
    std::string line;
    std::vector<std::vector<int>> lines;

    while (std::getline(file, line))
    {
       lines.push_back(std::move(make_vector(line)));
    }
    std::size_t count{}, count_part_two{};
    for (auto const& l : lines)
    {
        count += check_line(l);
    }
    std::cout << count << '\n';

    for (auto const& l : lines)
    {
        count_part_two += std::size_t(check_line_counter(l) < 3);
    }
    std::cout << count_part_two << '\n';
    std::cin.get();
}
