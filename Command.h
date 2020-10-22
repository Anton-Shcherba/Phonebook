#pragma once
#include <sstream>
#include <algorithm>
#include <fstream>
#include <unordered_set>
#include "Entry.h"

class Command
{
protected:
    std::vector<std::string> words;
public:
    virtual void execute(std::unordered_set<Entry>& phonebook) = 0;
    void init(const std::vector<std::string>& arguments);
};

class Add_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set) override;
};

class Search_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set) override;
};

class Del_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set) override;
};

class Write_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set) override;
};

class Read_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set) override;
};

class Show_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set) override;
};

