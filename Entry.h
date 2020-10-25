#pragma once
#include <iostream>
#include <string>

class Entry
{
private:
    std::string name;
    int number;
public:
    Entry();
    Entry(std::string _name);
    Entry(std::string _name, int _number);
    const std::string get_name() const;
    const int get_number() const;
    bool operator==(const Entry& p) const;
    friend std::ostream& operator<< (std::ostream& out, const Entry& entry);
    friend std::istream& operator>> (std::istream& in, Entry& entry);
};

namespace std
{
    template <>
    struct hash<Entry>
    {
        typedef Entry argument_type;
        typedef std::size_t result_type;
        result_type operator()(argument_type const&s) const
        {
            return std::hash<std::string>()(s.get_name() + std::to_string(s.get_number()));
        }
    };
}