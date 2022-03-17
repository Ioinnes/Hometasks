#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

void check(std::string &data, std::regex &pattern){
    std::sregex_iterator begin(data.cbegin(), data.cend(), pattern);
    std::sregex_iterator end;

    std::for_each(begin, end, [](const std::smatch & m)
    {
        std::cout << m[0] << std::endl;
    });
}

int main()
{
    std::string data = "iefhe uifhe ufeh 19:23:23 20:01:01 iefnh 2a:32:12 2002.02.03 ife 200j.02.wi uefh uefh uefh efwuhiuefhui 37273gr64g2376g 9999.13.12 9999.12.01";
    //std::getline(std::cin, data);

    std::regex pattern_date1(R"(\d{4}.[0]{1}[1-9]{1}.[0-2]{1}\d{1})");
    std::regex pattern_date2(R"(\d{4}.[1]{1}[0-2]{1}.[0-2]{1}\d{1})");
    std::regex pattern_time1(R"([0-1]{1}\d{1}:[0-5]{1}\d{1}:[0-5]{1}\d{1})");
    std::regex pattern_time2(R"([2]{1}[0 - 3]{1}:[0-5]{1}\d{1}:[0-5]{1}\d{1})");
    check(data, pattern_date1);
    check(data, pattern_date2);
    check(data, pattern_time1);
    check(data, pattern_time2);

    return 0;
}


