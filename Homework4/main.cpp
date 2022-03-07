#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

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
template <typename T>
void squareVector (std::vector<T> &vector){
    for(int i = 0; i < vector.size(); i++){
        vector[i] = vector[i] * vector[i];
    }

}

template <typename T>
void changeVector(std::vector<T> &vector, int size) {
    for(int i = 0; i < rand() % (size - 1) + 1; i++){
        vector[i] = 1;
    }
};

template <typename T>
long sumVector(std::vector<T> &vector){
    long result = 0;
    for (T i: vector) result += i;
    return result;
}


template <typename T>
void makeZeroVector(std::vector<T> &vector, int size){
    for (int i = 0; i < size; i++){
        if (vector[i] < 0)
            vector[i] = 0;
    }
}

template <typename T>
void removeZero(std::vector<T> &vector, int size){
    for (int i = 0; i < size; i++){
        if (vector[i] == 0){
            for(int k = i; k < size; k++){
                vector[k] = vector[k+1];
            }
            vector.pop_back();
            size--;
            i--;
        }

    }
}

template<typename T>
void reverseVector(std::vector<T> &vector){
    int size = vector.size();
    for(int i = 0; i < int(size / 2); i++){
        std::swap(vector[i], vector[size - 1 - i]);
    }
}


template <typename T, typename U>
void mergeVectors(std::vector<T> &vector1, std::vector<U> &vector2, std::vector<int> &vector3){
    int counter1 = 0, counter2 = 0, size1 = vector1.size(), size2 = vector2.size();
    while (counter1 < size1 && counter2 < size2) {
        if (vector1[counter1] <= vector2[counter2]) {
            vector3.push_back(vector1[counter1]);
            counter1++;
        }
        else {
            vector3.push_back(vector2[counter2]);
            counter2++;
        }
    }
    if (counter1 != size1) {
        for (int i = counter1; i < size1; i++)
            vector3.push_back(vector1[i]);
    }
    else {
        for (int i = counter2; i < size2; i++)
            vector3.push_back(vector2[i]);
    }
}

template<typename T>
void findInsertionRange(std::vector<T> vector, T insertElement) {
    int beginOfRange = 0, endOfRange = 0, sizeOfVector = vector.size();
    for (int i = 0; i < sizeOfVector; i++) {
        if (vector[i] < insertElement)
            beginOfRange++;
        else break;
    }
    endOfRange = beginOfRange;
    for (int i = beginOfRange; i < sizeOfVector; i++){
            if (vector[i] == insertElement){
                endOfRange++;
            }
            else{
                break;
            }
        }
    std::cout << "Range: " << '[' << beginOfRange << ", " << endOfRange - 1 << ']' << std::endl;
}
int main() {
    std::vector<short> vector1;
    int size = 0;
    srand(time(nullptr));

    for (int i = 0; i < 255; i++){
        int a = rand() % 10 + 1;
        vector1.push_back(a);
    }

    for (int i = 0; i < (rand() % 5); i++) {
        int n = 0;
        std::cin >> n;
        vector1.push_back(n);
    }

    size = vector1.size();
    std::cout << "Sequence is generated(std::cin is already used): ";
    printVector(vector1);

    mixVector(vector1, vector1.size());
    std::cout << "Mixed: ";
    printVector(vector1);

    removeDublicate(vector1, size);
    std::cout << "Duplicates are removed: ";
    printVector(vector1);

    size = vector1.size();
    std::cout << "Odd: " << countOdd(vector1, size) << std::endl;

    std::pair<short, short> pairMinMax = findMinMax(vector1, size);
    std::cout << "Min: " << pairMinMax.first << std::endl << "Max: " << pairMinMax.second << std::endl;

    findPrimeNumber(vector1);

    squareVector(vector1);
    std::cout<< "Squared Vector: ";
    printVector(vector1);

    std::vector<int> vector2;
    vector2.reserve(size);
    for(int i = 0; i < size; i++) {
        vector2.push_back(rand());
    }
    std::cout << "New vector: ";
    printVector(vector2);

    std::cout << "Sum in vector2: " << sumVector(vector2) << std::endl;

    changeVector(vector2, size);
    std::cout << "Changed vector2: ";
    printVector(vector2);

    std::vector<int> vector3;
    vector3.reserve(size);
    for (int i = 0; i < size; i++){
        vector3.push_back(vector1[i] - vector2[i]);
    }
    std::cout << "Make vector3: ";
    printVector(vector3);

    makeZeroVector(vector3, size);
    std::cout << "Make zero vector3: ";
    printVector(vector3);

    removeZero(vector3, size);
    std::cout << "Remove zero-elements: ";
    printVector(vector3);

    reverseVector(vector3);
    std::cout << "Reversed vector3: ";
    printVector(vector3);

    std::sort(vector3.begin(), vector3.end());
    int sizeVector3 = vector3.size();
    if (sizeVector3 >= 3) {
        for (int i = 0; i < 3; i++)
            std::cout << "top " << i + 1 << ": " << vector3[sizeVector3 - i - 1] << std::endl;
    }
    else {
        for (int i = 0; i < sizeVector3; i++)
            std::cout << "top " << i + 1 << ": " << vector3[sizeVector3 - i - 1] << std::endl;
    }


    std::sort(vector1.begin(), vector1.end());
    std::sort(vector2.begin(), vector2.end());

    std::cout << "Sorted vector: ";
    printVector(vector1);
    std::cout << "Sorted vector2: ";
    printVector(vector2);

    std::vector<int> vector4;
    mergeVectors(vector1, vector2, vector4);
    std::cout<<"Make vector4: ";
    printVector(vector4);

    //std::cout << vector4.size();

    findInsertionRange(vector4, 1);

    std::cout<< "vector1: ";
    printVector(vector1);
    std::cout << "vector2: ";
    printVector(vector2);
    std::cout << "vector3: ";
    printVector(vector3);
    std::cout << "vector4: ";
    printVector(vector4);
    return 0;
}
