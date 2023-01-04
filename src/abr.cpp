/**
 * @file abr.c
 * @author Thomas Roiseux
 * @brief Implements {abr.h}.
 * @version 0.1
 * @date 2023-01-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../header/abr.h"

ABR::ABR() : word(""), lines(), left(nullptr), right(nullptr)
{
}

ABR::ABR(const std::string& word, unsigned int line) : ABR()
{
    this->word = word;
    lines.push_back(line);
}

ABR::~ABR()
{
    delete left;
    delete right;
}

bool ABR::isPresent(const std::string& word) const
{
    if (this->word == word) return true;
    if (this->word > word && left != nullptr) return left->isPresent(word);
    if (this->word < word && right != nullptr) return right->isPresent(word);
    return false;
}

void ABR::add(const std::string& word, unsigned int line)
{
    if (this->word == word)
    {
        lines.push_back(line);
    }
    else if (this->word > word)
    {
        if (left == nullptr) left = new ABR(word, line);
        else left->add(word, line);
    }
    else
    {
        if (right == nullptr) right = new ABR(word, line);
        else right->add(word, line);
    }
}

const std::vector<unsigned int>& ABR::operator[](const std::string& word) const
{
    if (this->word == word) return lines;
    else if (this->word > word && left != nullptr) return (*left)[word];
    else if (this->word < word && right != nullptr) return (*right)[word];
    else throw std::runtime_error("Word not found.");
}

std::vector<unsigned int> ABR::operator[](const std::vector<std::string>& words) const
{
    std::vector<unsigned int> lines;
    
}

std::vector<unsigned int> ABR::operator[](std::vector<std::string>&& words) const
{
    
}