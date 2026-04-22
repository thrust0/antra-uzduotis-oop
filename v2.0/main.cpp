#include "menu.h"

/**
 * @file main.cpp
 * @brief Program entry point.
 *
 * Sets up and runs the interactive menu. Exceptions are caught and reported
 * to stderr to provide friendly error messages without a crash dump.
 */
int main() 
try{
    menu();
    return 0;
}
/** Catch runtime errors (file problems etc) and report gracefully. */
catch(const std::runtime_error& e)
{
    std::cerr << "Vykdymo klaida: " << e.what() << std::endl;
}
catch(const std::exception& e)
{
    std::cerr << "Nenumatyta klaida: " << e.what() << std::endl;
}