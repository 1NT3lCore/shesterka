#include <iostream>
#include <fstream>
#include <ctime>
#include "file_operations.h"

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    const char* filename = "numbers.txt";
    int size;

    std::cout << "Введите количество чисел: ";
    while (!(std::cin >> size) || size <= 0) {
        std::cin.clear(); // Сброс флагов ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
        std::cout << "Ошибка: введите натуральное число: ";
    }

    int* numbers = new int[size];
    for (int i = 0; i < size; ++i) {
        numbers[i] = rand() % 100 + 1; // Генерация случайных чисел от 1 до 100
    }

    write_to_file(filename, numbers, size);

    read_from_file(filename, numbers, size);
    int min_number = find_min(numbers, size);
    replace_multiples_with_zero(filename, min_number);

    delete[] numbers;

    return 0;
}