#ifndef ERRORS_H
#define ERRORS_H

#include <Arduino.h>
#include <vector>

std::vector<std::exception> error_list;
void add_error(const std::exception &e);
void clear_errors();
void print_errors();

#endif