#include "errors.h"

std::vector<std::exception> error_list;

void add_error(const std::exception &e)
{
    error_list.push_back(e);
}

void clear_errors()
{
    error_list.clear();
}

void print_errors()
{
    for (const auto &e : error_list)
    {
        Serial.println(e.what());
    }
}
