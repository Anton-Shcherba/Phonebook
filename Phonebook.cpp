﻿#include <windows.h>
#include "Entry.h"
#include "Command.h"
using namespace std;

enum ConsoleColor {
    Black,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Brown,
    LightGray,
    DarkGray,
    LightBlue,
    LightGreen,
    LightCyan,
    LightRed,
    LightMagenta,
    Yellow,
    White
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

constexpr auto add_string = "add";
constexpr auto search_string = "search";
constexpr auto delete_string = "delete";
constexpr auto write_string = "write";
constexpr auto read_string = "read";
constexpr auto show_string = "show";
constexpr auto help_string = "help";
constexpr auto exit_string = "exit";

int main()
{
    unordered_set <Entry> book;
    help();
    while (true) {
        color(White);
        cout << "Enter your command: ";
        string command, arguments_line;
        cin >> command;
        vector<string> arguments;
        getline(cin, arguments_line);
        istringstream ist(arguments_line);
        while (ist >> arguments_line) arguments.push_back(arguments_line);
        color(DarkGray);
        if (command == add_string) {
            static Add_Command add;
            add.init(arguments);
            cout << add.execute(book) << endl;
        }
        else if (command == search_string) {
            static Search_Command search;
            search.init(arguments);
            cout << search.execute(book) << endl;
        }
        else if (command == delete_string) {
            static Del_Command del;
            del.init(arguments);
            cout << del.execute(book) << endl;
        }
        else if (command == write_string) {
            static Write_Command write;
            write.init(arguments);
            cout << write.execute(book) << endl;
        }
        else if (command == read_string) {
            static Read_Command read;
            read.init(arguments);
            cout << read.execute(book) << endl;
        }
        else if (command == show_string) {
            static Show_Command show;
            show.init(arguments);
            cout << show.execute(book) << endl;
        }
        else if (command == help_string) help();
        else if (command == exit_string) return 0;
        else cout << "[Error] wrong command" << endl;
    }
}