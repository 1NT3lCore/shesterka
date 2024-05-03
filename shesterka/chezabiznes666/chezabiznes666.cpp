#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main() {

    string input_filename;
    string output_filename;

    cout << "Enter the name of the input file: ";
    cin >> input_filename;

    if (!file_exists(input_filename)) {
        cerr << "Error: Input file does not exist." << endl;
        return 1;
    }

    if (is_file_empty(input_filename)) {
        cerr << "Error: Input file is empty." << endl;
        return 1;
    }

    cout << "Enter the name of the output file: ";
    cin >> output_filename;

    count_lowercase_russian_letters(input_filename, output_filename);

    cout << "Results written to " << output_filename << endl;

    return 0;
}