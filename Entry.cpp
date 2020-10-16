#include "Entry.h"

Entry::Entry() {}

Entry::Entry(const char _name[], int _number) {
    name = new char[strlen(_name) + 1];
    number = new int(_number);
    strcpy_s(name, strlen(_name) + 1, _name);
}

char* Entry::get_name() {
    return name;
}

int Entry::get_number() {
    return *number;
}

std::ostream& operator<< (std::ostream& out, const Entry& entry)
{
    out << entry.name << " " << *entry.number;
    return out;
}

std::istream& operator>> (std::istream& in, Entry& entry)
{
    char tmp[10];
    in >> tmp;
    entry.name = new char[strlen(tmp) + 1];
    strcpy_s(entry.name, strlen(tmp) + 1, tmp);
    entry.number = new int;
    in >> *entry.number;
    return in;
}