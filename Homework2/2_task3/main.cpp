#include <algorithm>
#include <iomanip>
#include <iostream>

#include <boost/multi_array.hpp>

template <typename T>
boost::multi_array<T, 3U> fill_multi_array(std::vector<T> &vector) {
    boost::multi_array<T, 3U> multiArray;
    const auto size_1 = 3U;
    const auto size_2 = 4U;
    const auto size_3 = 5U;
    auto counter = 0;
    for (auto i = 0U; i < size_1; ++i) {
        for (auto j = 0U; j < size_2; ++j) {
            for (auto k = 0U; k < size_3; ++k) {
                std::cout << (multiArray[i][j][k] = vector[++counter]) << " ";
            }

            std::cout << std::endl;
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

    using view_t = array_t::array_view < 2 > ::type;

    using range_t = boost::multi_array_types::index_range;

    view_t view = array[boost::indices[range_t(0, 2)][1][range_t(0, 5, 2)]];
    //view_t view = array[boost::indices[range_t() < 2][range_t()][0 <= range_t().stride(2) <= 5]];

    const auto view_size_1 = 2U;
    const auto view_size_2 = 3U;

    for (auto i = 0U; i < view_size_1; ++i)
    {
        for (auto k = 0U; k < view_size_2; ++k)
        {
            std::cout << std::setw(2) << std::right << view[i][k] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::vector<int> vector{4,3,2,1,4,5,3,7,8,6,
                            5,3,7,3,1,8,9,4,2,1};
    boost::multi_array<int, 3U> multiArray = fill_multi_array(vector);

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