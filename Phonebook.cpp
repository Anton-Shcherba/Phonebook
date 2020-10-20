#include <windows.h>
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
        if (command == add_string) {
            add.init();
            add.execute(book);
        }
        else if (command == search_string) {
            search.init();
            search.execute(book);
        }
        else if (command == delete_string) {
            del.init();
            del.execute(book);
        }
        else if (command == write_string) {
            write.init();
            write.execute(book);
        }
        else if (command == read_string) {
            read.init();
            read.execute(book);
        }
        else if (command == show_string) {
            show.init();
            show.execute(book);
        }
        else if (command == help_string) help();
        else if (command == exit_string) return 0;
    }
}