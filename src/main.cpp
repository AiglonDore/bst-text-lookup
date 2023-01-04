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

/**
 * @brief Split a string into a vector of words.
 * 
 * @param str String to split.
 * @param vec Vector to fill.
 */
void splitString(const std::string &str, std::vector<std::string> &vec)
{
    std::string word;
    for (const auto &x : str)
    {
        if (x == ' ')
        {
            vec.push_back(word);
            word = "";
        }
        else
        {
            word.push_back(x);
        }
    }
    vec.push_back(word);
}
/**
 * @brief Main function.
 * 
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return int Exit code.
 */
int main(int argc, char *argv[])
{
    std::cout << "\t\t-----Phrase lookup-----" << std::endl;
    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " <file> <phrase>" << std::endl;
        return EXIT_SUCCESS;
    }
    else if (argc == 2)
    {
        std::cerr << "Missing phrase." << std::endl;
        return EXIT_FAILURE;
    }
    else if (argc > 3)
    {
        std::cerr << "Too many arguments." << std::endl;
        return EXIT_FAILURE;
    }

    std::string filename = argv[1];

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Could not open file " << filename << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        std::string line;
        unsigned int nbLine = 1;
        ABR abr;

        while (std::getline(file, line))
        {
            std::vector<std::string> words;
            splitString(line, words);
            for (const auto &word : words)
            {
                abr.add(word, nbLine);
            }
            nbLine++;
        }

        std::vector<std::string> phraseWords;
        splitString(argv[2], phraseWords);

        std::vector<unsigned int> phraseLines = abr[phraseWords];

        if (phraseLines.empty())
        {
            std::cout << "Phrase not found." << std::endl;
        }
        else
        {
            std::cout << "Phrase found in lines: ";
            for (const auto &line : phraseLines)
            {
                std::cout << line << " ";
            }
            std::cout << std::endl;
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}
