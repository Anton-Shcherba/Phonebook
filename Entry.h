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
    char* get_name() const;
    int get_number() const;
    bool operator==(const Entry& p) const;
    friend std::ostream& operator<< (std::ostream& out, const Entry& entry);
    friend std::istream& operator>> (std::istream& in, Entry& entry);
};

namespace std
{
    template <>
    struct hash<char*>
    {
        size_t operator()(const char* s) const
        {
            size_t h = 5381;
            int c;
            while ((c = *s++))
                h = ((h << 5) + h) + c;
            return h;
        }
    };

    template <>
    struct hash<Entry>
    {
        typedef Entry argument_type;
        typedef std::size_t result_type;

        result_type operator()(argument_type const&s) const
        {
            return std::hash<char*>()(s.get_name());
        }
    };
}