#include <iostream>
#include <iomanip>
#include <string>

int main() {
        std::cout << "Enter amount in USD. Example: $123.45" << std::endl;
        std::string str;
        std::getline ( std::cin, str );
        std::istringstream in(str);
        long double v1;
        in.imbue(std::locale("en_US.UTF-8"));
        in >> std::get_money(v1);
        v1 *= 108;

        std::cout.imbue(std::locale("ru_RU.UTF-8"));
        std::cout << std::showbase << std::put_money(v1, true) << '\n';
        return 0;
}