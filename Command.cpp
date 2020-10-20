#include "Command.h"

void Command::init() {
    std::string command;
    getline(std::cin, command);
    std::istringstream ist(command);
    words.clear();
    while (ist >> command) words.push_back(command);
}

void Add_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 2) std::cout << "[Error] command \"add\" should be: add <name> <number>" << std::endl;
    else if (words[1].substr(0, 1) == "0") std::cout << "[Error] number cannot start with zero" << std::endl;
    else if (words[1].size() != 7) std::cout << "[Error] the length of the number must be seven numerals" << std::endl;
    else if (!all_of(words[1].begin(), words[1].end(), isdigit)) std::cout << "[Error] number should contain only digits" << std::endl;
    else {
        auto ret = entry_set.emplace(words[0], stoi(words[1]));
        if (!ret.second) {
            entry_set.erase(ret.first);
            entry_set.emplace(words[0], stoi(words[1]));
            std::cout << "[Done] number updated" << std::endl;
        }
        else std::cout << "[Done] number recorded" << std::endl;
    }
}

void Search_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 1) std::cout << "[Error] command \"search\" should be: search <name>" << std::endl;
    else {
        std::unordered_set<Entry>::const_iterator  got = entry_set.find(Entry(words[0]));
        if (got == entry_set.end()) std::cout << "[Error] no contact with name " + words[0] + " found" << std::endl;
        else std::cout << "[Done] " << *got << std::endl;
    }
}

void Del_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 1) std::cout << "[Error] command \"delete\" should be: delete <name>" << std::endl;
    else if (!entry_set.erase(Entry(words[0]))) std::cout << "[Error] contact with this name does not exist" << std::endl;
    else std::cout << "[Done] contact deleted" << std::endl;
}

void Write_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 1) std::cout << "[Error] command \"write\" should be: write <filename>" << std::endl;
    else {
        std::ofstream out(words[0] + ".txt");
        if (!out.is_open()) std::cout << "[Error] invalid file name" << std::endl;
        else {
            for (auto now : entry_set) out << now << std::endl;
            out.close();
            std::cout << "[Done] data are written to the file " + words[0] + ".txt" << std::endl;
        }
    }
}

void Read_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 1) std::cout << "[Error] command \"read\" should be: read <filename>" << std::endl;
    else {
        std::ifstream in(words[0] + ".txt");
        if (!in.is_open()) std::cout << "[Error] invalid file name or file does not exist" << std::endl;
        else {
            Entry tmp;
            while (in >> tmp) {
                auto ret = entry_set.insert(tmp);
                if (ret.second == false) {
                    entry_set.erase(ret.first);
                    entry_set.insert(tmp);
                }
            }
            std::cout << "[Done] data are read from file " + words[0] + ".txt" << std::endl;
        }
    }
}

void Show_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 0) std::cout << "[Error] command \"show\" requires no arguments" << std::endl;
    if (entry_set.size() == 0) std::cout << "[Error] no contacts in memory" << std::endl;
    else for (auto now : entry_set) std::cout << now << std::endl;
}