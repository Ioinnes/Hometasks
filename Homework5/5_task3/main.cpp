#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

void check(std::string &data, std::regex &pattern){
    std::sregex_iterator begin(data.cbegin(), data.cend(), pattern);
    std::sregex_iterator end;
    std::string str;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        unsigned long pos = match_str.find('@');
        unsigned long len = match_str.length();
        for(int i = pos; i < len; i++){
            std::cout << match_str[i];
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::string data = "ugu ih eij_y@andex.ru idjf iejf idjf ijJWUUA@9jas.ru ifjiefj@idwe.org 12987832_widj@ijwq.org 2738783261@mail.ru";
    //std::getline(std::cin, data);

    std::regex pattern_email(R"(\w{4,30}@[[:lower:]]{3,15}.[[:lower:]]{2,6})");

    check(data, pattern_email);


    return 0;
}