#pragma once
#include <iostream>
class Entry
{
private:
    int* number;
    char* name;
public:
    Entry();
    Entry(const char _name[], int _number);
    char* get_name();
    int get_number();
    friend std::ostream& operator<< (std::ostream& out, const Entry& entry);
    friend std::istream& operator>> (std::istream& in, Entry& entry);
};
