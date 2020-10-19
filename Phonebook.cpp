#include <iostream>
#include <windows.h>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
using namespace std;

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};
void color(unsigned x) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, x);
}
void help() {
    system("cls");
    color(LightBlue);
    cout << "read <filename>";
    color(White);
    cout << "     - read (load) data from a file. The path to the file is specified instead of <filename>." << endl;
    color(LightBlue);
    cout << "add <name> <number>";
    color(White);
    cout << " - add an entry to the phonebook. If an entry with the same name already exists, the new one will                          replace the old one (the number will be overwritten)." << endl;
    color(LightBlue);
    cout << "search <name>";
    color(White);
    cout << "       - search for a record with this name." << endl;
    color(LightBlue);
    cout << "delete <name>";
    color(White);
    cout << "       - delete a record with this name." << endl;
    color(LightBlue);
    cout << "write <filename>";
    color(White);
    cout << "    - record the directory data currently in memory to the specified file." << endl;
    color(LightBlue);
    cout << "show";
    color(White);
    cout << "                - show the list of contacts." << endl;
    color(LightBlue);
    cout << "help";
    color(White);
    cout << "                - display help information." << endl;
    color(LightBlue);
    cout << "exit";
    color(White);
    cout << "                - closing the program." << endl << endl;
}

int main()
{
    map <string, string> book;
    help();
    while (true) {
        color(White);
        cout << "Enter your command: ";
        string command;
        getline(cin, command);
        vector<string> words;
        istringstream ist(command);
        string tmp;
        while (ist >> tmp) words.push_back(tmp);
        if (words.size() > 0) {
            if (words[0] == "add") {
                color(LightRed);
                if (words.size() != 3) cout << "[Error] command \"add\" should be: add <name> <number>" << endl;
                else if (words[2].substr(0,1) == "0") cout << "[Error] number cannot start with zero" << endl;
                else if (words[2].size() != 7) cout << "[Error] the length of the number must be seven numerals" << endl;
                else if (!all_of(words[2].begin(), words[2].end(), isdigit)) cout << "[Error] number should contain only digits" << endl;
                else {
                    color(LightGreen);
                    pair<map<string, string>::iterator, bool> ret;
                    ret = book.insert(pair <string, string>(words[1], words[2]));
                    if (ret.second == false) {
                        book.at(words[1]) = words[2];
                        cout << "[Done] number updated" << endl;
                    }
                    else cout << "[Done] number recorded" << endl;
                }
            }
            else if (words[0] == "search") {
                color(LightRed);
                if (words.size() != 2) cout << "[Error] command \"search\" should be: search <name>" << endl;
                else {
                    map<string, string>::iterator it;
                    it = book.find(words[1]);
                    if (it == book.end()) cout << "[Error] no contact with name " + words[1] + " found" << endl;
                    else {
                        color(LightGreen);
                        cout << "[Done] " + words[1] + " " + it->second << endl;
                    }
                }
            }
            else if (words[0] == "delete") {
                color(LightRed);
                if (words.size() != 2 ) cout << "[Error] command \"delete\" should be: delete <name>" << endl;
                else if (!book.erase(words[1])) cout << "[Error] contact with this name does not exist" << endl;
                else {
                    color(LightGreen);
                    cout << "[Done] contact deleted" << endl;
                }
            }
            else if (words[0] == "write") {
                color(LightRed);
                if (words.size() != 2) cout << "[Error] command \"write\" should be: write <filename>" << endl;
                else {
                    ofstream out(words[1] + ".txt");
                    if (!out.is_open()) cout << "[Error] invalid file name" << endl;
                    else {
                        for (auto now : book) out << now.first << " " << now.second << endl;
                        out.close();
                        color(LightGreen);
                        cout << "[Done] data are written to the file " + words[1] + ".txt" << endl;
                    }
                }
            }
            else if (words[0] == "read") {
                color(LightRed);
                if (words.size() != 2) cout << "[Error] command \"read\" should be: read <filename>" << endl;
                else {
                    ifstream in(words[1] + ".txt");
                    if (!in.is_open()) cout << "[Error] invalid file name or file does not exist" << endl;
                    else {
                        string tmp1, tmp2;
                        pair<map<string, string>::iterator, bool> ret;
                        while (in >> tmp1 && in >> tmp2) {
                            ret = book.insert(pair <string, string>(tmp1, tmp2));
                            if (ret.second == false) book.at(tmp1) = tmp2;
                        }
                        color(LightGreen);
                        cout << "[Done] data are read from file " + words[1] + ".txt" << endl;
                    }
                }
            }
            else if (words[0] == "show") {
                color(LightRed);
                if (words.size() > 1) cout << "[Error] command \"show\" requires no arguments" << endl;
                if (book.size() == 0) cout << "[Error] no contacts in memory" << endl;
                else {
                    color(LightGreen);
                    for (auto now : book) cout << now.first << " " << now.second << endl;
                }
            }
            else if (words[0] == "help") {
                color(LightRed);
                if (words.size() > 1) cout << "[Error] command \"help\" requires no arguments" << endl;
                else help();
            }
            else if (words[0] == "exit") {
                color(LightRed);
                if (words.size() > 1) cout << "[Error] command \"exit\" requires no arguments" << endl;
                else {
                    color(White);
                    return 0;
                }
            }
            else {
                color(LightRed);
                cout << "[Error] wrong command" << endl;
            }
        }
        else {
            color(LightRed);
            cout << "[Error] command not entered" << endl;
        }
    }
}