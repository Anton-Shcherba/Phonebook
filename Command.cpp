#include "Command.h"

void Command::init(const std::vector<std::string>& arguments) {
    words = arguments;
}

std::string Add_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 2) return "[Error] command \"add\" should be: add <name> <number>";
    else if (words[1].substr(0, 1) == "0") return "[Error] number cannot start with zero";
    else if (words[1].size() != 7) return "[Error] the length of the number must be seven numerals";
    else if (!all_of(words[1].begin(), words[1].end(), isdigit)) return "[Error] number should contain only digits";
    else {
        auto got = std::find_if(entry_set.cbegin(), entry_set.cend(), [&](const Entry& e) { return e.get_name() == words[0]; });
        if (got == entry_set.end()) {
            entry_set.emplace(words[0], stoi(words[1]));
            return "[Done] number recorded";
        }
        else {
            entry_set.erase(got);
            entry_set.emplace(words[0], stoi(words[1]));
            return "[Done] number updated";
        }
    }
}

std::string Search_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 1) return "[Error] command \"search\" should be: search <name>";
    else {
        auto got = std::find_if(entry_set.cbegin(), entry_set.cend(), [&](const Entry& e) { return e.get_name() == words[0]; });
        if (got == entry_set.end()) return "[Error] no contact with name " + words[0] + " found";
        else return "[Done] " + got->get_name() + ' ' + std::to_string(got->get_number());
    }
}

std::string Del_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 1) return "[Error] command \"delete\" should be: delete <name>";
    else if (!entry_set.erase(Entry(words[0]))) return "[Error] contact with this name does not exist";
    else return "[Done] contact deleted";
}

std::string Write_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 1) return "[Error] command \"write\" should be: write <filename>";
    else {
        std::ofstream out(words[0] + ".txt");
        if (!out.is_open()) return "[Error] invalid file name";
        else {
            for (auto now : entry_set) out << now << std::endl;
            out.close();
            return "[Done] data are written to the file " + words[0] + ".txt";
        }
    }
}

std::string Read_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 1) return "[Error] command \"read\" should be: read <filename>";
    else {
        std::ifstream in(words[0] + ".txt");
        if (!in.is_open()) return "[Error] invalid file name or file does not exist";
        else {
            Entry tmp;
            while (in >> tmp) {
                auto ret = entry_set.insert(tmp);
                if (ret.second == false) {
                    entry_set.erase(ret.first);
                    entry_set.insert(tmp);
                }
            }
            return "[Done] data are read from file " + words[0] + ".txt";
        }
    }
}

std::string Show_Command::execute(std::unordered_set <Entry>& entry_set) {
    if (words.size() != 0) return "[Error] command \"show\" requires no arguments";
    if (entry_set.size() == 0) return "[Error] no contacts in memory";
    else {
        std::string out_str = "[Done]";
        for (auto now : entry_set) out_str += '\n' + now.get_name() + ' ' + std::to_string(now.get_number());
        return out_str;
    }
}