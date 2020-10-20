#include "Entry.h"

Entry::Entry() : name(nullptr), number(nullptr) { }

Entry::Entry(std::string _name, int _number) {
    name = new std::string(_name);
    number = new int(_number);
}

Entry::Entry(std::string _name) {
    name = new std::string(_name);
    number = nullptr;
}

const std::string Entry::get_name() const {
    return *name;
}

const int Entry::get_number() const {
    return *number;
}

bool Entry::operator==(const Entry& e) const
{
    return *name == *e.name;
}

std::ostream& operator<< (std::ostream& out, const Entry& entry)
{
    out << *entry.name << " " << *entry.number;
    return out;
}

std::istream& operator>> (std::istream& in, Entry& entry)
{
    entry.name = new std::string;
    in >> *entry.name;
    entry.number = new int;
    in >> *entry.number;
    return in;
}