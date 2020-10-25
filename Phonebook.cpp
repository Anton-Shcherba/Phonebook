#include <windows.h>
#include "Entry.h"
#include "Command.h"
using namespace std;

enum class Color {
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

void Console_color(Color x) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<unsigned>(x));
}

void help() {
    system("cls");
    Console_color(Color::LightBlue);
    cout << "read <filename>";
    Console_color(Color::White);
    cout << "     - read (load) data from a file. The path to the file is specified instead of <filename>." << endl;
    Console_color(Color::LightBlue);
    cout << "add <name> <number>";
    Console_color(Color::White);
    cout << " - add an entry to the phonebook. If an entry with the same name already exists, the new one will                          replace the old one (the number will be overwritten)." << endl;
    Console_color(Color::LightBlue);
    cout << "search <name>";
    Console_color(Color::White);
    cout << "       - search for a record with this name." << endl;
    Console_color(Color::LightBlue);
    cout << "delete <name>";
    Console_color(Color::White);
    cout << "       - delete a record with this name." << endl;
    Console_color(Color::LightBlue);
    cout << "write <filename>";
    Console_color(Color::White);
    cout << "    - record the directory data currently in memory to the specified file." << endl;
    Console_color(Color::LightBlue);
    cout << "show";
    Console_color(Color::White);
    cout << "                - show the list of contacts." << endl;
    Console_color(Color::LightBlue);
    cout << "help";
    Console_color(Color::White);
    cout << "                - display help information." << endl;
    Console_color(Color::LightBlue);
    cout << "exit";
    Console_color(Color::White);
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
        Console_color(Color::White);
        cout << "Enter your command: ";
        string command, arguments_line;
        cin >> command;
        vector<string> arguments;
        getline(cin, arguments_line);
        istringstream ist(arguments_line);
        while (ist >> arguments_line) arguments.push_back(arguments_line);
        Console_color(Color::DarkGray);
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