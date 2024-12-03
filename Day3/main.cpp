#include <algorithm>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <regex>
#include <sstream>




int main()
{
    std::ifstream file("../../Day3/input.txt");
    std::string line;
    std::string lines;
    std::regex reg("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
    while (std::getline(file, line))
    {
      lines += line;
    }
    auto start = std::sregex_iterator(lines.begin(), lines.end(), reg);
    auto end = std::sregex_iterator();
    std::vector<std::string> real_muls;
    for (std::sregex_iterator i = start; i != end; ++i)
      real_muls.push_back(i->str());

    int64_t real_result{};
    for (auto const& mul : real_muls)
    {
        auto const operand1 = std::stoi(mul.substr(4, mul.find(',') - 4));
        auto const operand2 = std::stoi(mul.substr(mul.find(',') + 1, mul.find(')') - mul.find(',')));

        real_result += operand1 * operand2;
    }
    std::cout << real_result << std::endl;

    std::regex reg2(R"((mul\([0-9]{1,3},[0-9]{1,3}\))|(do\(\))|(don't\(\)))");
    auto start2 = std::sregex_iterator(lines.begin(), lines.end(), reg2);
    auto end2 = std::sregex_iterator();
    std::vector<std::string> vals2;
    for (std::sregex_iterator i = start2; i != end2; ++i)
    {
        vals2.push_back(i->str());
    }
    int64_t real_result2{};
    bool can_mul = true;
    for (auto const& val : vals2)
    {
        if (val[0] == 'm')
        {
            if (!can_mul) continue;
            auto const operand1 = std::stoi(val.substr(4, val.find(',') - 4));
            auto const operand2 = std::stoi(val.substr(val.find(',') + 1, val.find(')') - val.find(',')));

            real_result2 += operand1 * operand2;
        }
        else if (val == "don\'t()")
        {
            can_mul = false;
        }
        else if (val == "do()")
        {
            can_mul = true;
        }
        else
        {
            std::abort();
        }
    }
    std::cout << real_result2 << std::endl;
    std::cin.get();
}
