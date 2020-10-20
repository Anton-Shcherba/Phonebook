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
    void init();
};

class Add_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set);
};

class Search_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set);
};

class Del_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set);
};

class Write_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set);
};

class Read_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set);
};

class Show_Command : public Command {
public:
    void execute(std::unordered_set <Entry>& entry_set);
};

