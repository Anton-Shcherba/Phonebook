#include <iostream>
#include <windows.h>
#include <map>
#include <string>

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
    cout << "Enter your command: ";
}



int main()
{
    
    help();

    return 0;
}




 

