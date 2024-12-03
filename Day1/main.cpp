#include <algorithm>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
int main()
{
    std::ifstream file("../../Day1/input.txt");
    std::string line;
    std::vector<int> first, second;
    first.reserve(1000);
    second.reserve(1000);
    while (std::getline(file, line))
    {
        first.push_back(std::stoi(line.substr(0, 5)));
        second.push_back(std::stoi(line.substr(8, 5)));
    }
    std::ranges::sort(first);
    std::ranges::sort(second);

    uint64_t total{};
    for (int i = 0; i < first.size(); ++i)
    {
        total += std::abs(first[i] - second[i]);
    }
    std::cout << total << std::endl;

    uint64_t total_part_two{};

    for (int i : first)
        total_part_two += i * std::ranges::count(second, i);

    std::cout << total_part_two << std::endl;
    // std::cin.get();
}