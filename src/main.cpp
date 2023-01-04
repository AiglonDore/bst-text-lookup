/**
 * @file main.c
 * @author Thomas Roiseux
 * @brief Main file.
 * @version 0.1
 * @date 2023-01-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <string>

#include "../header/abr.h"

int main(int argc, char *argv[])
{
    std::cout << "\t\t-----Phrase lookup-----" << std::endl;
    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " <file> <phrase>" << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}

