#include "functions.h"
#include <iostream>
#include <fstream>
#include <map>


bool file_exists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

bool is_file_empty(const string& filename) {
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
}

void count_lowercase_russian_letters(const std::string& input_filename, const std::string& output_filename) {
    std::ifstream input_file(input_filename);
    std::ofstream output_file(output_filename, std::ios::out | std::ios::binary);
    output_file << "\xEF\xBB\xBF"; // Добавляем BOM для UTF-8

    if (!input_file.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return;
    }

    if (!output_file.is_open()) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return;
    }

    std::map<wchar_t, int> letter_counts;

    wchar_t ch;
    while (input_file.get(ch)) {
        if ((ch >= 0x0410 && ch <= 0x044F) || (ch == 0x0401) || (ch == 0x0451)) {
            letter_counts[ch]++;
        }
    }

    for (const auto& pair : letter_counts) {
        wchar_t russian_letter = pair.first;
        output_file << russian_letter << " " << pair.second << std::endl;
    }

    input_file.close();
    output_file.close();
}