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
    std::string data = "fr rg2000.12.1 ufhn 9999.12.31 2000.12.12 2000.12.1a 01:59:59 23:59:59 00:12:60 00:12:23 eufh 21:12:23 uefh 1000.13.31 eifj iehf uwhd uwdh uwqdh uh 1231.09.31 uwdh uwdh uwdbh wudh 12jan.12.53 2000.12.aa";
    //std::getline(std::cin, data);

    std::regex pattern_date(R"((\d{4}).(0[1-9]{1}|1[0-2]{1}).([0-2]{1}[0-9]{1}|31|30))");
    std::regex pattern_time(R"(([0-1]{1}\d{1}|2[0-3]{1}):([0-5]{1}\d{1}):([0-5]{1}\d{1}))");
    check(data, pattern_date);
    check(data, pattern_time);

    return 0;
}


