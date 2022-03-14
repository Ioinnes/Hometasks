#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

int generator() {
    return rand() % 10 + 1;
}

void printVector(std::vector<int> &vector) {
    for (int i : vector){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

bool isOdd (int n) {
    if (n % 2 == 0)
        return false;
    else return true;
}

bool isPrime (int n) {
    if (n == 1) return false;
    for(int i = 2; i < n / 2 + 1; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int minus(std::vector<int>::iterator &iterator1,std::vector<int>::iterator &iterator2){
    int result = *iterator1 * *iterator2;
    iterator1++;
    iterator2++;
    return result;
}


int main() {
    std::mt19937 mt(time(nullptr));
    srand(time(nullptr));
    std::vector<int> vector1(10);
    std::generate(vector1.begin(), vector1.end(), generator);

    std::cout << "Generate vector1: ";
    printVector(vector1);

    std::copy(
            std::istream_iterator<int>(std::cin),
            std::istream_iterator<int>(),
            std::back_inserter(vector1));

    std::cout << "Add elements in vector1 from cin: ";
    printVector(vector1);

    std::shuffle(vector1.begin(), vector1.end(), mt);

    std::cout << "Shuffle vector1: ";
    printVector(vector1);

    std::vector<int>::iterator ip;
    std::sort(vector1.begin(), vector1.end());
    ip = std::unique(vector1.begin(), vector1.end());
    vector1.resize(std::distance(vector1.begin(), ip));

    std::cout << "Remove duplicates: ";
    printVector(vector1);

    std::cout << "Odd elements in vector1: " << std::count_if(vector1.begin(), vector1.end(), isOdd) << std::endl;

    std::cout << "Min in vector1: " << *std::min_element(vector1.begin(), vector1.end()) << std::endl;
    std::cout << "Max in vector1: " << *std::max_element(vector1.begin(), vector1.end()) << std::endl;

    std::cout << "Prime: " << *std::find_if(vector1.begin(), vector1.end(), isPrime) << std::endl;

    std::for_each(vector1.begin(), vector1.end(), [](int &n){ n *= n;});

    std::cout << "Square vector: ";
    printVector(vector1);

    std::vector<int> vector2(vector1.size());
    std::generate(vector2.begin(), vector2.end(), mt);
    std::cout << "Generate vector2: ";
    printVector(vector2);

    std::cout << "Sum in vector2: " << std::accumulate(vector2.begin(), vector2.end(), 0) << std::endl;

    int vector2_size = vector2.size();
    std::fill(vector2.begin(), vector2.begin() + 1 + rand() % (vector2_size - vector2_size / 3)  , 1);

    std::cout << "Change value to 1 in vector2: ";
    printVector(vector2);


    auto iterator1 = vector1.begin(), iterator2 = vector2.begin();
    std::vector<int> vector3(vector2_size);
    std::generate(vector3.begin(), vector3.end(), [&iterator1, &iterator2](){int result = *iterator1 + *iterator2; iterator1++; iterator2++; return result;
    });
    //std::transform(vector1.begin(), vector1.end(), vector2.begin(), vector3.begin(), std::plus<>{});

    std::cout << "Generate vector3: ";
    printVector(vector3);


    std::for_each(vector3.begin(), vector3.end(), [](int &n){if (n < 0) n = 0;});
    std::cout << "Change elements < 0 to 0 in vector3: ";
    printVector(vector3);

    vector3.erase(std::remove(vector3.begin(), vector3.end(), 0), vector3.end());
    std::cout << "Remove 0-elements from vector3: ";
    printVector(vector3);

    std::reverse(vector3.begin(), vector3.end());
    std::cout << "Reverse vector3: ";
    printVector(vector3);

    //to search top3 elements it is better to use heap, but firstly we have to make build
    std::sort(vector3.begin(), vector3.end());
    int vector3_size = vector3.size();
    std::cout << "Top 1 element in vector3: " << vector3[vector3_size - 1] << std::endl;
    std::cout << "Top 2 element in vector3: " << vector3[vector3_size - 2] << std::endl;
    std::cout << "Top 3 element in vector3: " << vector3[vector3_size - 3] << std::endl;

    std::reverse(vector3.begin(), vector3.end());

    std::sort(vector2.begin(), vector2.end());
    std::cout << "Sort vector1: ";
    printVector(vector1);
    std::cout << "Sort vector2: ";
    printVector(vector2);

    std::vector<int> vector4(vector2_size * 2);
    std::merge(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), vector4.begin());
    std::cout << "Merge vector1 and vector2 in vector4: ";
    printVector(vector4);

    auto range = std::equal_range(vector4.begin(), vector4.end(), 1);
    std::cout << "Range for insertion: [" << range.first - vector4.begin() << ", " << range.second - vector4.begin() << ']' << std::endl;

    std::cout << "vector1: ";
    printVector(vector1);
    std::cout << "vector2: ";
    printVector(vector2);
    std::cout << "vector3: ";
    printVector(vector3);
    std::cout << "vector4: ";
    printVector(vector4);

    return 0;

}