#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T> &vector){
    for (T i: vector){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void mixVector(std::vector<T> &vector, int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i)
        std::swap(vector[i], vector[std::rand() % size]);
}

template <typename T>
void removeDublicate(std::vector<T> &vector, int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++){
            if (vector[i] == vector[j]) {
                for(int k = j; k < size - 1; k++){
                    vector[k] = vector[k+1];
                }
                size--;
                j--;
                vector.pop_back();
            }
        }
    }
}


int countOdd(std::vector<short> vector, int size) {
    int result = 0;
    for (short i: vector){
        if (i % 2 == 1)
            result++;
    }
    return result;
};

std::pair<short, short> findMinMax (std::vector<short> &vector, int size) {
    int indexMin = 0, indexMax = 0;
    for (int i = 1; i < size; i++){
        if (vector[indexMax] < vector[i])
            indexMax = i;
        if (vector[indexMin] > vector[i])
            indexMin = i;
    }

    return std::make_pair(vector[indexMin], vector[indexMax]);
}


void findPrimeNumber (std::vector<short> &vector) {
    int counter = 0;
    for (short i: vector){
        bool flag = true;
        for (int j = 2; j < i / 2 + 1; j++){
            if ((i % j) == 0)
                flag = false;
        }
        if (flag && (i > 1)) {
            counter++;
            std::cout << "Prime Number #" << counter << ": " << i << std::endl;
        }
    }
}
int main() {
    std::vector<short> vector;
    int size = 0;
    srand(time(nullptr));
    for (int i = 0; i < 255; i++){
        int a = rand() % 10 + 1;
        vector.push_back(a);
    }

    for (int i = 0; i < (rand() % 5); i++) {
        int n = 0;
        std::cin >> n;
        vector.push_back(n);
    }

    size = vector.size();
    std::cout << "Sequence is generated(std::cin is already used): ";
    printVector(vector);

    mixVector(vector, vector.size());
    std::cout << "Mixed: ";
    printVector(vector);

    removeDublicate(vector, size);
    std::cout << "Duplicates are removed: ";
    printVector(vector);

    size = vector.size();
    std::cout << "Odd: " << countOdd(vector, size) << std::endl;

    std::pair<short, short> pairMinMax = findMinMax(vector, size);
    std::cout << "Min: " << pairMinMax.first << std::endl << "Max: " << pairMinMax.second << std::endl;

    findPrimeNumber(vector);

    return 0;
}
