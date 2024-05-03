#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool file_exists(const string& filename);
bool is_file_empty(const string& filename);
void count_lowercase_russian_letters(const string& input_filename, const string& output_filename);

#endif