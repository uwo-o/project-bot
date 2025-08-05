#ifndef ERRORS_H
#define ERRORS_H

#include <Arduino.h>
#include <vector>

extern std::vector<String> error_list;
void add_error(const String &msg);
void clear_errors();
void print_errors();

#endif