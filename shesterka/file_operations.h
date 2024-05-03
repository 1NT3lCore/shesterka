#pragma once
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

void write_to_file(const char* filename, int* numbers, int size);
void read_from_file(const char* filename, int* numbers, int size);
int find_min(int* numbers, int size);
void replace_multiples_with_zero(const char* filename, int min_number);

#endif
