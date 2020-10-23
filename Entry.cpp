#include "Entry.h"

Entry::Entry() : name(""), number(0) { }

Entry::Entry(std::string _name, int _number) {
    name = _name;
    number = _number;
}

Entry::Entry(std::string _name) {
    name = _name;
    number = 0;
}

const std::string Entry::get_name() const {
    return name;
}

const int Entry::get_number() const {
    return number;
}

bool Entry::operator==(const Entry& e) const
{
    return name == e.name;
}

std::ostream& operator<< (std::ostream& out, const Entry& entry)
{
    out << entry.name << " " << entry.number;
    return out;
}

std::istream& operator>> (std::istream& in, Entry& entry)
{
    in >> entry.name;
    in >> entry.number;
    return in;
}