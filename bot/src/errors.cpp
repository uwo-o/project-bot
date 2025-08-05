#include "errors.h"

std::vector<String> error_list;

void add_error(const String &msg)
{
    error_list.push_back(msg);
}

void clear_errors()
{
    error_list.clear();
}

void print_errors()
{
    for (const auto &msg : error_list)
    {
        Serial.println(msg);
    }
}