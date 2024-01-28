#include <iostream>
using std::cout;
#include "myFile.h"

void print_id(const std::string& lab_desc) {
    std::cout << "Amber Fisk\n";
    std::cout << lab_desc << "\n";
    std::cout << "Editor(s) used: Notepad ++\n";
    std::cout << "Compiler(s) used: Microsoft Visual Studio\n";
   std::cout << "File: " << __FILE__ << '\n';
    std::cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}
