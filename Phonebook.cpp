#include <windows.h>
#include "Entry.h"
#include "Command.h"
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
    Add_Command add;
    Search_Command search;
    Del_Command del;
    Write_Command write;
    Read_Command read;
    Show_Command show;
    unordered_set <Entry> book;
    help();
    while (true) {
        color(White);
        cout << "Enter your command: ";
        string command;
        cin >> command;
        color(DarkGray);
        if (command == "add") {
            add.init();
            add.execute(book);
        }
        else if (command == "search") {
            search.init();
            search.execute(book);
        }
        else if (command == "delete") {
            del.init();
            del.execute(book);
        }
        else if (command == "write") {
            write.init();
            write.execute(book);
        }
        else if (command == "read") {
            read.init();
            read.execute(book);
        }
        else if (command == "show") {
            show.init();
            show.execute(book);
        }
        else if (command == "help") help();
        else if (command == "exit") return 0;
    }
}