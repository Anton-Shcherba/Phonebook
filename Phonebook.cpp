#include <iostream>
#include <windows.h>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
using namespace std;

void color(unsigned x) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, x);
}
void help() {
    system("cls");
    color(9);
    cout << "read <filename>";
    color(15);
    cout << "     - read (load) data from a file. The path to the file is specified instead of <filename>." << endl;
    color(9);
    cout << "add <name> <number>";
    color(15);
    cout << " - add an entry to the phonebook. If an entry with the same name already exists, the new one will                          replace the old one (the number will be overwritten)." << endl;
    color(9);
    cout << "search <name>";
    color(15);
    cout << "       - search for a record with this name." << endl;
    color(9);
    cout << "delete <name>";
    color(15);
    cout << "       - delete a record with this name." << endl;
    color(9);
    cout << "write <filename>";
    color(15);
    cout << "    - record the directory data currently in memory to the specified file." << endl;
    color(9);
    cout << "show";
    color(15);
    cout << "                - show the list of contacts." << endl;
    color(9);
    cout << "help";
    color(15);
    cout << "                - display help information." << endl;
    color(9);
    cout << "exit";
    color(15);
    cout << "                - closing the program." << endl << endl;
}

int main()
{
    map <string, string> book;
    help();
    while (true) {
        color(15);
        cout << "Enter your command: ";
        string command;
        getline(cin, command);
        vector<string> words;
        istringstream ist(command);
        string tmp;
        while (ist >> tmp) words.push_back(tmp);
        if (words.size() > 0) {
            if (words[0] == "add") {
                color(12);
                if (words.size() != 3) cout << "[Error] not enough arguments" << endl;
                else if (words[2].substr(0,1) == "0") cout << "[Error] number cannot start from zero" << endl;
                else if (words[2].size() != 7) cout << "[Error] the length of the number must be seven" << endl;
                else if (!all_of(words[2].begin(), words[2].end(), isdigit)) cout << "[Error] number must be digits" << endl;
                else {
                    color(10);
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
                color(12);
                if (words.size() != 2) cout << "[Error] not enough arguments" << endl;
                else {
                    map<string, string>::iterator it;
                    it = book.find(words[1]);
                    if (it == book.end()) cout << "[Error] no entry with name " + words[1] + " found." << endl;
                    else {
                        color(10);
                        cout << "[Done] " + words[1] + " " + it->second << endl;
                    }
                }
            }
            else if (words[0] == "delete") {
                color(12);
                if (words.size() != 2 ) cout << "[Error] not enough arguments" << endl;
                else if (!book.erase(words[1])) cout << "[Error] contact with this name does not exist" << endl;
                else {
                    color(10);
                    cout << "[Done] contact deleted" << endl;
                }
            }
            else if (words[0] == "write") {
                color(12);
                if (words.size() != 2) cout << "[Error] not enough arguments" << endl;
                else {
                    ofstream out(words[1] + ".txt");
                    if (!out.is_open()) cout << "[Error] invalid file name" << endl;
                    else {
                        for (auto now : book) out << now.first << " " << now.second << endl;
                        out.close();
                        color(10);
                        cout << "[Done] data written to file " + words[1] + ".txt" << endl;
                    }
                }
            }
            else if (words[0] == "read") {
                color(12);
                if (words.size() != 2) cout << "[Error] not enough arguments" << endl;
                ifstream in(words[1] + ".txt");
                if (!in.is_open()) cout << "[Error] invalid file name or file does not exist" << endl;
                else {
                    string tmp1, tmp2;
                    pair<map<string, string>::iterator, bool> ret;
                    while (in >> tmp1 && in >> tmp2) {
                        ret = book.insert(pair <string, string>(tmp1, tmp2));
                        if (ret.second == false) book.at(tmp1) = tmp2;
                    }
                    color(10);
                    cout << "[Done] data is read from file " + words[1] + ".txt" << endl;
                }
            }
            else if (words[0] == "exit") {
                return 0;
            }
            else if (words[0] == "show") {
                color(10);
                for (auto now : book) {
                    cout << now.first << " " << now.second << endl;
                }
                cout << "[Done]" << endl;
            }
            else if (words[0] == "help") {
                help();
            }
            else {
                color(12);
                cout << "[Error] wrong command" << endl;
            }
        }
        else {
            color(12);
            cout << "[Error] wrong command" << endl;
        }
    }
}




 

