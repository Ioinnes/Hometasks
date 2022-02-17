#include <algorithm>
#include <iomanip>
#include <iostream>

#include <boost/multi_array.hpp>

template <typename T >
void fill_multi_array(std::vector<std::vector<std::vector<int>>> &vector, boost::multi_array<T, 3> &multiArray) {
    const auto size_1 = 3U;
    const auto size_2 = 4U;
    const auto size_3 = 5U;
    auto counter = 0;
    for (auto i = 0U; i < size_1; ++i) {
        for (auto j = 0U; j < size_2; ++j) {
            for (auto k = 0U; k < size_3; ++k) {
                multiArray[i][j][k] = vector[i][j][k];
            }
        }
    }
}

int main()
{
    const auto size_1 = 3U;
    const auto size_2 = 4U;
    const auto size_3 = 5U;

    using array_t = boost::multi_array < int, 3U > ;

    array_t array(boost::extents[size_1][size_2][size_3]);

    auto counter = 0;

    for (auto i = 0U; i < size_1; ++i)
    {
        for (auto j = 0U; j < size_2; ++j)
        {
            for (auto k = 0U; k < size_3; ++k)
            {
                std::cout << std::setw(2) << std::right << (array[i][j][k] = ++counter) << " ";
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    std::vector<std::vector<std::vector<int>>> vector1;

    for (auto i = 0U; i < size_1; ++i)
    {   std::vector<std::vector<int>> vector2;
        for (auto j = 0U; j < size_2; ++j)
        {
            std::vector<int> vector3;
            for (auto k = 0U; k < size_3; ++k)
            {   counter += 100;
                vector3.push_back(counter);
            }
            vector2.push_back(vector3);
        }
        vector1.push_back(vector2);
    }


    array_t multiArray(boost::extents[size_1][size_2][size_3]);
    fill_multi_array(vector1, multiArray);

    counter = 0;

    for (auto i = 0U; i < size_1; ++i)
    {
        for (auto j = 0U; j < size_2; ++j)
        {
            for (auto k = 0U; k < size_3; ++k)
            {
               std::cout << std::setw(2) << std::right << (multiArray[i][j][k]) << " ";
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
    }
    return 0;
}