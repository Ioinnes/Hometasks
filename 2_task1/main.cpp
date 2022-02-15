#include <iostream>
#include <vector>
int main() {
    // для решения данной задачи будем последовательно добавлять элементы в вектор с помощью функции члена push_back() и отслеживать capacity.
    // в первом столбце будет отображться количество элементов. Во втором - capacity
    std::vector<int> vector1;
    for (int i = 0; i < 64; i++) {
        std::cout << vector1.size() << ' ' << vector1.capacity() << std::endl;
        vector1.push_back(1);
    }
    //после выполнения программы на этом этапе мы получили ожидаемвй результат: когда size становится равным capacity и мы пытаемся добавить новый элемент в конец вектора, capacity увеличивается в два раза.
    for (int i = 0; i < 64; i++) {
        std::cout << "--";
    }
    std::cout << std::endl;
    //попробуем использовать reserve
    std::vector<int> vector2;
    vector2.reserve(13);
    for (int i = 0; i < 32; i++) {
        std::cout << vector2.size() << ' ' << vector2.capacity() << std::endl;
        vector2.push_back(1);
    }
    //получили ожидаемый результат: capacity при условиях, озвученных выше, увеличивается в 2 раза
    for (int i = 0; i < 64; i++) {
        std::cout << "--";
    }
    std::cout << std::endl;
    //теперь попробуем запросить большой объем памяти для vector3
    std::vector<int> vector3;
    // но для начала узнаем максимальный размер вектора с помощью max_size
    std::cout << vector3.max_size() << std::endl;
    //зарезервируем максимальный размер и будем добавлять элементы до тех пор, пока его не достигнем
    vector3.reserve(2305843009213693951);
    for (long i = 0; i < 2305843009213693954; i++) {
        //std::cout << vector3.size() << ' ' << vector3.capacity() << std::endl;
        vector3.push_back(1);
    }
    std::cout << vector3.size() << ' ' << vector3.capacity() << std::endl;
}
