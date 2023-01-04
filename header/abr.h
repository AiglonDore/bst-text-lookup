/**
 * @file abr.h
 * @author Thomas Roiseux
 * @brief Provides the ABR structure.
 * @version 0.1
 * @date 2023-01-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ABR_H
#define ABR_H

#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

/**
 * @brief ABR structure.
 * 
 */
class ABR
{
private:
    std::string word;
    std::vector<unsigned int> lines;
    ABR *left;
    ABR *right;
public:
    /**
     * @brief Construct a new ABR object.
     * 
     */
    ABR();
    /**
     * @brief Construct a new ABR object
     * 
     * @param word Word to add.
     * @param line Line where the word is.
     */
    explicit ABR(const std::string& word, unsigned int line);
    /**
     * @brief Destroy the ABR object.
     * 
     */
    ~ABR();

    /**
     * @brief Check if a word is present in the ABR.
     * 
     * @param word Word to check.
     * @return true If the word is present.
     * @return false If the word is not present.
     */
    bool isPresent(const std::string& word) const;

    /**
     * @brief Add a word to the ABR.
     * 
     * @param word Word to add.
     * @param line Line where the word is.
     */
    void add(const std::string& word, unsigned int line);

        /**
     * @brief Get the Lines object for a specific word.
     * 
     * @param word Word to get the lines.
     * @return const std::vector<unsigned int>& Lines where the word is.
     */
    const std::vector<unsigned int>& operator[](const std::string& word) const;

    /**
     * @brief Get the Lines object for a specific phrase.
     * 
     * @param words Words of the phrase.
     * @return std::vector<unsigned int> Lines where the phrase is.
     */
    std::vector<unsigned int> operator[](const std::vector<std::string>& words) const;
    /**
     * @brief Get the Lines object for a specific phrase.
     * 
     * @param words Words of the phrase.
     * @return std::vector<unsigned int> Lines where the phrase is.
     */
    std::vector<unsigned int> operator[](std::vector<std::string>&& words) const;
};


#endif /* ABR_H */