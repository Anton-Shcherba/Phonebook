#include <iostream>
#include <windows.h>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
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
    cout << "    - record the directory data currently in memory to the specified file." << endl << endl;
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
                if (words.size() == 3 && all_of(words[2].begin(), words[2].end(), isdigit)) {
                    if (book.find(words[1]) != book.end()) book.at(words[1]) = words[2];
                    else book.insert(pair <string, string>(words[1], words[2]));
                    color(10);
                    cout << "[Done]" << endl;
                }
                else {
                    color(12);
                    cout << "[Error] wrong arguments" << endl;
                }
            }
            else if (words[0] == "search") {
                if (words.size() == 2 && book.find(words[1]) != book.end()) {
                    color(10);
                    cout << "[Done] " + words[1] + " " + book.find(words[1])->second << endl;
                }
                else {
                    color(12);
                    cout << "[Error] wrong arguments" << endl;
                }
            }
            else if (words[0] == "delete") {
                if (words.size() == 2 && book.find(words[1]) != book.end()) {
                    book.erase(book.find(words[1]));
                    color(10);
                    cout << "[Done]" << endl;
                }
                else {
                    color(12);
                    cout << "[Error] wrong arguments" << endl;
                }
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
    return 0; 
}




 

