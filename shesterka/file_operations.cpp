#include <iostream>
#include <fstream>
#include "file_operations.h"

void write_to_file(const char* filename, int* numbers, int size) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            file << numbers[i] << " ";
        }
        file.close();
    }
}

void read_from_file(const char* filename, int* numbers, int size) {
    std::ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            file >> numbers[i];
        }
        file.close();
    }
}

int find_min(int* numbers, int size) {
    int min = numbers[0];
    for (int i = 1; i < size; ++i) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

void replace_multiples_with_zero(const char* filename, int min_number) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::cout << "Original numbers:" << std::endl;
        int number;
        while (file >> number) {
            std::cout << number << " ";
        }
        file.close();
         std::cout << std::endl;
        file.open(filename);
        if (file.is_open()) {
            std::cout << "Numbers with multiples of " << min_number << " replaced with 0:" << std::endl;
            while (file >> number) {
                if (number % min_number == 0) {
                    std::cout << "0 ";
                }
                else {
                    std::cout << number << " ";
                }
            }
            file.close();
        }
    }
}